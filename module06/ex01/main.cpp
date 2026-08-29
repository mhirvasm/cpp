#include <iostream>
#include "Serializer.hpp"

int main() {
    
    Data myData;
    myData.id = 42;
    myData.name = "HiveHelsinki";

    std::cout << "--- NORMAL CASE ---\n";
    std::cout << "Original address: " << &myData << "\n";

    // serialize
    uintptr_t serialized = Serializer::serialize(&myData);
    std::cout << "Serialized value: " << serialized << "\n";

    // deserialize
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized address: " << deserialized << "\n";

    // verify
    if (deserialized == &myData) {
        std::cout << "Success: Pointers match.\n";
        std::cout << "Data ID: " << deserialized->id << " | Name: " << deserialized->name << "\n";
    }

    std::cout << "\n--- EDGE CASE: NULLPTR ---\n";
    // Edge case test with nullptr
    Data* nullData = nullptr;
    uintptr_t serializedNull = Serializer::serialize(nullData);
    Data* deserializedNull = Serializer::deserialize(serializedNull);
    
    std::cout << "Serialized nullptr value: " << serializedNull << "\n";
    if (deserializedNull == nullptr) {
        std::cout << "Success: nullptr correctly serialized and deserialized.\n";
    }

    return 0;
}