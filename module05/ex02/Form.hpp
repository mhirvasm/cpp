#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
            const std::string _name;
            bool              _signed;
            const int         _signGrade;
            const int         _execGrade;

    public:
            Form();
            Form(std::string name);
            Form(const Form& other);
            Form& operator=(const Form& other);
            ~Form();

            const std::string   getName() const;
            bool                getSigned() const;
            int                 getSignGrade() const;
            int                 getExecGrade() const;

            void beSigned(const Bureaucrat& object);

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

            //getters for all attributes
            //add beSigned() member function
            //add signForm() member function IN BUREAUCRAT CLASS 
            /* This function must
                call Form::beSigned() to attempt to sign the form. If the form is signed successfully, it
                will print something like:
                <bureaucrat> signed <form>
                
                Otherwise, it will print something like:
                <bureaucrat> couldn’t sign <form> because <reason>
                
                */

};

//overload << insertion operator here!
std::ostream& operator<<(std::ostream& out, Form const& rhs);
int           generateRandomGrade(); // to be used in intialization with default constructor

#endif