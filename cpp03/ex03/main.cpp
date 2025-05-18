#include "DiamondTrap.hpp"

void OCCF_tests(void) {
    std::cout << "          OCCF TESTS" << std::endl;
    {
        DiamondTrap Gary("Gary");
    }

    {
        DiamondTrap Gary("Gary");
        DiamondTrap Sary("Sary");
        Gary = Sary;
        Gary.displayAttributes();
    }
    
    {
        DiamondTrap Gary("Gary");
        DiamondTrap Sary(Gary);
    }
}

void diamond_tests (void) {
    {
        DiamondTrap Gary("Gary");
        Gary.whoAmI();
    }

    {
        DiamondTrap Gary("Gary");
        DiamondTrap copyGary(Gary);
        Gary.whoAmI();
    }

    {
        DiamondTrap Gary("Gary");
        DiamondTrap notGary("notGary");
        notGary.whoAmI();
        notGary = Gary;
        notGary.whoAmI();
        notGary.displayAttributes();
        notGary.attack("Someone");
        notGary.attack("Someone");
        notGary.displayAttributes();
    }
}

void funny_tests() {
    DiamondTrap Gary("Gary");
    Gary.ScavTrap::guardGate();
    Gary.highFivesGuys();
    Gary.FlagTrap::highFivesGuys();

    Gary.ScavTrap::attack("Dude"); // attack as Scavtrap
    Gary.FlagTrap::attack("Alien"); // attack ass FlagTrap, which inherits attack() from ClapTrap
    Gary.attack("Man"); // overridden member function of DiamondTrap that delegates attack() to Scavtrap::attack()
}

int main() {
    OCCF_tests();
    diamond_tests();
    funny_tests();
}