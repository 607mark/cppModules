#include "Dog.hpp"

Dog::Dog() {
     std::cout << "Dog : Default construtor has been called." << std::endl;

    type = "Dog";
    brainPtr = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other){
    std::cout << "Dog : Copy construtor has been called." << std::endl;
    
    this->type = other.type;
    brainPtr = new Brain(*other.brainPtr);
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog : Copy assignment operator overload has been called." << std::endl;

    if (this != &other) {
        Animal::operator=(other);
        *brainPtr = *other.brainPtr;
    }
    return *this;
}

Dog::~Dog () {
    std::cout << "Dog : Destructor has been called." << std::endl;
    delete brainPtr;
}

void Dog::makeSound(void) const {
    std::cout << "Woof!!!!" << std::endl;
}

void Dog::addBrainIdea(std::string idea) {
    brainPtr->addIdea(idea);
}

std::string Dog::getBrainIdea(unsigned int index) const {
    return brainPtr->getIdea(index);
}