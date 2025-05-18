#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Unknown") {
     std::cout << "WrongAnimal : Default construtor has been called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string strType) : type(strType) {
    std::cout << "WrongAnimal : Parameterized construtor has been called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type){
    std::cout << "WrongAnimal : Copy construtor has been called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
    std::cout << "WrongAnimal : Copy assignment operator overload has been called." << std::endl;
    
    if (this != &other)
        this->type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal () {
    std::cout << "WrongAnimal : Destructor has been called." << std::endl;

}

std::string WrongAnimal::getType(void) const {
    return type;
}

void WrongAnimal::makeSound(void) const {
    std::cout << "Bloop-zorp-wibbidy-wop!👽👽👽" << std::endl;
}
