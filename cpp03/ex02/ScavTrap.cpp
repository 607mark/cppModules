#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap : Default construtor has been called." << std::endl;

    _hitp = 100;
    _energyp = 50;
    _attackd = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap : Parameterized construtor has been called." << std::endl;

    _hitp = 100;
    _energyp = 50;
    _attackd = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other){
    std::cout << "ScavTrap : Copy construtor has been called." << std::endl;

    _name = other._name;
    _hitp = other._hitp;
    _energyp = other._energyp;
    _attackd = other._attackd;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap : Copy assignment operator overload has been called." << std::endl;

    if (this != &other) {
        ClapTrap::operator=(other);
        _name = other._name;
        _hitp = other._hitp;
        _energyp = other._energyp;
        _attackd = other._attackd;
    }
    return *this;
}

ScavTrap::~ScavTrap ( void ){
    std::cout << "ScavTrap : Destructor has been called." << std::endl;
}

void ScavTrap::attack(const std::string& target){
    if (this->_hitp == 0 || this->_energyp == 0) return;
    --_energyp;

    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackd << " points of damage!" << std::endl;
}

void ScavTrap::guardGate (void) {
    std::cout << "ScavTrap " << _name << " is now in Gatekeeper mode" << std::endl;
}