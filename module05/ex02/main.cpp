#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <cstdlib> // rand() ja srand()
#include <ctime>   // time()

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define AT __FILE__ ":" TOSTRING(__LINE__)

int main()
{
    std::srand(std::time(NULL)); //intialization of the seed value through time
    
    
    return 0;
}