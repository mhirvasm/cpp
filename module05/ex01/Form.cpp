#include "Form.hpp"
#include <cstdlib> // rand() ja srand()
#include <ctime>   // time()

// Default constructor
Form::Form() :
_name("Unnamed"),
_signed(false),
_signGrade(_generateRandomGrade()),
_execGrade(_generateRandomGrade())
{
    std::cout << "Randomized Form " << _name << " created (Sign: " 
              << _signGrade << ", Exec: " << _execGrade << ")\n";
}

// Copy constructor
Form::Form(const Form& other) :
_name(other._name),
_signed(other._signed),
_signGrade(other._signGrade),
_execGrade(other._execGrade)
{
    std::cout << "Form copy constructor called\n";
}

// Copy assignment operator
Form& Form::operator=(const Form& other)
{
    std::cout << "Form copy assignment operator called\n";
    if (this != &other)
        _signed = other._signed;
    return (*this);
}

Form::~Form()
{
    std::cout << "Form destructor called\n";
}

const std::string Form::getName() const
{
    return (_name);
}
bool        Form::getSigned() const
{
    return (_signed);
}
int   Form::getSignGrade() const
{
    return (_signGrade);
}

int   Form::getExecGrade() const
{
    return (_execGrade);
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low.\n");
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high\n");
}

void Form::beSigned(const Bureaucrat& object)
{
    if (object.getGrade() <= this->getSignGrade())
    {
        std::cout << "Bureaucrat " << object.getName() << " signed " << _name << std::endl;
    }
    else 
    {
        std::cout << "Bureaucrat " << object.getName() << " couldnt sign the " << _name << " because grade too low." << std::endl;
        throw Form::GradeTooLowException();
    }
}

int Form::_generateRandomGrade() const 
{
    //generating random number between 1-150
    return (std::rand() % 150) + 1;
}