#pragma once
#include <string>
#include <iostream>
#include <stdexcept>

class Brain {
    private:
        static constexpr unsigned int ideasSIZE = 100;
        std::string ideas[ideasSIZE];
        unsigned int ideasCount;
    public:
        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        ~Brain();

        void addIdea(std::string idea);
        std::string getIdea(unsigned int index) const;
} ;

