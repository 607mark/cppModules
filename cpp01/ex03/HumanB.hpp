#pragma once
#include "Weapon.hpp"

class HumanB {
    private:
        string name;
        Weapon *weapon;
    public:
        HumanB(string nameStr);
        void setWeapon(Weapon &type);
        void attack();
} ;