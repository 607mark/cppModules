#include "Bureaucrat.hpp"

// Constructor
Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade) : name(name) {
    if (grade < 1) throw GradeTooHighException();
    if (grade > 150) throw GradeTooLowException();

    this->grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {
}

// Assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) this->grade = other.grade;

    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {
}

// Getters
std::string Bureaucrat::getName(void) const {
    return this->name;
}

unsigned int Bureaucrat::getGrade(void) const {
    return this->grade;
}

void Bureaucrat::incrementGrade(void) {
    if (this->grade <= 1) throw GradeTooHighException();

    --this->grade;
}

void Bureaucrat::decrementGrade(void) {
    if (this->grade >= 150) throw GradeTooLowException();

    ++this->grade;
}

void Bureaucrat::signForm(Form& form) const{
    try {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << "." << std::endl;
    } catch (const std::exception& e) {
        std::cout << this->name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high! (min grade is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low! (max grade is 150)";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";

    return out;
}
