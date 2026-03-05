#pragma once

#include <cstddef>
#include <stdexcept>
#include <utility>

template <typename T>
class Array
{
private:
    T *_data;
    std::size_t _size;

public:
    // Default: empty array
    Array() : _data(nullptr), _size(0) {}

    // Construct with n elements value-initialized
    explicit Array(std::size_t n) : _data(nullptr), _size(n)
    {
        _data = (n ? new T[n]() : nullptr);
    }

    // Copy constructor (deep copy)
    Array(const Array &other) : _data(nullptr), _size(other._size)
    {
        if (_size > 0)
        {
            _data = new T[_size];
            for (std::size_t i = 0; i < _size; ++i)
                _data[i] = other._data[i];
        }
    }

    // Assignment operator (copy-and-swap for strong exception safety)
    Array &operator=(Array other)
    {
        std::swap(_data, other._data);
        std::swap(_size, other._size);
        return *this;
    }

    // Destructor
    ~Array()
    {
        delete[] _data;
    }

    // size() const accessor
    std::size_t size() const { return _size; }

    // Checked subscript operator (non-const)
    T &operator[](std::size_t index)
    {
        if (index >= _size)
            throw std::out_of_range("Array index out of range");
        return _data[index];
    }

    const T &operator[](std::size_t index) const
    {
        if (index >= _size)
            throw std::out_of_range("Array index out of range");
        return _data[index];
    }
};
