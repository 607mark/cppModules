#pragma once
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat; // Forward declaration

class Form {
    private:
        const std::string name;
        bool isSigned;
        const unsigned int gradeToSign;
        const unsigned int gradeToExecute;
    
    public:
        Form() = delete;
        Form(const std::string& name, unsigned int gradeToSign, unsigned int gradeToExecute);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();    

        std::string getName(void) const;
        bool getIsSigned(void) const;
        unsigned int getGradeToSign(void) const;
        unsigned int getGradeToExecute(void) const;
        
        void beSigned(const Bureaucrat& bureaucrat);


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
std::ostream& operator<<(std::ostream& out, const Form& Form);