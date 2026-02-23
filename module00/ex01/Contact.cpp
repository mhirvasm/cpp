
#include "Contact.hpp"

void Contact::set_firstname(std::string firstname) 
{
    this->_firstname = firstname;
}

void Contact::set_lastname(std::string lastname)
{
    this->_lastname = lastname;
}

void Contact::set_nickname(std::string nickname) 
{
    this->_nickname = nickname;
}

void Contact::set_phonenumber(std::string phonenumber)
{
    this->_phonenumber = phonenumber;
}

void Contact::set_darksecret(std::string darksecret)
{
    this->_darksecret = darksecret;
}


std::string Contact::get_firstname(void) const
{
     return (this->_firstname);
}

std::string Contact::get_lastname(void) const 
{
     return (this->_lastname);
}

std::string Contact::get_nickname(void) const
{
     return (this->_nickname);
}

std::string Contact::get_phonenumber(void) const 
{
    return (this->_phonenumber);
}

std::string Contact::get_darksecret(void) const 
{
    return (this->_darksecret);
}