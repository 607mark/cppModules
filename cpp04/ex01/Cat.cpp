#include "Cat.hpp"

Cat::Cat() : Animal(){
    std::cout << "Cat : Default construtor has been called." << std::endl;

    type = "Cat";
    brainPtr = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other){
    std::cout << "Cat : Copy construtor has been called." << std::endl;

    brainPtr = new Brain(*other.brainPtr);
    this->type = other.type;
}

Cat& Cat::operator=(const Cat& other){
    std::cout << "Cat : Copy assignment operator overload has been called." << std::endl;

    if (this != &other) {
        Animal::operator=(other);
        *brainPtr = *other.brainPtr;
    }
    return *this;
}

Cat::~Cat () {
    std::cout << "Cat : Destructor has been called." << std::endl;
    delete brainPtr;
}

void Cat::makeSound(void) const {
    std::cout << "Meow!!!" << std::endl;
}

void Cat::addBrainIdea(std::string idea) {
    brainPtr->addIdea(idea);
}

std::string Cat::getBrainIdea(unsigned int index) const {
    return brainPtr->getIdea(index);
}

