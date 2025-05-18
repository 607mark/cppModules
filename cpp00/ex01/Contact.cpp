#include "Contact.hpp"
#include "PhoneBook.hpp"

void Contact::addContact(std::string firstname, std::string lastname, std::string nickname, std::string phone, std::string secret) {
    FirstName = firstname;
    LastName = lastname;
    Nickname = nickname;
    Phone = phone;
    Secret = secret;
}

void Contact::displayFullContact(void) const
{
    std::cout << "First name: "<< FirstName << std::endl
            << "Last name: "<< LastName << std::endl
            << "Nickname: "<< Nickname << std::endl
            << "Phone: " << Phone << std::endl
            << "Secret: " << Secret << std::endl;
}

std::string Contact::getFirstName() const {
    return (FirstName);
}

std::string Contact::getLastName() const {
    return (LastName);
}

std::string Contact::getNickname() const {
    return (Nickname);
}