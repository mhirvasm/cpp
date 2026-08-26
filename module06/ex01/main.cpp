#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr) {
    // reinterpret_cast changes pointer to int without changing bits
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    // reinterpret_cast changes int back to pointer
    return reinterpret_cast<Data*>(raw);
}