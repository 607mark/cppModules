#include "Fixed.hpp"

const int Fixed::_fractional = 8;

//default constructor
Fixed::Fixed() {
    value = 0;
    std::cout << "Default construtor has been called." << std::endl;
}

//copy constructor
Fixed::Fixed(const Fixed& old){
    this->value = old.getRawBits();
    std::cout << "Copy construtor has been called." << std::endl;
}

//copy assignment operator overload with self-assignment check
Fixed& Fixed::operator=(const Fixed& old) {
    if (this != &old)
        value = old.value;
    std::cout << "Copy assignment operator overload has been called." << std::endl;
    return *this;
}

//destructor
Fixed::~Fixed( void ) {
    std::cout << "Destructor has been called." << std::endl;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits function has been called." << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits function has been called." << std::endl;
    this->value = raw;
}
