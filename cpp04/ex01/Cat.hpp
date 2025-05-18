#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

class Cat : public Animal {
    private:
        Brain* brainPtr;
    public:
        Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        ~Cat();

        void makeSound(void) const override ;
        void addBrainIdea(std::string idea);
        std::string getBrainIdea(unsigned int index) const;     
} ;