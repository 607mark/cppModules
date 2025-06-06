#pragma once
#include <string>
#include <iostream>

class Animal {
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string);
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual ~Animal();
        std::string getType(void) const;
        virtual void makeSound(void) const = 0;

        virtual void addBrainIdea(std::string idea) = 0;
        virtual std::string getBrainIdea(unsigned int index) const = 0;
} ;