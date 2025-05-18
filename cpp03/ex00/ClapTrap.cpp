#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Noname"), _hitp(10), _energyp(10), _attackd(0){
    std::cout << "Default construtor has been called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitp(10), _energyp(10), _attackd(0){
    std::cout << "Parameterized construtor has been called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitp(other._hitp), _energyp(other._energyp), _attackd(other._attackd){
    std::cout << "Copy construtor has been called." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
    std::cout << "Copy assignment operator overload has been called." << std::endl;

    if (this != &other) {
        _name = other._name;
        _hitp = other._hitp;
        _energyp = other._energyp;
        _attackd = other._attackd;
    }
    return *this;
}

ClapTrap::~ClapTrap ( void ){
    std::cout << "Destructor has been called." << std::endl;
}


void ClapTrap::attack(const std::string& target){
    if (this->_hitp == 0 || this->_energyp == 0) return;
    --_energyp;

    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackd << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitp == 0 || this->_energyp == 0) return;
    if (static_cast<int64_t>(_hitp) - amount < 0) {
        amount = _hitp;
        _hitp = 0; 
    }
    else
        _hitp -= amount;
    
    std::cout << "ClapTrap " << _name << " has taken " << amount << " of damage. HP is " << _hitp << std::endl;
    
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_hitp == 0 || this->_energyp == 0) return;
    --_energyp;
    if (static_cast<uint64_t>(_hitp) + amount > UINT_MAX) {
        amount = UINT_MAX - _hitp;
        _hitp = UINT_MAX;
    }
    else
        _hitp += amount;

    std::cout << "ClapTrap " << _name << " repairs itself by " << amount << ". HP is " << _hitp << std::endl;
}


void ClapTrap::displayAttributes(void) {
    std::cout << "Name: " << _name << std::endl
                << "    _hitp:" << _hitp << std::endl
                << "    _energyp:" << _energyp << std::endl
                << "    _attackd:" << _attackd << std::endl;
}
