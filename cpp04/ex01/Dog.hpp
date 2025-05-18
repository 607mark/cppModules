#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

class Dog : public Animal {
    private:
        Brain* brainPtr;
    public:
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();

        void makeSound(void) const override;
        void addBrainIdea(std::string idea);
        std::string getBrainIdea(unsigned int index) const;
} ;