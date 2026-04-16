#include "ShrubberyCreationForm.hpp"

/*• ShrubberyCreationForm: Required grades: sign 145, exec 137
Creates a file <target>_shrubbery in the working directory and writes ASCII trees
inside it.*/

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
AForm("Shrubbery", 145, 137),
_target(target)
{
    std::cout << "Shrubbery constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
AForm(other),
_target(other._target)
{
    std::cout << "Shrubbery copyconstructor called." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm:: operator=(const ShrubberyCreationForm& other)
{
    std::cout << "Shrubbery copyassignment operator called." << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Shrubbery destructor called." << std::endl;
}

void        AForm::execute(Bureaucrat const & executor) const
{
    try
    {
        //check it is signed
        //check bureaucrat exec grade is enough, otherwise throw exception
        //execute if all is good 
    }
    catch(std::exception & e)
    {
        
    }
}