// Span.hpp - declaration and template implementations
#pragma once

#include <vector>
#include <cstddef>
#include <exception>
#include <iterator>

class Span
{
private:
    unsigned int _capacity;
    std::vector<int> _data;

public:
    explicit Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int value);

    template <typename InputIt>
    void addNumber(InputIt first, InputIt last)
    {
        auto dist = std::distance(first, last);
        if (dist <= 0)
            return;
        if (static_cast<unsigned long>(dist) > static_cast<unsigned long>(_capacity - _data.size()))
            throw FullSpanException();
        _data.insert(_data.end(), first, last);
    }

    long longestSpan() const;
    long shortestSpan() const;

    // exception types
    class FullSpanException : public std::exception
    {
    public:
        const char *what() const noexcept override;
    };

    class NoSpanException : public std::exception
    {
    public:
        const char *what() const noexcept override;
    };
};
