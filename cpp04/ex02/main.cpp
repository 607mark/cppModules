#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void OCCF_tests(void) {
    std::cout << "          OCCF TESTS" << std::endl;
    {
        Dog Daisy;
        Cat Tom;
    }

    {
        Dog *Lucy  = new Dog;
        Lucy->addBrainIdea("Pet me someone");
        Dog Daisy;
        Daisy = *Lucy;
        delete Lucy;
        std::cout << "          " << Daisy.getBrainIdea(0) << " " << std::endl;
    }
    {
        Cat *Lucy  = new Cat;
        Lucy->addBrainIdea("I wish I were a bird");
        Cat Daisy;
        Daisy = *Lucy;
        delete Lucy;
        std::cout << "          " << Daisy.getBrainIdea(0) << " " << std::endl;
    }
    {
        Cat *Lucy  = new Cat;
        Lucy->addBrainIdea("Dry cat food doesn't taste too good");
        Cat Daisy(*Lucy);
        delete Lucy;
        std::cout << "          " << Daisy.getBrainIdea(0) << " " << std::endl;
    }
    {
        Dog *Lucy  = new Dog;
        Lucy->addBrainIdea("Dry dog food tastes sooooo good");
        Dog Daisy(*Lucy);
        delete Lucy;
        std::cout << "          " << Daisy.getBrainIdea(0) << " " << std::endl;
    }
}

int main()
{
    // Animal a; // non-instantiable!!! won't compile
    OCCF_tests();
    
    return 0;
}