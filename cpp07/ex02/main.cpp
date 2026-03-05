#include <iostream>
#include <string>
#include <stdexcept>
#include "Array.hpp"

// Helper to display pass/fail
void check(bool cond, const std::string &label)
{
    std::cout << label << ": " << (cond ? "OK" : "FAIL") << '\n';
}

int main()
{
    // Test 1: Default constructed array is empty
    Array<int> a0;
    check(a0.size() == 0, "default size == 0");
    try
    {
        a0[0];
        std::cout << "FAIL: no throw accessing index 0 of empty\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "empty access throws: OK\n";
    }

    // Test 2: Construct with n and verify value-initialization (ints become 0)
    Array<int> a5(5);
    check(a5.size() == 5, "size == 5");
    bool allZero = true;
    for (std::size_t i = 0; i < a5.size(); ++i)
    {
        if (a5[i] != 0)
        {
            allZero = false;
            break;
        }
    }
    check(allZero, "value-init ints == 0");

    // Mutate elements
    for (std::size_t i = 0; i < a5.size(); ++i)
        a5[i] = static_cast<int>(i * 10);
    check(a5[2] == 20, "mutation works");

    // Test 3: Copy constructor deep copy independence
    Array<int> aCopy(a5);
    check(aCopy.size() == a5.size(), "copy size matches");
    check(aCopy[2] == 20, "copy value preserved");
    a5[2] = 999;
    check(aCopy[2] == 20, "copy unaffected after original mutation");

    // Test 4: Assignment operator deep copy independence
    Array<int> assignTarget;
    assignTarget = a5; // a5 currently modified
    check(assignTarget.size() == a5.size(), "assign size matches");
    check(assignTarget[2] == 999, "assigned value matches source");
    assignTarget[2] = 111;
    check(a5[2] == 999, "source unaffected after target mutation");

    // Test 5: Bounds checking (negative not applicable; test >= size)
    try
    {
        a5[a5.size()];
        std::cout << "FAIL: no throw at upper bound\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "upper bound throws: OK\n";
    }
    try
    {
        a5[a5.size() + 10];
        std::cout << "FAIL: no throw far OOB\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "far OOB throws: OK\n";
    }

    // Test 6: Non-trivial type behavior and default construction
    struct Item
    {
        std::string name;
        int qty;
    };
    Array<Item> items(3); // value-init: strings empty, ints zero
    bool itemInitOk = true;
    for (std::size_t i = 0; i < items.size(); ++i)
    {
        if (!items[i].name.empty() || items[i].qty != 0)
        {
            itemInitOk = false;
            break;
        }
    }
    check(itemInitOk, "struct members value-init");
    items[0].name = "koira";
    items[0].qty = 5;
    items[1].name = "kissa";
    items[1].qty = 7;
    Array<Item> itemsCopy(items);
    check(itemsCopy[0].name == "koira" && itemsCopy[1].qty == 7, "struct copy preserves");
    items[0].qty = 500;
    check(itemsCopy[0].qty == 5, "struct copy independence");

    // Test 7: Single element array
    Array<int> single(1);
    check(single.size() == 1 && single[0] == 0, "single element initialized");
    single[0] = 42;
    check(single[0] == 42, "single element mutation");

    // Test 8: Self-assignment safety
    a5 = a5; // should do nothing harmful
    check(a5[2] == 999, "self-assignment no change");

    std::cout << "Tests completed." << std::endl;
    return 0;
}
