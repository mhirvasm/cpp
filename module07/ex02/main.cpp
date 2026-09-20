#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    // --- standard 42 mandatory tests ---
    
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    
    // mirror test: fill both arrays with the exact same random values
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    // deep copy stress test: scope block forces destruction of tmp and test
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    } // <- destructors for tmp and test are called here. 

    // verify memory integrity: if the copies were shallow, the data would be corrupted now
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    // out of bounds test: negative index (overflows to massive unsigned int)
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "caught exception for index -2: " << e.what() << '\n';
    }

    // out of bounds test: exact capacity limit
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "caught exception for index MAX_VAL: " << e.what() << '\n';
    }

    // reassignment test
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;

    // --- additional tests for evaluation ---

    std::cout << "\n--- complex type test (std::string) ---\n";
    Array<std::string> string_array(3);
    string_array[0] = "hive";
    string_array[1] = "helsinki";
    string_array[2] = "42";

    for (unsigned int i = 0; i < string_array.size(); ++i) 
    {
        std::cout << "string_array[" << i << "] = " << string_array[i] << "\n";
    }

    std::cout << "\n--- const array read-only test ---\n";
    // copy constructor creates a const array
    const Array<int> const_numbers(numbers); 
    
    // const_numbers[0] = 42; // <- uncommenting this will cause a compile error
    std::cout << "const_numbers[0] = " << const_numbers[0] << " (read successfully via const operator[])\n";
    
    return 0;
}