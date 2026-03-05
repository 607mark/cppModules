#include "ScalarConverter.hpp"
#include <cctype>
#include <charconv>
#include <cmath>
#include <iostream>
#include <limits>
#include <optional>
#include <sstream>
#include <string_view>

// ============================================================================
// LITERAL TYPE DETECTION
// ============================================================================

// Check for IEEE 754 special values (infinity, NaN)
static bool isPseudoLiteral(std::string_view s)
{
    return (s == "nan" || s == "nanf" || s == "+inf" || s == "-inf" || s == "+inff" || s == "-inff");
}

// Check if string represents a single character (non-digit, printable)
static bool isCharLiteral(std::string_view s)
{
    return s.size() == 1 &&
           !std::isdigit(static_cast<unsigned char>(s[0])) &&
           std::isprint(static_cast<unsigned char>(s[0]));
}

// ============================================================================
// PARSING HELPERS - Return std::optional (value or nullopt on failure)
// ============================================================================

static std::optional<char> tryParseChar(const std::string &s)
{
    if (!isCharLiteral(s))
        return std::nullopt;
    return s[0];
}

static std::optional<int> tryParseInt(const std::string &s)
{
    long value = 0;
    auto begin = s.data();
    auto end = begin + s.size();

    // Use C++17 from_chars
    std::from_chars_result res = std::from_chars(begin, end, value);
    if (res.ec == std::errc() && res.ptr == end)
    {
        // Check if value fits in int range
        if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
            return std::nullopt;
        return static_cast<int>(value);
    }
    return std::nullopt;
}

static std::optional<float> tryParseFloat(const std::string &s)
{
    if (s.empty() || s.back() != 'f') // Inline check
        return std::nullopt;

    // Remove trailing 'f' and parse
    std::string num = s.substr(0, s.size() - 1);
    std::istringstream iss(num);
    float v;

    // Ensure entire string was consumed (no trailing garbage)
    if (iss >> v && iss.eof())
        return v;

    return std::nullopt;
}

static std::optional<double> tryParseDouble(const std::string &s)
{
    // Don't parse float literals (ending with 'f')
    if (!s.empty() && s.back() == 'f')
        return std::nullopt;

    std::istringstream iss(s);
    double v;

    if (iss >> v && iss.eof())
        return v;

    return std::nullopt;
}

// ============================================================================
// PRINTING HELPERS - FROM DOUBLE
// ============================================================================

void printCharFromDouble(double v)
{
    // Check if value is finite and fits in char range
    if (!std::isfinite(v) || v < std::numeric_limits<char>::min() || v > std::numeric_limits<unsigned char>::max())
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(v);
    if (!std::isprint(static_cast<unsigned char>(c)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
}

void printIntFromDouble(double v)
{
    if (!std::isfinite(v) || v < std::numeric_limits<int>::min() || v > std::numeric_limits<int>::max())
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    int i = static_cast<int>(v);
    std::cout << "int: " << i << std::endl;
}

void printFloatFromDouble(double v)
{
    float f = static_cast<float>(v);
    if (!std::isfinite(f))
    {
        std::cout << "float: impossible" << std::endl;
        return;
    }

    // Format with fixed-point notation, 1 decimal
    std::cout.setf(std::ios::fixed);
    std::cout.precision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout.unsetf(std::ios::fixed);
}

void printDoubleFromDouble(double v)
{
    if (!std::isfinite(v))
    {
        std::cout << "double: impossible" << std::endl;
        return;
    }

    std::cout.setf(std::ios::fixed);
    std::cout.precision(1);
    std::cout << "double: " << v << std::endl;
    std::cout.unsetf(std::ios::fixed);
}

// ============================================================================
// PRINTING HELPERS - FROM SPECIFIC TYPES
// ============================================================================

static void printFromChar(char c)
{
    if (!std::isprint(static_cast<unsigned char>(c)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout.setf(std::ios::fixed);
    std::cout.precision(1);
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
    std::cout.unsetf(std::ios::fixed);
}

static void printFromInt(int iv)
{
    if (iv < std::numeric_limits<char>::min() || iv > std::numeric_limits<unsigned char>::max())
        std::cout << "char: impossible" << std::endl;
    else
    {
        char c = static_cast<char>(iv);
        if (!std::isprint(static_cast<unsigned char>(c)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << c << "'" << std::endl;
    }
    std::cout << "int: " << iv << std::endl;
    std::cout.setf(std::ios::fixed);
    std::cout.precision(1);
    std::cout << "float: " << static_cast<float>(iv) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(iv) << std::endl;
    std::cout.unsetf(std::ios::fixed);
}

static void printFromFloat(float fv)
{
    printCharFromDouble(static_cast<double>(fv));
    printIntFromDouble(static_cast<double>(fv));
    printFloatFromDouble(static_cast<double>(fv));
    printDoubleFromDouble(static_cast<double>(fv));
}

// Dispatch to type-specific print functions
static void printFromDouble(double dv)
{
    printCharFromDouble(dv);
    printIntFromDouble(dv);
    printFloatFromDouble(dv);
    printDoubleFromDouble(dv);
}

// Handle IEEE 754 special values (infinity, NaN)
static void printPseudo(const std::string &str)
{
    // Float-suffixed versions (nanf, +inff, -inff)
    if (str == "nanf" || str == "+inff" || str == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << str << std::endl;
        if (str == "nanf")
            std::cout << "double: nan" << std::endl;
        else if (str == "+inff")
            std::cout << "double: +inf" << std::endl;
        else // -inff
            std::cout << "double: -inf" << std::endl;
        return;
    }

    // Double versions (nan, +inf, -inf)
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (str == "nan")
        std::cout << "float: nanf" << std::endl;
    else if (str == "+inf")
        std::cout << "float: +inff" << std::endl;
    else // -inf
        std::cout << "float: -inff" << std::endl;
    std::cout << "double: " << str << std::endl;
}

// ============================================================================
// MAIN CONVERSION LOGIC
// ============================================================================

void ScalarConverter::convert(const std::string &literal)
{
    if (literal.empty())
    {
        std::cerr << "Error: empty literal" << std::endl;
        return;
    }

    // Try each parser in order, print first match
    if (auto c = tryParseChar(literal))
        printFromChar(*c);
    else if (isPseudoLiteral(literal))
        printPseudo(literal);
    else if (auto f = tryParseFloat(literal))
        printFromFloat(*f);
    else if (auto i = tryParseInt(literal))
        printFromInt(*i);
    else if (auto d = tryParseDouble(literal))
        printFromDouble(*d);
    else
    {
        // No parser succeeded - invalid input
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}
