#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(){
    PhoneBook phonebook;
    std::string line;

    std::cout << "Welcome to PhoneBook!" << std::endl
    << "I accept ADD, SEARCH and EXIT" << std::endl;
    while(42)
    {
        std::cout << "Input you command:" << std::endl;
        if (!std::getline(std::cin, line))
            std::exit (1);
        if (line == "EXIT")
            break;
        else if (line == "SEARCH")
            phonebook.search();
        else if (line == "ADD")
            phonebook.add();
        else
        {
            std::cout << "Your command doesn't match any of commands. " << std::endl 
            << "I accept ADD, SEARCH and EXIT" << std::endl;
            continue;
        }
          
    }
    return (0);
}