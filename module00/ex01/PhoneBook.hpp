#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP


#include <iostream> //input output
#include <string> //string manipulation
#include "Contact.hpp" // Contact class
class PhoneBook
{
    //Instance variables
    private:
        int     _index; //contact indexing
        int     _count; //current contact count
        Contact _contacts[8];

    public:
        PhoneBook(); //constructor
        ~PhoneBook(); //deconstructor

        void    add_contact();
        void    search_contact();
        
};
#endif