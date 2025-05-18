#pragma once
#include <string>
using std::string;

class Weapon {
    private:
        string type;
    public:
        Weapon();
        Weapon(string str);
        const string getType() const;
        void setType(string str);
} ;