#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : _name("Noname") {
    
    std::cout << _name
    << " has been created" << std::endl;
}

void Zombie::announce(void){
    std::cout << _name
    << ": BraiiiiiiinnnzzzZ..."<< std::endl;;
}

Zombie::~Zombie(void) {
    std::cout << _name
    << " has been destroyed" << std::endl;
}

void Zombie::setZombieName(std::string name)
{
    _name = name;
}