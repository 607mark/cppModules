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

void subject_array_exercise(void ) {
    Animal *array[10];
    for (unsigned int i = 0; i < 5; ++i)
        array[i] = new Dog();
    for (unsigned int i = 5; i < 10; ++i)
        array[i] = new Cat();
    for (Animal* animal : array)
        animal->addBrainIdea("*any idea here*");
    for (Animal* animal : array)
        std::cout << animal->getType() << ": " << animal->getBrainIdea(0) << std::endl;
    for (Animal* animal : array)
        delete animal;
}


int main()
{
    OCCF_tests();
    subject_array_exercise();
    return 0;
}