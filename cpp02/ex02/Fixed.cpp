#include "Fixed.hpp"

//default constructor
Fixed::Fixed() {
    //std::cout << "Default construtor has been called." << std::endl;
    _value = 0;
}

//int constructor
Fixed::Fixed(const int value) {
    //std::cout << "Int construtor has been called." << std::endl;

    long long result = static_cast<long long>(static_cast<long long>(value) << _fractional);
    if (result < FIXED_MIN_VALUE || result > FIXED_MAX_VALUE)
        throw (std::overflow_error("Value out of range in int constructor"));

    _value = static_cast<int>(result);
}


// float constructor
Fixed::Fixed(const float value) {
    //std::cout << "Float construtor has been called." << std::endl;

    long long result = static_cast<long long>(roundf(value * SCALE));
    if (result < FIXED_MIN_VALUE || result > FIXED_MAX_VALUE)
        throw (std::overflow_error("Value out of range in float constructor"));
    _value = static_cast<int>(result);
}

//copy constructor
Fixed::Fixed(const Fixed& other){
    //std::cout << "Copy construtor has been called." << std::endl;
    _value = other.getRawBits();
}

//copy assignment operator overload with self-assignment check
Fixed& Fixed::operator=(const Fixed& other) {
    //std::cout << "Copy assignment operator overload has been called." << std::endl;

    if (this != &other)
        _value = other._value;
    return *this;
}

// three-way comparison operator aka spaceship operator with explicit std::strong_ordering
//rhs - right-hand side
std::strong_ordering Fixed::operator<=>(const Fixed& rhs) const noexcept {
    return _value <=> rhs._value;
}

//equality comparison operator
bool Fixed::operator==(const Fixed& rhs) const noexcept {
    return _value == rhs._value;
}

Fixed Fixed::operator+(const Fixed &rhs) const{
    long long result = static_cast<long long>(_value) + rhs._value;
    if (result < FIXED_MIN_VALUE || result > FIXED_MAX_VALUE)
        throw (std::overflow_error("Overflow in addition operator"));
    Fixed res;
    res.setRawBits(static_cast<int>(result));
    return res;
}

Fixed Fixed::operator-(const Fixed &rhs) const{
    long long result = static_cast<long long>(_value) - rhs._value;
    if (result < FIXED_MIN_VALUE || result > FIXED_MAX_VALUE)
        throw (std::overflow_error("Overflow in subtraction operator"));
    Fixed res;
    res.setRawBits(static_cast<int>(result));
    return res;
}

Fixed Fixed::operator*(const Fixed &rhs) const{
    long long result = static_cast<long long>(_value) * rhs._value;
    if (result < FIXED_MIN_VALUE || result > FIXED_MAX_VALUE)
        throw (std::overflow_error("Overflow in multiplication operator"));
    Fixed res;
    res.setRawBits(static_cast<int>(result >> _fractional));
    return res;
}

Fixed Fixed::operator/(const Fixed &rhs) const{
    if (rhs._value == 0)
        throw (std::domain_error("Division by zero"));
    long long result = (static_cast<long long>(_value) << _fractional) / rhs._value;
    if (result < FIXED_MIN_VALUE || result > FIXED_MAX_VALUE)
        throw (std::overflow_error("Overflow in division operator"));
    Fixed res;
    res.setRawBits(static_cast<int>(result));
    return res;
}

Fixed& Fixed::operator++( void ) {
    if (_value == FIXED_MAX_VALUE)
        throw (std::overflow_error("Overflow in preincrement"));
    ++_value;
    return *this;
}

Fixed& Fixed::operator--( void ) {
    if (_value == FIXED_MIN_VALUE)
        throw (std::overflow_error("Overflow in predecrement"));
    --_value;
    return *this;
}

Fixed Fixed::operator++( int ) {
    if (_value == FIXED_MAX_VALUE)
        throw (std::overflow_error("Overflow in postincrement"));
    Fixed temp(*this);
    ++_value;
    return temp;
}

Fixed Fixed::operator--( int ) {
    if (_value == FIXED_MIN_VALUE)
        throw (std::overflow_error("Overflow in postdecrement"));
    Fixed temp(*this);
    --_value;
    return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
    if (a < b)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    if (a > b)
        return a;
    return b;
}
const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    if (a < b)
        return a;
    return b;
}
const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    if (a > b)
        return a;
    return b;
}


//destructor
Fixed::~Fixed( void ) {
    //std::cout << "Destructor has been called." << std::endl;
}

int Fixed::getRawBits( void ) const {
    // std::cout << "getRawBits function has been called." << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    //std::cout << "setRawBits function has been called." << std::endl;
    _value = raw;
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