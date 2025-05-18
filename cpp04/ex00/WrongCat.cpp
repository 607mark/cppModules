#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
    std::cout << "WrongCat : Default construtor has been called." << std::endl;

    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other){
    std::cout << "WrongCat : Copy construtor has been called." << std::endl;

    this->type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other){
    std::cout << "WrongCat : Copy assignment operator overload has been called." << std::endl;

    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

WrongCat::~WrongCat () {
    std::cout << "WrongCat : Destructor has been called." << std::endl;
}

void WrongCat::makeSound(void) const {
    std::cout << "Meow!!!" << std::endl;
}
