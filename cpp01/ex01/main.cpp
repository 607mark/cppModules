#include "Zombie.hpp"

void testzombiehorde(int N)
{
    Zombie *Mark = zombieHorde(N, "Mark");
    if (Mark)
    {
        for (int i = 0; i < N; i++)
            (Mark + i)->announce();
        delete[] Mark;
    }
}

int main() {
    testzombiehorde(10);
    testzombiehorde(-1);
    //testzombiehorde(100000000);
}