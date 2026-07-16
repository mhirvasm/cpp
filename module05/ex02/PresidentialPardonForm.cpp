#include "PresidentialPardonForm.hpp"

/*• PresidentialPardonForm: Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox*/

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
AForm("PresidentialPardonForm", 25, 5),
_target(target)
{
    std::cout << "Presidential constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
AForm(other),
_target(other._target)
{
    std::cout << "Presidential copyconstructor called." << std::endl;
}
PresidentialPardonForm& PresidentialPardonForm:: operator=(const PresidentialPardonForm& other)
{
    std::cout << "Presidential copyassignment operator called." << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Presidential destructor called." << std::endl;
}

void        PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    // Ensure the form is signed and the bureaucrat can execute it.
    this->checkExecutionRequirements(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}