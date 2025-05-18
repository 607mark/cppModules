#include "Dog.hpp"

Dog::Dog() {
     std::cout << "Dog : Default construtor has been called." << std::endl;

    type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other){
    std::cout << "Dog : Copy construtor has been called." << std::endl;
    
    this->type = other.type;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog : Copy assignment operator overload has been called." << std::endl;

    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Dog::~Dog () {
    std::cout << "Dog : Destructor has been called." << std::endl;
}

void Dog::makeSound(void) const {
    std::cout << "Woof!!!!" << std::endl;
}
