#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(string nameStr) : name(nameStr) {}

void HumanB::setWeapon(Weapon &type) {
    weapon = &type;
}

void HumanB::attack() {
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}