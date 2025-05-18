#include "FlagTrap.hpp"


FlagTrap::FlagTrap() : ClapTrap() {
    std::cout << "FlagTrap : Default construtor has been called." << std::endl;

    _hitp = 100;
    _energyp = 100;
    _attackd = 30;
}

FlagTrap::FlagTrap(std::string name) : ClapTrap(name) {
    std::cout << "FlagTrap : Parameterized construtor has been called." << std::endl;

    _hitp = 100;
    _energyp = 100;
    _attackd = 30;
}

FlagTrap::FlagTrap(const FlagTrap& other) : ClapTrap(other){
    std::cout << "FlagTrap : Copy construtor has been called." << std::endl;

    _name = other._name;
    _hitp = other._hitp;
    _energyp = other._energyp;
    _attackd = other._attackd;
}

FlagTrap& FlagTrap::operator=(const FlagTrap& other) {
    std::cout << "FlagTrap : Copy assignment operator overload has been called." << std::endl;

    if (this != &other) {
        ClapTrap::operator=(other);
        _name = other._name;
        _hitp = other._hitp;
        _energyp = other._energyp;
        _attackd = other._attackd;
    }
    return *this;
}

FlagTrap::~FlagTrap ( void ){
    std::cout << "FlagTrap : Destructor has been called." << std::endl;
}

void FlagTrap::highFivesGuys(void) {
    std::cout << "FlagTrap " << _name << " requests a high five 🙌🙌🙌" << std::endl;
}