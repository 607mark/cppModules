#include "FlagTrap.hpp"
void OCCF_tests(void) {
    std::cout << "          OCCF TESTS" << std::endl;
    {
        FlagTrap tony;
        tony.displayAttributes();
    }
    FlagTrap Joel("Joel");
    FlagTrap notJoel("notJoel");
    notJoel = Joel;
}

void attack_tests(void) {
    FlagTrap john("John");
    for (int i = 100; i > 0; --i)
        john.attack("innocent person");
    john.displayAttributes();
    john.highFivesGuys();
}

int main() {
    OCCF_tests();
    attack_tests();
}