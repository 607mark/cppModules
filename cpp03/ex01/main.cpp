#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
void OCCF_tests(void) {
    std::cout << "          OCCF TESTS" << std::endl;
    {
        ScavTrap tony;
    }
    ScavTrap Joel("Joel");
    ScavTrap notJoel("notJoel");
    notJoel = Joel;
}

void attack_tests(void) {
    ScavTrap john("John");
    for (int i = 100; i > 0; --i)
        john.attack("innocent person");
    john.displayAttributes();
    john.guardGate();
}

int main() {
    OCCF_tests();
    attack_tests();
}