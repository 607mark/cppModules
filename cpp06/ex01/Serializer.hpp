#pragma once
#include <cstdint>

struct Data;

class Serializer
{
public:
    Serializer() = delete;
    Serializer(const Serializer &) = delete;
    Serializer &operator=(const Serializer &) = delete;
    ~Serializer() = delete;

    static std::uintptr_t serialize(Data *ptr);
    static Data *deserialize(std::uintptr_t raw);
};
