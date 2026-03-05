#pragma once

#include <algorithm>
#include <iterator>
#include <stdexcept>
// return iterator to the found element or throw if not found
template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    auto it = std::find(std::begin(container), std::end(container), value);
    if (it == std::end(container))
        throw std::runtime_error("easyfind: value not present in container");
    return it;
}

template <typename T>
typename T::const_iterator easyfind(const T &container, int value)
{
    auto it = std::find(std::begin(container), std::end(container), value);
    if (it == std::end(container))
        throw std::runtime_error("easyfind: value not present in container");
    return it;
}
