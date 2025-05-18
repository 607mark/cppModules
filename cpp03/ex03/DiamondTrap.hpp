#pragma once
#include "FlagTrap.hpp"
#include "ScavTrap.hpp"
/*
           ClapTrap
           /      \
        ScavTrap  FragTrap
           \      /
          DiamondTrap
*/ 

class DiamondTrap : public FlagTrap, public ScavTrap {
    private:
        std::string _name;
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap& operator=(const DiamondTrap& other);
        ~DiamondTrap();

        void attack(const std::string& target);
        void whoAmI();

        void displayAttributes(void);

} ;