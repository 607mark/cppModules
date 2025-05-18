#pragma once
#include "Weapon.hpp"

class HumanA {
    private:
        string name;
        Weapon &weapon;
    public:
        HumanA(string nameStr, Weapon &weaponObj);
        void attack();
} ;