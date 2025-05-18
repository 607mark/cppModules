#pragma once
#include <string>
#include <iostream>
#include <cstdint>
#include <climits>

class ClapTrap {
    private:
        std::string _name;
        unsigned int         _hitp;
        unsigned int         _energyp;
        unsigned int         _attackd;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        void displayAttributes(void);


};