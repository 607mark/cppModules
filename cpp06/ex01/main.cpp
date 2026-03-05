#include "Serializer.hpp"
#include "Data.hpp"

#include <iostream>

int main()
{
    Data d;
    d.value = 42;
    d.string = "test";

    Data *original = &d;
    std::uintptr_t raw = Serializer::serialize(original);
    Data *restored = Serializer::deserialize(raw);

    std::cout << "original ptr: " << original << "\n";
    std::cout << "serialized : " << raw << "\n";
    std::cout << "restored ptr: " << restored << "\n";

    if (restored == original)
    {
        std::cout << "Success: restored pointer equals original" << "\n";
        std::cout << "Data: value=" << restored->value << " string='" << restored->string << "'\n";
        return 0;
    }
    std::cout << "Failure: restored pointer differs" << "\n";
    return 1;
}
