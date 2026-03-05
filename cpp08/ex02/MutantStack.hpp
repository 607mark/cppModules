#pragma once

#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
public:
    MutantStack() = default;
    MutantStack(const MutantStack &) = default;
    MutantStack &operator=(const MutantStack &) = default;
    ~MutantStack() = default;
    // typedefs that expose common member types
    typedef Container container_type; // underlying container type
    typedef T value_type;             // type of elements
    typedef T &reference;             // mutable reference to element
    typedef const T &const_reference; // const reference to element

    // expose the underlying container's iterators
    typedef typename container_type::iterator iterator;                             // iterator type
    typedef typename container_type::const_iterator const_iterator;                 // const iterator type
    typedef typename container_type::reverse_iterator reverse_iterator;             // reverse iterator type
    typedef typename container_type::const_reverse_iterator const_reverse_iterator; // const reverse iterator type

    // iterate from bottom (oldest) to top (newest)
    // Note: mutating the stack (push/pop) may invalidate iterators depending on Container
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }

    // reverse iterators iterate from top (newest) to bottom (oldest)
    // Note: same invalidation caveats apply to reverse iterators
    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }
    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }
};
