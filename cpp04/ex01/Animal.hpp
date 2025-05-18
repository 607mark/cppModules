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
        virtual ~Animal(); // destructor has to be virtual since Animal is abstract class and Animal ptr can hold derived class object(polymorphism) and needs virtual for proper cleanup
        //without virtual in destructor will cause underfined behavior
        std::string getType(void) const;
        virtual void makeSound(void) const;

        virtual void addBrainIdea(std::string idea) = 0;
        virtual std::string getBrainIdea(unsigned int index) const = 0;
} ;