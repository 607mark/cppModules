#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include "Contact.hpp"

class PhoneBook{
    private:
        Contact contacts[8];
        int Count;
    public:
        PhoneBook() : Count(0) {}
        int getCount(void);
        void incrementCount(void);
        void shiftContactsDown(void);
        void addContact(std::string firstname, std::string lastname, std::string nickname, std::string phone, std::string secret);
        void displayContact(int index) const;
        void displayContacts() const;
        std::string truncateField(std::string field) const;
        void add();
        void search();
};
#endif