#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
    std::string arg(av[1]);
    ScalarConverter::convert(arg);
    return 0;
}
