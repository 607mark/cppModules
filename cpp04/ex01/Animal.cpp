#include "Animal.hpp"

Animal::Animal() : type("Unknown") {
     std::cout << "Animal : Default construtor has been called." << std::endl;
}

Animal::Animal(std::string strType) : type(strType) {
    std::cout << "Animal : Parameterized construtor has been called." << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type){
    std::cout << "Animal : Copy construtor has been called." << std::endl;
}

Animal& Animal::operator=(const Animal& other){
    std::cout << "Animal : Copy assignment operator overload has been called." << std::endl;
    
    if (this != &other)
        this->type = other.type;
    return *this;
}

Animal::~Animal () {
    std::cout << "Animal : Destructor has been called." << std::endl;

}

std::string Animal::getType(void) const {
    return type;
}

void Animal::makeSound(void) const {
    std::cout << "Bloop-zorp-wibbidy-wop!👽👽👽" << std::endl;
}
