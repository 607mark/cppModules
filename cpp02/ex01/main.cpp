#include "Fixed.hpp"
#include <iostream>
#include <float.h>
int subject_test( void ) {
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    a = Fixed( 1234.4321f );
    
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}

int overflow_float_test(float value) {
    try {
        Fixed f(value);
    } catch (const std::overflow_error& e) {
        std::cerr << "  Caught overflow error: " << e.what() << ". Value: " << value << std::endl;
        return 1;
    }
    std::cout << "  No overflow, value "<< value << " is valid"<< std::endl;
    return 0;
}

int overflow_int_test(int value) {
    try {
        Fixed f(value);
    } catch (const std::overflow_error& e) {
        std::cerr << "  Caught overflow error: " << e.what() << ". Value: " << value << std::endl;
        return 1;
    }
    std::cout << "  No overflow, value "<< value << " is valid"<< std::endl;
    return 0;
}

void int_tests( void ) {
    overflow_int_test(INT_MAX);
    overflow_int_test(INT_MAX >> 8);
    overflow_int_test((INT_MAX >> 8) + 1);
    overflow_int_test(INT_MIN);
    overflow_int_test(INT_MIN >> 8);
    overflow_int_test((INT_MIN >> 8) - 1);
}

void float_tests( void ) {
    overflow_float_test(FLT_MAX);
    overflow_float_test(1234.4321f);
    overflow_float_test(-FLT_MAX);
    overflow_float_test(-1234.4321f);
}
int main( void ) {
    std::cout << "      TEST FROM THE SUBJECT" << std::endl << std::endl;
    subject_test();
    std::cout << "      OVERFLOW INT TESTS" << std::endl << std::endl;
    int_tests();
    std::cout << "      OVERFLOW FLOAT TESTS" << std::endl << std::endl;
    float_tests();
}


// #include <cfloat>
// #include <bitset>
// int main() {
//     // float f = -6.5f;
//     // unsigned int bits = *reinterpret_cast<unsigned int*>(&f);
//     // std::cout << "Value: " << f << "\n";
//     // std::cout << "Bits: " << std::bitset<32>(bits) << "\n";
//     int n = 1 << 8;
//     unsigned int bits = *reinterpret_cast<unsigned int*>(&n);
//     std::cout << "Value: " << n << "\n";
//     std::cout << "Bits: " << std::bitset<32>(bits) << "\n";
//     n = n * (float)3.5;
//     bits = *reinterpret_cast<unsigned int*>(&n);
//     std::cout << "Value: " << n << "\n";
//     std::cout << "Bits: " << std::bitset<32>(bits) << "\n";
//     float d = (float)n / (float)(1 << 8);
//     bits = *reinterpret_cast<unsigned int*>(&d);
//     std::cout << "Value: " << d << "\n";
//     std::cout << "Bits: " << std::bitset<32>(bits) << "\n";
// }