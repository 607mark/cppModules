#include "Weapon.hpp"
using std::string;

Weapon::Weapon() {    
}

Weapon::Weapon(string str) : type(str) {

}

const string Weapon::getType() const {
    return type;
}
void Weapon::setType(string str) {
    type = str;
}