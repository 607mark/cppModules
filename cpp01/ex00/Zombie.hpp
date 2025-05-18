#pragma once
#include <string>

using std::string;

class Zombie {
    private:
        string name;
    public:
        void announce( void );
        Zombie(string str);
        ~Zombie(void);
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );