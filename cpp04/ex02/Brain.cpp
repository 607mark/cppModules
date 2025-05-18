#include "Brain.hpp"

Brain::Brain() : ideasCount(0){
    std::cout << "Brain : Default construtor has been called." << std::endl;
}

Brain::Brain(const Brain& other) : ideasCount(other.ideasCount){
    std::cout << "Brain : Copy construtor has been called." << std::endl;
    
    for (unsigned int i = 0; i < ideasSIZE; ++i)
        ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other){
    std::cout << "Brain : Copy assignment operator overload has been called." << std::endl;

    if (this != &other) {
        ideasCount = other.ideasCount;
        for (unsigned int i = 0; i < ideasSIZE; ++i)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain () {
    std::cout << "Brain : Destructor has been called." << std::endl;
}

void Brain::addIdea(std::string idea) {
    if (ideasCount == 100)
        throw (std::out_of_range("Brain is full"));
    ideas[ideasCount] = idea;
    ++ideasCount;
}


std::string Brain::getIdea(unsigned int index) const{
    if (index >= ideasSIZE)
        throw (std::out_of_range("index is out of range of brain"));
    return ideas[index];
}