#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <cstdlib> // rand() ja srand()
#include <ctime>   // time()

int main()
{
    std::srand(std::time(NULL)); //intialization of the seed value through time

    Form form1;
    std::cout << std::endl;
    Form form2;
    std::cout << std::endl;
    Form form3;
    std::cout << std::endl;
    Form form4;

    return 0;
}