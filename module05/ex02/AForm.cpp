#include "AForm.hpp"
#include <cstdlib> // rand() ja srand()
#include <ctime>   // time()

// Default constructor
AForm::AForm() :
_name("Unnamed"),
_signed(false),
_signGrade(generateRandomGrade()),
_execGrade(generateRandomGrade())
{
    std::cout << "Randomized AForm " << _name << " created (Sign: " 
              << _signGrade << ", Exec: " << _execGrade << ")\n";
}
//modified constructor for ex02
AForm::AForm(std::string name, int signGrade, int execGrade) : 
_name(name),
_signed(false),
_signGrade(signGrade),
_execGrade(_execGrade)
{
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
    
    return ("Grade too low.\n");
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high\n");
}

int generateRandomGrade()
{
    //generating random number between 1-150
    return (std::rand() % 150) + 1;
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

std::ostream& operator<<(std::ostream& out, AForm const& rhs)
{
    
    out << rhs.getName() << " signGrade: " << rhs.getSignGrade() << " execGrade: " << rhs.getExecGrade() <<
    " signed state: " << rhs.getSigned() << "." << std::endl;
    return (out);
}