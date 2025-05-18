#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av) {
    Harl dude;

    if (ac != 2) {
        std::cout <<  "Usage:" << std::endl << "/harlFilter <complaintLevel>" << std::endl;
        return 1;
    }
    dude.complain(std::string(av[1]));
    return 0;
}
