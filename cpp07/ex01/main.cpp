#include <iostream>
#include <string>
#include <cctype>
#include "iter.hpp"

template <typename T>
void printMe(T &a)
{
    std::cout << a << std::endl;
}

// Toggle case: upper->lower, lower->upper
void toggleCase(std::string &s)
{
    for (char &c : s)
    {
        if (std::isupper(static_cast<unsigned char>(c)))
            c = std::tolower(static_cast<unsigned char>(c));
        else if (std::islower(static_cast<unsigned char>(c)))
            c = std::toupper(static_cast<unsigned char>(c));
    }
}

// Increment each character (e.g. 'a' -> 'b', '1' -> '2')
void incChars(std::string &s)
{
    for (char &c : s)
        ++c;
}

// Replace content with "*classified*"
void redactClassified(std::string &s)
{
    s = "*classified*";
}

// Replace any int with 0
void zeroOut(int &n)
{
    n = 0;
}

int main()
{
    // Focused string-transformation tests for uniqueness
    std::cout << "=== ex01: String transform tests ===\n";

    // Toggle case
    std::string toggleArr[] = {"AbC", "xyz", "123Aa"};
    std::size_t nToggle = sizeof(toggleArr) / sizeof(toggleArr[0]);
    std::cout << "\n-- Toggle Case (before) --" << std::endl;
    iter(toggleArr, nToggle, printMe<std::string>);
    iter(toggleArr, nToggle, toggleCase);
    std::cout << "-- Toggle Case (after) --" << std::endl;
    iter(toggleArr, nToggle, printMe<std::string>);

    // Increment characters
    std::string incArr[] = {"a0z", "9A"};
    std::size_t nInc = sizeof(incArr) / sizeof(incArr[0]);
    std::cout << "\n-- Increment Chars (before) --" << std::endl;
    iter(incArr, nInc, printMe<std::string>);
    iter(incArr, nInc, incChars);
    std::cout << "-- Increment Chars (after) --" << std::endl;
    iter(incArr, nInc, printMe<std::string>);

    // Redact to *classified*
    std::string redArr[] = {"secret", "visible", "topsecret"};
    std::size_t nRed = sizeof(redArr) / sizeof(redArr[0]);
    std::cout << "\n-- Redact (before) --" << std::endl;
    iter(redArr, nRed, printMe<std::string>);
    iter(redArr, nRed, redactClassified);
    std::cout << "-- Redact (after) --" << std::endl;
    iter(redArr, nRed, printMe<std::string>);

    // Int zeroing test
    int nums[] = {7, -3, 42, 1};
    std::size_t nNums = sizeof(nums) / sizeof(nums[0]);
    std::cout << "\n-- Zero Out Ints (before) --" << std::endl;
    iter(nums, nNums, printMe<int>);
    iter(nums, nNums, zeroOut);
    std::cout << "-- Zero Out Ints (after) --" << std::endl;
    iter(nums, nNums, printMe<int>);

    std::cout << std::endl;
    return 0;
}
