#include "Fixed.hpp"
#include <iostream>

void test_comparison_op( void ){
    Fixed a(10.2f);
    Fixed b(1000.5f);
    std::cout << "a: " << a << ", b: " << b << std::endl;
    std::cout << "a < b : " << (a < b ? "true" : "false") << std::endl;
    std::cout << "a > b : " << (a > b ? "true" : "false") << std::endl;
    std::cout << "a == b : " << (a == b ? "true" : "false") << std::endl;
    a = 3.5f;
    b = 3.5f;
    std::cout << "a: " << a << ", b: " << b << std::endl;
    std::cout << "a <= b : " << (a <= b ? "true" : "false") << std::endl;
    std::cout << "a >= b : " << (a >= b ? "true" : "false") << std::endl;
    std::cout << "a != b : " << (a != b ? "true" : "false") << std::endl;
    std::cout << "a == b : " << (a == b ? "true" : "false") << std::endl;
}

void test_arithmetic_op( void ){
    Fixed a(100.2f);
    Fixed b(23.5f);
    std::cout << "a: " << a << ", b: " << b << std::endl;
    std::cout << "a + b : " << a + b << std::endl;
    std::cout << "a: " << a << ", b: " << b << std::endl;
    std::cout << "a - b : " << a - b << std::endl;
    std::cout << "a * b : " << a * b << std::endl;
    std::cout << "a / b : " << a / b << std::endl;
    a = 5;
    b = -12;
    std::cout << "a: " << a << ", b: " << b << std::endl;
    std::cout << "a + b : " << a + b << std::endl;
    std::cout << "a: " << a << ", b: " << b << std::endl;
    std::cout << "a - b : " << a - b << std::endl;
    std::cout << "a * b : " << a * b << std::endl;
    std::cout << "a / b : " << a / b << std::endl;

    std::cout << "Division by zero test" << std::endl;
    Fixed z(10);
    Fixed k(0);
    try {
        Fixed res (z / k);
    } catch (const std::domain_error& e) {
        std::cerr << "  Caught domain error: " << e.what() << " when 10 / 0"<< std::endl;
        return ;
    }
}

void test_prepostindecrement_op( void ){

    std::cout << "POSTINCREMENT" << std::endl;
    Fixed a(100.2f);
    std::cout << "a: " << a << std::endl;
    std::cout << "a++ " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;
    a = 10;
    std::cout << "a: " << a << std::endl;
    std::cout << "a++ " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;

    std::cout << "POSTDECREMENT" << std::endl;
    a = 100.2f;
    std::cout << "a: " << a << std::endl;
    std::cout << "a-- " << a-- << std::endl;
    std::cout << "a: " << a << std::endl;
    a = 10;
    std::cout << "a: " << a << std::endl;
    std::cout << "a-- " << a-- << std::endl;
    std::cout << "a: " << a << std::endl;

    std::cout << "PREINCREMENT" << std::endl;
    a = 100.2f;
    std::cout << "a: " << a << std::endl;
    std::cout << "++a " << ++a << std::endl;
    std::cout << "a: " << a << std::endl;
    a = 10;
    std::cout << "a: " << a << std::endl;
    std::cout << "++a " << ++a << std::endl;
    std::cout << "a: " << a << std::endl;

    std::cout << "PREDECREMENT" << std::endl;
    a = 100.2f;
    std::cout << "a: " << a << std::endl;
    std::cout << "--a " << --a << std::endl;
    std::cout << "a: " << a << std::endl;
    a = 10;
    std::cout << "a: " << a << std::endl;
    std::cout << "--a " << --a << std::endl;
    std::cout << "a: " << a << std::endl;
}

void test_minmax( void ){
    std::cout << "Fixed::min(1000, 999.84f) " << Fixed::min(1000, 999.84f) << std::endl;
    std::cout << "Fixed::max(1000, 999.84f) " << Fixed::max(1000, 999.84f) << std::endl;
    Fixed a(10), b(10.5f);
    std::cout << "Fixed::min(a(10), b(10.5f)) " << Fixed::min(a, b) << std::endl;
    std::cout << "Fixed::max(a(10), b(10.5f)) " << Fixed::max(a, b) << std::endl;
}

int main( void ) {
    test_comparison_op();
    test_arithmetic_op();
    test_prepostindecrement_op();
    test_minmax();

}