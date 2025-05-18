#include "Fixed.hpp"
#include <iostream>

void test_setter( void ) {
    Fixed c; 
    c.setRawBits(1000);
    std::cout << c.getRawBits() << std::endl;
}

int main( void ) {
Fixed a;
Fixed b(a);
Fixed c;
c = b;
std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;

test_setter();

return 0;
}
