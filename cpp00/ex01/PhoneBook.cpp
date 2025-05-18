#include "PhoneBook.hpp"
#include <iomanip>
void PhoneBook::addContact(std::string firstname, std::string lastname, std::string nickname, std::string phone, std::string secret) {
    shiftContactsDown();
    contacts[0].addContact(firstname, lastname, nickname, phone, secret);
}

void PhoneBook::displayContact(int index) const{
    contacts[index].displayFullContact();
}

void PhoneBook::displayContacts() const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < Count; i++) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncateField(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncateField(contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncateField(contacts[i].getNickname()) << std::endl;
    }
}

std::string PhoneBook::truncateField(std::string field) const {
    if (field.length() > 10)
        return (field.substr(0, 9) + ".");  
    return (field);
}


int PhoneBook::getCount(void){
    return (Count);
}
void PhoneBook::incrementCount(void){
    if (Count < 8)
        Count++; 
}

void PhoneBook::shiftContactsDown() {
    for (int j = 6; j >= 0; j--)
        contacts[j + 1] = contacts[j];
}


void PhoneBook::search(){
    std::string line;
    int index = 0;
    std::cout << "=== THE PHONEBOOK ===" << std::endl << std::endl;
    if (getCount() == 0) {
        std::cout << "Nothing to display here yet." << std::endl << std::endl;
        return ;
    }
    displayContacts();
    std::cout << "Input index of the contact to display:" << std::endl;
   
    if (!std::getline(std::cin, line))
        std::exit (1);
    if (line.length() == 1 && isdigit(line[0]))
        index = std::stoi(line);
    else
    {
        std::cout << "The given index is too big or not a digit" << std::endl << std::endl;
        return;
    }    
    if (index < 0 || index + 1 > getCount())
    {
        std::cout << "The index is out of range." << std::endl << std::endl;
        return ;
    }
    displayContact(index);
}

int validate_input(std::string line, int i){
    if (line.length() == 0){
        std::cout << "Input should not be blank" << std::endl;
        return (1);
    }
    if (line.length() > 100){
        std::cout << "Input appears to be too long" << std::endl;
        return (1);
    }
    if (i >= 0 && i <= 1){
        bool hasAlpha = false;
        for (char c : line){
            if (!std::isalpha(c) && c != ' ' && c != '-' && c != '\'')
            {
                std::cout << "Input should only contain letters, spaces, hyphens, and apostrophes" << std::endl;
                return (1);
            }
            if(std::isalpha(c))
                hasAlpha = true;
        }
        if (hasAlpha == false)
        {
            std::cout << "This field has to have at least one letter" << std::endl;
            return (1);
        }
    }
    else if (i == 3){
        if (line.length() > 20){
            std::cout << "Number appears to be too long" << std::endl;
            return (1);
        }
        bool hasDigit = false;
        for (char c : line){
            if(std::isdigit(c))
                hasDigit = true;
            else if (!std::isdigit(c) && c != '+' && c != '-' && c != ' '){
                std::cout << "Phone can only contain numbers, '+', '-' and spaces" << std::endl;
                return (1);
            }
        }
        if (hasDigit == false)
        {
            std::cout << "Number has to have at least one digit" << std::endl;
            return (1);
        }

    }
    return (0);
}

void handle_input(int i, std::string *ptr)
{
    std::string line;
    while(42){
        if (i == 0)
            std::cout << "Input First Name:" << std::endl;
        else if (i == 1)
            std::cout << "Input Last Name:" << std::endl;
        else if (i == 2)
            std::cout << "Input Nickname Name:" << std::endl;
        else if (i == 3)
            std::cout << "Input Phone:" << std::endl;
        else if (i == 4)
            std::cout << "Input Secret:" << std::endl;
        if (!std::getline(std::cin, line))
            std::exit (1);
        if (validate_input(line, i) == 0) {
            *ptr = line;
            return;
        }
    }
   
}

void PhoneBook::add(){

    std::string input[5] = {""};
    for (int i = 0; i < 5; i++)
        handle_input(i, &input[i]);
    addContact(input[0], input[1], input[2], input[3], input[4]);
    incrementCount();
    std::cout << "Contact has been successfully added !" << std::endl;
}