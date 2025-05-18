#pragma once
#include <iostream>

class Fixed {
    private:
        int value;
        static const int _fractional;
    public:
        Fixed();
        Fixed(const Fixed& old);
        Fixed& operator=(const Fixed &old);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits(int const raw);
} ;