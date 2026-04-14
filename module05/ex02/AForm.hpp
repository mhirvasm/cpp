#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
            const std::string _name;
            bool              _signed;
            const int         _signGrade;
            const int         _execGrade;

    public:
            AForm();
            AForm(std::string name);
            AForm(const AForm& other);
            AForm& operator=(const AForm& other);
            virtual ~AForm(); //make it virtual

            const std::string   getName() const;
            bool                getSigned() const;
            int                 getSignGrade() const;
            int                 getExecGrade() const;

            void                beSigned(const Bureaucrat& object);
            virtual void        execute(Bureaucrat const & executor) const = 0; //make it virtual

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
std::ostream& operator<<(std::ostream& out, AForm const& rhs);
int           generateRandomGrade(); // to be used in intialization with default constructor

#endif