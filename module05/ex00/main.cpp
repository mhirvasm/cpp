#include <iostream>
#include "Bureaucrat.hpp"


int main()
{
    // Testing accepted creation
    std::cout << "--- Test 1: Standard Bureaucrat ---" << std::endl;
    try 
    {
        Bureaucrat b1("High Ranker", 2);
        std::cout << b1 << std::endl; // Using the overloaded << operator here
        
        b1.increment(); // 2 -> 1
        std::cout << "After increment: " << b1 << std::endl;
        
        // Try to increment over the bounds
        std::cout << "Attempting to increment grade 1..." << std::endl;
        b1.increment(); 
    }
    catch (std::exception & e) 
    {
        // e.what() returns the error text provided
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Invalid Construction (Too Low) ---" << std::endl;
    try 
    {
        // Testing forbidden 151
        Bureaucrat b2("Intern", 151); 
        std::cout << b2 << std::endl;
    }
    catch (std::exception & e) 
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Invalid Construction (Too High) ---" << std::endl;
    try 
    {
        // 0 or negative numbers are forbidden
        Bureaucrat b3("The Boss", 0); 
        std::cout << b3 << std::endl;
    }
    catch (std::exception & e) 
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 4: Decrement limit ---" << std::endl;
    try 
    {
        Bureaucrat b4("Low Ranker", 149);
        std::cout << b4 << std::endl;
        
        b4.decrement(); // 149 -> 150
        std::cout << "After decrement: " << b4 << std::endl;
        
        b4.decrement(); // 150 -> 151 (Throws!)
    }
    catch (std::exception & e) 
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}