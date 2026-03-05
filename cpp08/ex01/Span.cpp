#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span(unsigned int N)
    : _capacity(N), _data()
{
    _data.reserve(N);
}

Span::Span(const Span &other)
    : _capacity(other._capacity), _data(other._data) {}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _capacity = other._capacity;
        _data = other._data;
    }
    return *this;
}

Span::~Span() = default;

void Span::addNumber(int value)
{
    if (_data.size() >= _capacity)
        throw FullSpanException();
    _data.push_back(value);
}

long Span::longestSpan() const
{
    if (_data.size() < 2)
        throw NoSpanException();
    auto mm = std::minmax_element(_data.begin(), _data.end());
    return static_cast<long>(*mm.second) - static_cast<long>(*mm.first);
}

long Span::shortestSpan() const
{
    if (_data.size() < 2)
        throw NoSpanException();
    std::vector<int> tmp(_data);
    std::sort(tmp.begin(), tmp.end());
    long minSpan = std::numeric_limits<long>::max();
    for (size_t i = 1; i < tmp.size(); ++i)
    {
        long span = static_cast<long>(tmp[i]) - static_cast<long>(tmp[i - 1]);
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

const char *Span::FullSpanException::what() const noexcept
{
    return "Span capacity exceeded: cannot add number";
}

const char *Span::NoSpanException::what() const noexcept
{
    return "Insufficient numbers to compute a span";
}
