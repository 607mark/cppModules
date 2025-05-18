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
        Dog Daisy;
        Dog Lucy;
        Daisy = Lucy; // doesn't do much since they don't have any attributes other than type
        std::cout << Daisy.getType() << " " << std::endl;
        Daisy.makeSound();
    }
    {
        Cat Tom;
        Cat John;
        Tom = John; // doesn't do much since they don't have any attributes other than type
        std::cout << Tom.getType() << " " << std::endl;
        Tom.makeSound();
    }
    {
        Cat Daicy;
        Cat Lucy(Daicy);
    }
}

void subject_test(void) {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;
}

void Wrong_tests(void) {
    const WrongAnimal* meta = new WrongAnimal();
    std::cout << "used as WrongAnimal, type " << meta->getType() << " " << std::endl;
    meta->makeSound();
    delete meta;

    const WrongAnimal* i = new WrongCat();
    std::cout << "used as WrongAnimal, type " << i->getType() << " " << std::endl;
    i->makeSound(); //will not output the cat sound!
    delete i;

    WrongCat kitty;
    std::cout << "used as WrongCat, type " << kitty.getType() << " " << std::endl;
    kitty.makeSound();
}

int main()
{
    subject_test();
    OCCF_tests();
    Wrong_tests();
    return 0;
}