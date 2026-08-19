#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Default constructor
AForm::AForm() :
_name("Unnamed"),
_signed(false),
_signGrade(1),
_execGrade(1)
{
    std::cout << "Randomized AForm " << _name << " created (Sign: " 
              << _signGrade << ", Exec: " << _execGrade << ")\n";
}
//modified constructor for ex02
AForm::AForm(std::string name, int signGrade, int execGrade) : 
_name(name),
_signed(false),
_signGrade(signGrade),
_execGrade(execGrade)
{
    if (signGrade < 1)
        throw GradeTooHighException();
    if (execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150)
        throw GradeTooLowException();
    if (execGrade > 150)
        throw GradeTooLowException();
    std::cout << "Named form " << _name << " created (Sign: " 
              << _signGrade << ", Exec: " << _execGrade << ")\n";

}

// Copy constructor
AForm::AForm(const AForm& other) :
_name(other._name),
_signed(other._signed),
_signGrade(other._signGrade),
_execGrade(other._execGrade)
{
    std::cout << "AForm copy constructor called\n";
}

// Copy assignment operator
AForm& AForm::operator=(const AForm& other)
{
    std::cout << "AForm copy assignment operator called\n";
    if (this != &other)
        _signed = other._signed;
    return (*this);
}

AForm::~AForm()
{
    std::cout << "AForm destructor called\n";
}

const std::string AForm::getName() const
{
    return (_name);
}
bool        AForm::getSigned() const
{
    return (_signed);
}
int   AForm::getSignGrade() const
{
    return (_signGrade);
}

int   AForm::getExecGrade() const
{
    return (_execGrade);
}

const char* AForm::GradeTooLowException::what() const throw()
{
    
    return ("Grade too low.");
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char* AForm::NotSignedException::what() const throw()
{
    return ("Form is not signed.");
}

void AForm::beSigned(const Bureaucrat& object)
{
    if (object.getGrade() <= this->getSignGrade())
    {
        this->_signed = true;
    }
    else 
    {
        throw AForm::GradeTooLowException();
    }
}

void AForm::checkExecutionRequirements(Bureaucrat const & executor) const
{
    // Ensure the form has been signed before it can be executed.
    if (this->_signed == false)
        throw AForm::NotSignedException();
    // Ensure the bureaucrat's grade is high enough to execute the form.
    if (executor.getGrade() > this->_execGrade)
        throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, AForm const& rhs)
{
    
    out << rhs.getName() << " signGrade: " << rhs.getSignGrade() << " execGrade: " << rhs.getExecGrade() <<
    " signed state: " << rhs.getSigned() << "." << std::endl;
    return (out);
}