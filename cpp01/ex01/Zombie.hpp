#pragma once
#include <string>

using std::string;

class Zombie {
    private:
        string _name;
    public:
        void announce( void );
        Zombie();
        ~Zombie(void);
        void setZombieName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );