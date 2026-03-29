#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) :
_name(name)
{
    if (grade < 1)
    {
        throw GradeTooHighException();
    }
    if (grade > 150)
    {
        throw GradeTooLowException();
    }
    _grade = grade;
}

std::string Bureaucrat::getName() const
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
        throw GradeTooHighException();
    }
}

void Bureaucrat::decrement()
{
    _grade++;
    if (_grade > 150)
    {
        _grade--;
        throw GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& out, Bureaucrat const& rhs)
{
    //<name>, bureaucrat grade <grade> <----- FORMAT to print
    out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
    return (out);
}

const char* GradeTooHighException::what() const throw()
{
    return ("Grade is too High!");
}

const char* GradeTooLowException::what() const throw()
{
    return ("Grade is too Low!");
}