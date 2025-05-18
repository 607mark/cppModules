#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(string nameStr, Weapon &weaponObj) : name(nameStr), weapon (weaponObj) {
}

void HumanA::attack() {
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}