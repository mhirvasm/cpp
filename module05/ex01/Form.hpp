#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Form
{
    private:
            const std::string _name;
            bool              _signed;
            const int         _signGrade;
            const int         _execGrade;

    public:
            Form();
            Form(const Form& other);
            Form& operator=(const Form& other);
            ~Form();

            std::string getName() const;
            bool        getSigned();
            const int   getSignGrade() const;
            const int   getExecGrade() const;

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
std::ostream& operator<<(const std::ostream& out, Form const& rhs);

#endif