#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data;

    data.id = 42;
    data.name = "El Hassane";
    data.score = 1337.42;

    std::cout << "===== Original Object =====" << std::endl;
    std::cout << "Address : " << &data << std::endl;
    std::cout << "id      : " << data.id << std::endl;
    std::cout << "name    : " << data.name << std::endl;
    std::cout << "score   : " << data.score << std::endl;

    uintptr_t raw = Serializer::serialize(&data);

    std::cout << std::endl;
    std::cout << "Serialized value : " << raw << std::endl;

    Data *ptr = Serializer::deserialize(raw);

    std::cout << std::endl;
    std::cout << "===== Deserialized Object =====" << std::endl;
    std::cout << "Address : " << ptr << std::endl;
    std::cout << "id      : " << ptr->id << std::endl;
    std::cout << "name    : " << ptr->name << std::endl;
    std::cout << "score   : " << ptr->score << std::endl;

    std::cout << std::endl;

    if (ptr == &data)
        std::cout << "SUCCESS: pointers are identical." << std::endl;
    else
        std::cout << "ERROR: pointers are different." << std::endl;

    return (0);
}