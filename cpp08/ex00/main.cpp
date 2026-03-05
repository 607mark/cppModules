#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

static void test_vector()
{
    std::vector<int> v{1, 2, 3, 4, 5};
    try
    {
        auto it = easyfind(v, 3);
        std::cout << "Found in vector: " << *it << '\n';
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
    try
    {
        easyfind(v, 42);
    }
    catch (const std::exception &e)
    {
        std::cout << "Not found in vector (as expected): " << e.what() << '\n';
    }
}

static void test_list()
{
    std::list<int> l{10, 20, 30};
    try
    {
        auto it = easyfind(l, 20);
        std::cout << "Found in list: " << *it << '\n';
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
}

static void test_deque()
{
    std::deque<int> d{7, 8, 9};
    try
    {
        auto it = easyfind(d, 9);
        std::cout << "Found in deque: " << *it << '\n';
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
}

int main()
{
    std::cout << "=== easyfind tests ===" << std::endl;
    test_vector();
    test_list();
    test_deque();
    std::cout << "All tests completed." << std::endl;
    return 0;
}
