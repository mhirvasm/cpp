#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private:
            std::string const _name;
            size_t            _grade; //Any attempt to instantiate a Bureaucrat with an invalid grade must throw an exception:
                                      //either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.

            /*
            You will provide getters for both attributes: getName() and getGrade(). You must
            also implement two member functions to increment or decrement the bureaucrat’s grade.
            If the grade goes out of range, both functions must throw the same exceptions as the
            constructor.*/
    public:
            Bureaucrat(std::string name);
            ~Bureaucrat();
            void getName();
            void getGrade();
            void increment();
            void decrement();

 

           
};

std::ostream& operator<<(std::ostream& out, Bureaucrat const& rhs); //<name>, bureaucrat grade <grade> <----- FORMAT to print


#endif