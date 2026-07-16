#include "Form.hpp"
#include "Bureaucrat.hpp"

// Default constructor
Form::Form() :
_name("Unnamed"),
_signed(false),
_signGrade(1),
_execGrade(1)
{
    std::cout << "Unnamed form " << _name << " created (Sign: " 
              << _signGrade << ", Exec: " << _execGrade << ")\n";
}

Form::Form(std::string name, int signGrade, int execGrade) : 
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
    
    return ("Grade too low.");
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

void Form::beSigned(const Bureaucrat& object)
{
    if (object.getGrade() <= this->getSignGrade())
    {
        this->_signed = true;
    }
    else 
    {
        throw Form::GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& out, Form const& rhs)
{
    
    out << rhs.getName() << " signGrade: " << rhs.getSignGrade() << " execGrade: " << rhs.getExecGrade() <<
    " signed state: " << rhs.getSigned() << "." << std::endl;
    return (out);
}