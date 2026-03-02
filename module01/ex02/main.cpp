#include <iostream>

int main(void)
{
    std::string test = "HI THIS IS BRAIN";

    std::string* stringPTR = &test;
    std::string& stringREF = test;

    std::cout << "Memory address of the string variable: " << &test << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "Value of the string variable: " << test << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
}