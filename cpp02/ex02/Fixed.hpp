#pragma once
#include <cmath>
#include <climits>
#include <iostream>
#include <compare>

class Fixed {
    private:
        int _value;
        static const int _fractional = 8;
        
        static const long long FIXED_MAX_VALUE = static_cast<long long>(INT_MAX); // MAX value in long long representation
        static const long long FIXED_MIN_VALUE = static_cast<long long>(INT_MIN); // MIN value in long long representation
        static const long long SCALE = 1LL << _fractional; // 1LL is 1 in long long representation
    public:
        Fixed();
        Fixed(const Fixed& old);
        Fixed(const int value);
        Fixed(const float value);

        Fixed& operator=(const Fixed &old);

        std::strong_ordering operator<=>(const Fixed& rhs) const noexcept;
        bool operator==(const Fixed& rhs) const noexcept;

        Fixed operator+(const Fixed &rhs) const;
        Fixed operator-(const Fixed &rhs) const;
        Fixed operator*(const Fixed &rhs) const;
        Fixed operator/(const Fixed &rhs) const;

        Fixed& operator++( void ); //preincrement
        Fixed& operator--( void );
        Fixed operator++(int); //postincrement
        Fixed operator--(int);

        static Fixed& min(Fixed &a, Fixed &b);
        static Fixed& max(Fixed &a, Fixed &b);
        static const Fixed& min(const Fixed &a, const Fixed &b);
        static const Fixed& max(const Fixed &a, const Fixed &b);

        ~Fixed();

        float toFloat( void ) const;
        int toInt( void ) const;

        int getRawBits( void ) const;
        void setRawBits(int const raw);
} ;

std::ostream& operator<<(std::ostream& os, const Fixed& obj);