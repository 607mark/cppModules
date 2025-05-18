#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap() : ClapTrap("Noname_clap_name"), FlagTrap(), ScavTrap(), _name("Noname") {
    std::cout << "DiamondTrap : Default construtor has been called." << std::endl;

    _hitp = FlagTrap::_hitp;
    _energyp = ScavTrap::_energyp;
    _attackd = FlagTrap::_attackd;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FlagTrap(name), ScavTrap(name), _name(name) {
    std::cout << "DiamondTrap : Parameterized construtor has been called." << std::endl;

    _hitp = FlagTrap::_hitp;
    _energyp = ScavTrap::_energyp;
    _attackd = FlagTrap::_attackd;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other.ClapTrap::_name), FlagTrap(other), ScavTrap(other),_name(other._name){
    std::cout << "DiamondTrap : Copy construtor has been called." << std::endl;

    _name = other._name;
    _hitp = other._hitp;
    _energyp = other._energyp;
    _attackd = other._attackd;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << "DiamondTrap : Copy assignment operator overload has been called." << std::endl;

    if (this != &other) {
        ClapTrap::operator=(other);
        FlagTrap::operator=(other);
        ScavTrap::operator=(other);
        _name = other._name;
        _hitp = other._hitp;
        _energyp = other._energyp;
        _attackd = other._attackd;
    }
    return *this;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap ( void ){
    std::cout << "DiamondTrap : Destructor has been called." << std::endl;
}

void DiamondTrap::displayAttributes(void) {
    std::cout << "Name: " << _name << std::endl
                << "    _hitp:" << _hitp << std::endl
                << "    _energyp:" << _energyp << std::endl
                << "    _attackd:" << _attackd << std::endl;
}

void DiamondTrap::whoAmI(void) {
    std::cout << "My name:" << _name << std::endl
                << "My ClapTrap name: " << ClapTrap::_name << std::endl;
}
