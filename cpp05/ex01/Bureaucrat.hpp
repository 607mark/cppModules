#pragma once
#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Bureaucrat {
    private:
        const std::string name;
        unsigned int grade;
    public:
        Bureaucrat() = delete;
        Bureaucrat(const std::string& name, unsigned int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        std::string getName(void) const;
        unsigned int getGrade(void) const;
        
        void incrementGrade(void);
        void decrementGrade(void);

        void signForm(Form& form) const;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};
// Insertion operator overload
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);