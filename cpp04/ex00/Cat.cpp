#include "Cat.hpp"

Cat::Cat() : Animal(){
    std::cout << "Cat : Default construtor has been called." << std::endl;

    type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other){
    std::cout << "Cat : Copy construtor has been called." << std::endl;

    this->type = other.type;
}

Cat& Cat::operator=(const Cat& other){
    std::cout << "Cat : Copy assignment operator overload has been called." << std::endl;

    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Cat::~Cat () {
    std::cout << "Cat : Destructor has been called." << std::endl;
}

void Cat::makeSound(void) const {
    std::cout << "Meow!!!" << std::endl;
}
