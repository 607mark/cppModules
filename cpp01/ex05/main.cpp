#include "Harl.hpp"
#include <iostream>

int main() {
    Harl dude;

    std::cout <<  "Testing with DEBUG:" << std::endl;
    dude.complain("DEBUG");
    std::cout <<  "Testing with INFO:" << std::endl;
    dude.complain("INFO");
    std::cout <<  "Testing with WARNING:" << std::endl;
    dude.complain("WARNING");
    std::cout <<  "Testing with ERROR:" << std::endl;
    dude.complain("ERROR");
    std::cout <<  "Testing with WUZUP:" << std::endl;
    dude.complain("WUZUP");
}
