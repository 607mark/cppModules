#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <random>
#include <iostream>

Base *generate(void)
{
    static std::random_device rd;                      // Hardware random seed
    static std::mt19937 gen(rd());                     // Mersenne Twister engine (initialized once)
    static std::uniform_int_distribution<> dist(0, 2); // Uniform distribution [0, 2]
    int randNum = dist(gen);                           // Generate random number
    switch (randNum)
    {
    case 0:
        return new A();
    case 1:
        return new B();
    case 2:
        return new C();
    default:
        return nullptr;
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void)a; // Avoid unused variable warning
        std::cout << "A" << std::endl;
        return;
    }
    catch (const std::bad_cast &)
    {
    }

    try
    {
        B &b = dynamic_cast<B &>(p);
        (void)b; // Avoid unused variable warning
        std::cout << "B" << std::endl;
        return;
    }
    catch (const std::bad_cast &)
    {
    }

    try
    {
        C &c = dynamic_cast<C &>(p);
        (void)c; // Avoid unused variable warning
        std::cout << "C" << std::endl;
        return;
    }
    catch (const std::bad_cast &)
    {
    }

    std::cout << "Unknown type" << std::endl;
}

int main()
{
    Base *obj = generate();

    identify(obj);
    if (obj)
        identify(*obj);
    delete obj;
    return 0;
}