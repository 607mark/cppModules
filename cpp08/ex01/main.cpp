#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "Span.hpp"

int main()
{
    std::cout << "=== Span example ===" << std::endl;

    // Example from the subject
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    // Test add range and large dataset
    {
        const unsigned int N = 10000;
        Span big(N);
        std::vector<int> nums(N);
        // fill with 0..N-1
        std::iota(nums.begin(), nums.end(), 0);
        // shuffle
        std::mt19937_64 rng(42);
        std::shuffle(nums.begin(), nums.end(), rng);
        // add via range
        try
        {
            big.addNumber(nums.begin(), nums.end());
            std::cout << "big shortest: " << big.shortestSpan() << "\n";
            std::cout << "big longest: " << big.longestSpan() << "\n";
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error adding range: " << e.what() << std::endl;
        }
    }

    // Test exceptions
    {
        Span s(1);
        s.addNumber(5);
        try
        {
            s.addNumber(6);
        }
        catch (const std::exception &e)
        {
            std::cout << "Expected full: " << e.what() << '\n';
        }
        try
        {
            Span empty(3);
            empty.shortestSpan();
        }
        catch (const std::exception &e)
        {
            std::cout << "Expected no span: " << e.what() << '\n';
        }
    }

    std::cout << "All tests finished." << std::endl;
    return 0;
}
