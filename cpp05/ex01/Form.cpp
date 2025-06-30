#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructor
Form::Form(const std::string& name, unsigned int gradeToSign, unsigned int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150) throw GradeTooLowException();
    
    isSigned = false;
}

// Copy constructor
Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
}

// Assignment operator
Form& Form::operator=(const Form& other) {
    if (this != &other) isSigned = other.isSigned;

    return *this;
}

// Destructor
Form::~Form() {
}

// Getters
std::string Form::getName(void) const {
    return this->name;
}

bool Form::getIsSigned(void) const {
    return this->isSigned;
}

unsigned int Form::getGradeToSign(void) const {
    return this->gradeToSign;
}

unsigned int Form::getGradeToExecute(void) const {
    return this->gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > this->gradeToSign) throw GradeTooLowException();
    
    isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high! (min grade is 1)";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << "Form " << form.getName() << " (signed: " << (form.getIsSigned() ? "yes" : "no") 
        << ", grade to sign: " << form.getGradeToSign() 
        << ", grade to execute: " << form.getGradeToExecute() << ")";

    return out;
}
