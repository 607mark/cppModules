#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact {
    private:
        std::string FirstName;
        std::string LastName;
        std::string Nickname;
        std::string Phone;
        std::string Secret;
    public:
        void addContact(std::string firstname, std::string lastname, std::string nickname, std::string phone, std::string secret);
        void displayFullContact(void) const;
        std::string getFirstName() const ;
        std::string getLastName() const ;
        std::string getNickname() const ;
} ;
#endif
