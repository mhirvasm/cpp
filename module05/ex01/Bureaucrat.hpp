#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Form;

class Bureaucrat
{
    private:
        std::string const _name;
        int            _grade; //Any attempt to instantiate a Bureaucrat with an invalid grade must throw an exception:
                                //either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.

        /*
        You will provide getters for both attributes: getName() and getGrade(). You must
        also implement two member functions to increment or decrement the bureaucrat’s grade.
        If the grade goes out of range, both functions must throw the same exceptions as the
        constructor.*/
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        const std::string getName() const;
        int getGrade() const;
        void increment();
        void decrement();
        void signForm(Form& form);

        class GradeTooHighException : public std::exception
        {
        public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
        public:
                virtual const char* what() const throw();
        };

   
};


std::ostream& operator<<(std::ostream& out, Bureaucrat const& rhs); //<name>, bureaucrat grade <grade> <----- FORMAT to print


#endif