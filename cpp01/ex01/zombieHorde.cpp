#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {

    if (N < 1)
        return (nullptr);
    Zombie *ptr = new (std::nothrow) Zombie[N];

    if (!ptr)
        return nullptr;
    for (int i = 0; i < N; i++)
        (ptr+i)->setZombieName(name);
    return (ptr);
}