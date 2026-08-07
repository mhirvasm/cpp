#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>

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
            Form(std::string name, int signGrade, int execGrade);
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


};

//overload << insertion operator here!
std::ostream& operator<<(std::ostream& out, Form const& rhs);

#endif