#pragma once
#include <string>
#include <iostream>

class WrongAnimal {
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(std::string);
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal& operator=(const WrongAnimal& other);
        virtual ~WrongAnimal(); // destructor has to be virtual since WrongAnimal is abstract class and WrongAnimal ptr can hold derived class object(polymorphism) and needs virtual for proper cleanup

        std::string getType(void) const;
        void makeSound(void) const;
} ;