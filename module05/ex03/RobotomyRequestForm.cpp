#include "RobotomyRequestForm.hpp"
#include <cstdlib>

/*• RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises, then informs that <target> has been robotomized
successfully 50% of the time. Otherwise, it informs that the robotomy failed.*/

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
AForm("RobotomyRequestForm", 72, 45),
_target(target)
{
    std::cout << "Robotomy constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
AForm(other),
_target(other._target)
{
    std::cout << "Robotomy copyconstructor called." << std::endl;
}
RobotomyRequestForm& RobotomyRequestForm:: operator=(const RobotomyRequestForm& other)
{
    std::cout << "Robotomy copyassignment operator called." << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Robotomy destructor called." << std::endl;
}

void        RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    // Ensure the form is signed and the bureaucrat can execute it.
    this->checkExecutionRequirements(executor);
    std::cout << "Brrr..." << std::endl;
    std::cout << "Brrr..." << std::endl;
    if (std::rand() % 2 == 0)
    {
        std::cout << _target << " has been robotomized successfully" << std::endl;
    }
    else
    {
        std::cout << _target << " robotomy failed" << std::endl;
    }
}