#include "ClapTrap.hpp"

void OCCF_tests(void) {
    std::cout << "          OCCF TESTS" << std::endl;

    ClapTrap george("George");
    george.displayAttributes();

    ClapTrap noname;
    noname.displayAttributes();
    noname = george;
    noname.displayAttributes();
    ClapTrap copyGeorge(george);
}

void repair_tests (void) {
    std::cout << "          REPAIR TESTS" << std::endl;

    ClapTrap george("George");
    george.beRepaired(UINT_MAX);
    george.displayAttributes();
    george.beRepaired(UINT_MAX);
    george.displayAttributes();

}

void damage_tests (void) {
    std::cout << "          DAMAGE TESTS" << std::endl;
    ClapTrap george("George");
    george.takeDamage(UINT_MAX);
    george.displayAttributes();
    george.takeDamage(UINT_MAX);
    george.displayAttributes();

}

void energy_tests (void) {
    std::cout << "          ENERGY/ATTACK TESTS" << std::endl;
    ClapTrap george("George");
    for (int i = 9; i > 0; --i)
        george.attack("Tom");
    george.displayAttributes();
    george.attack("Tom");
    george.displayAttributes();
    george.takeDamage(UINT_MAX);
    george.beRepaired(UINT_MAX);
    george.displayAttributes();
}

int main() {
    OCCF_tests();
    repair_tests();
    damage_tests();
    energy_tests();

}