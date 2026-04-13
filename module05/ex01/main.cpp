#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <cstdlib> // rand() ja srand()
#include <ctime>   // time()

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define AT __FILE__ ":" TOSTRING(__LINE__)

int main()
{
    std::srand(std::time(NULL)); //intialization of the seed value through time

    Form form1("Form1");
    //std::cout << std::endl;
    Form form2("Form2");
    //std::cout << std::endl;
    Form form3("Form3");
    //std::cout << std::endl;
    Form form4("Form4");
    std::cout << std::endl;

    Bureaucrat bure1("Bob from " AT, 0);

    std::cout << "Bure1 signGrade: " << bure1.getGrade() << std::endl;

    bure1.signForm(form1);
    bure1.signForm(form2);
    bure1.signForm(form3);
    bure1.signForm(form4);

    return 0;
}