#include "Fixed.hpp"

//default constructor
Fixed::Fixed() {
    std::cout << "Default construtor has been called." << std::endl;
    
    _value = 0;
}

//int constructor
Fixed::Fixed(const int value) {
    std::cout << "Int construtor has been called." << std::endl;

    long long result = static_cast<long long>(value) << _fractional;
    if (result < FIXED_MIN_VALUE || result > FIXED_MAX_VALUE)
        throw (std::overflow_error("Value out of range in int constructor"));

    _value = static_cast<int>(result);
}


// float constructor
Fixed::Fixed(const float value) {
    std::cout << "Float construtor has been called." << std::endl;

    long long result = static_cast<long long>(roundf(value * SCALE));
    if (result < FIXED_MIN_VALUE || result > FIXED_MAX_VALUE)
        throw (std::overflow_error("Value out of range in float constructor"));
    
    _value = static_cast<int>(result);
}

//copy constructor
Fixed::Fixed(const Fixed& other){
    std::cout << "Copy construtor has been called." << std::endl;

    _value = other.getRawBits();

}

//copy assignment operator overload with self-assignment check
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator overload has been called." << std::endl;

    if (this != &other)
        _value = other._value;
    return *this;
}

//destructor
Fixed::~Fixed( void ) {
    std::cout << "Destructor has been called." << std::endl;
}

int Fixed::getRawBits( void ) const {
    // std::cout << "getRawBits function has been called." << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    //std::cout << "setRawBits function has been called." << std::endl;
    this->_value = raw;
}

//stream insertion operator
std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();
    return os;
}

float Fixed::toFloat( void ) const {
    return static_cast<float>(_value) / static_cast<float>(SCALE);
}

int Fixed::toInt( void ) const {
    return _value >> _fractional;
}