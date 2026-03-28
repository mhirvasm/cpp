#include "Bureaucrat.hpp"

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
    //prolly try catch here
}

void Bureaucrat::decrement()
{
    _grade++;
    //prolly try catch here
}

std::ostream& operator<<(std::ostream& out, Bureaucrat const& rhs)
{
    //<name>, bureaucrat grade <grade> <----- FORMAT to print
    out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
    return (out);
}

/*
try
{
/do some stuff with bureaucrats/
}
catch (std::exception & e)
{
/handle exception/
}
*/