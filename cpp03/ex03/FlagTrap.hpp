#pragma once
#include "ClapTrap.hpp"

class FlagTrap : virtual public ClapTrap {
    public:
        FlagTrap();
        FlagTrap(std::string name);
        FlagTrap(const FlagTrap& other);
        FlagTrap& operator=(const FlagTrap& other);
        ~FlagTrap();

        void highFivesGuys(void);
} ;