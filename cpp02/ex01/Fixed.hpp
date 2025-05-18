#pragma once
#include <cmath>
#include <climits>
#include <iostream>

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
        ~Fixed();

        float toFloat( void ) const;
        int toInt( void ) const;

        int getRawBits( void ) const;
        void setRawBits(int const raw);
} ;

std::ostream& operator<<(std::ostream& os, const Fixed& obj);