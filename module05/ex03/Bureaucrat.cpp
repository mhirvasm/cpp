#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() :
_name("Unnamed"),
_grade(150)
{
    std::cout << "Default constructor called for bureaucrat\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) :
_name(name)
{
    
    if (grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    if (grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
_name(other._name),
_grade(other._grade)
{
    std::cout << " Bureaucrat copyconstructor called\n";
    
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "Bureaucrat copy assignment operator called\n";
    if (this != &other)
    {
        //name is const, so we only take grade
        this->_grade = other._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << _name << " destructor called.\n";
}

const std::string Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const 
{
    return (_grade);
}

void Bureaucrat::increment()
{
    _grade--;
    if (_grade < 1)
    {
        _grade++;
        throw Bureaucrat::GradeTooHighException();
    }
}

void Bureaucrat::decrement()
{
    _grade++;
    if (_grade > 150)
    {
        _grade--;
        throw Bureaucrat::GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& out, Bureaucrat const& rhs)
{
    //<name>, bureaucrat grade <grade> <----- FORMAT to print
    out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
    return (out);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too High!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too Low!");
}

void Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << "Bureaucrat " << this->getName() << " signed " << form.getName() << std::endl;
    }

    catch(std::exception & e)
    {
        std::cout << this->getName() << " couldn't sign " 
              << form.getName() << " because " 
              << e.what() << std::endl;
    }

}

void Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch(std::exception & e)
    {
        std::cout << this->getName() << " couldn't execute "
              << form.getName() << " because "
              << e.what() << std::endl;
    }
}