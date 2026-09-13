#include <iostream>
#include <string>
#include "Iter.hpp"

// Instantiated function template as required by the subject
template <typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

// Function to modify elements (non-const)
template <typename T>
void incrementElement(T& element) {
    element++;
}

int main(void) {
    std::cout << "--- TEST 1: Non-const Integer Array ---\n";
    int intArray[] = {1, 2, 3, 4, 5};
    std::size_t intLen = sizeof(intArray) / sizeof(intArray[0]);
    
    // Modify array
    ::iter(intArray, intLen, incrementElement<int>);
    // Print array
    ::iter(intArray, intLen, printElement<int>);
    std::cout << "\n\n";

    std::cout << "--- TEST 2: Const String Array ---\n";
    const std::string strArray[] = {"Hello", "Hive", "Helsinki", "42"};
    std::size_t strLen = sizeof(strArray) / sizeof(strArray[0]);
    
    // If we tried to pass incrementElement here, it would fail to compile (which is correct).
    ::iter(strArray, strLen, printElement<std::string>);
    std::cout << "\n";

    return 0;
}