#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(string str){
    name = str;
}

void Zombie::announce(void){
    std::cout << name
    << ": BraiiiiiiinnnzzzZ..."<< std::endl;;
}

Zombie::~Zombie(void) {
    std::cout << name
    << " has been destroyed" << std::endl;
}