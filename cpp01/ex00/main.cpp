#include "Zombie.hpp"

int main() {
    Zombie *Mark = newZombie("Mark");
    Mark->announce();
    randomChump("Wark");
    delete Mark;
}