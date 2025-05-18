#pragma once
#include "Animal.hpp"
#include <string>
#include <iostream>

class Dog : public Animal {
    public:
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();

        void makeSound(void) const override;
        
} ;