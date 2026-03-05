#include <iostream>
#include <stack>
#include <list>
#include "MutantStack.hpp"

static void subject_test()
{
    std::cout << "=== Subject test (MutantStack) ===" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "MutantStack contents (bottom -> top):" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);
}

static void subject_test_with_list()
{
    std::cout << "=== Subject test (std::list replicate) ===" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    lst.pop_back(); // mimic stack pop()
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << "std::list contents (bottom -> top):" << std::endl;
    for (int v : lst)
        std::cout << v << std::endl;
}

static void extra_tests()
{
    std::cout << "=== Extra MutantStack tests ===" << std::endl;

    // Test copy construction
    MutantStack<int> a;
    for (int i = 1; i <= 5; ++i)
        a.push(i);
    MutantStack<int> b(a);
    std::cout << "Copied stack contents:" << std::endl;
    for (auto it = b.begin(); it != b.end(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;

    // Test const iteration
    const MutantStack<int> c = a;
    std::cout << "Const iteration:" << std::endl;
    for (MutantStack<int>::const_iterator it = c.begin(); it != c.end(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;

    // Test reverse iteration
    std::cout << "Reverse iteration (top -> bottom):" << std::endl;
    for (auto rit = a.rbegin(); rit != a.rend(); ++rit)
        std::cout << *rit << ' ';
    std::cout << std::endl;
}

int main()
{
    subject_test();
    subject_test_with_list();
    extra_tests();
    return 0;
}
