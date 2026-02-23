#include "PhoneBook.hpp"
#include <iomanip> //manipulator functions

//Constructor intializing values
PhoneBook::PhoneBook()
{
    this->_index = 0;
    this->_count = 0;
}
//Destructor
PhoneBook::~PhoneBook()
{

}

void    PhoneBook::add_contact()
{
    /*
     If the user enters this command, they are prompted to input the information
     of the new contact one field at a time. Once all the fields have been completed,
     add the contact to the phonebook.
     ◦ The contact fields are: first name, last name, nickname, phone number, and
     darkest secret. A saved contact can’t have empty fields.
    */
    std::string firstname, lastname, nickname, phonenumber, darkestsecret;

    while (true)
    {
    std::cout << "Enter firstname: ";
    std::getline(std::cin, firstname);
    if (!firstname.empty())
    {
        this->_contacts[this->_index % 8].set_firstname(firstname);
        break ;
    }
    std::cout << "Invalid input, field can't be empty.\n" << std::endl;
    }

    while (true)
    {
    std::cout << "Enter lastname: ";
    std::getline(std::cin, lastname);
    if (!lastname.empty())
    {
        this->_contacts[this->_index % 8].set_lastname(lastname);
        break ;
    }
    std::cout << "Invalid input, field can't be empty.\n" << std::endl;
    }

    while (true)
    {
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
    if (!nickname.empty())
    {
        this->_contacts[this->_index % 8].set_nickname(nickname);
        break ;
    }
    std::cout << "Invalid input, field can't be empty.\n" << std::endl;
    }


    while (true)
    {
    std::cout << "Enter phonenumber: ";
    std::getline(std::cin, phonenumber);
    if (!phonenumber.empty())
    {
        this->_contacts[this->_index % 8].set_phonenumber(phonenumber);
        break ;
    }
    std::cout << "Invalid input, field can't be empty.\n" << std::endl;
    }

    while (true)
    {
    std::cout << "Enter darkestsecret: ";
    std::getline(std::cin, darkestsecret);
    if (!darkestsecret.empty())
    {
        this->_contacts[this->_index % 8].set_darksecret(darkestsecret);
        break ;
    }
    std::cout << "Invalid input, field can't be empty.\n" << std::endl;
    }
    //increment index and count
    this->_index++;
    if (this->_count != 8)
        this->_count++;
    

}

void    PhoneBook::search_contact()
{
    /*
    ◦ Display the saved contacts as a list of 4 columns: index, first name, last
    name and nickname.
    ◦ Each column must be 10 characters wide. A pipe character (’|’) separates
    them. The text must be right-aligned. If the text is longer than the column,
    it must be truncated and the last displayable character must be replaced by a
    dot (’.’).
    ◦ Then, prompt the user again for the index of the entry to display. If the index
    is out of range or wrong, define a relevant behavior. Otherwise, display the
    contact information, one field per line.
    */
    
    //setw as set width
    // right to align text right 
    // |     index|first name| last name|  nickname|

    std::string firstname, lastname, phonenumber, nickname;

    std::cout << "|" << std::setw(10) << "Index" << "|";
    std::cout << "|" << std::setw(10) << "Firstname" << "|";
    std::cout << "|" << std::setw(10) << "Lastname" << "|";
    std::cout << "|" << std::setw(10) << "Nickname" << "|";
    std::cout << std::endl;

    for (int i = 0; i < this->_count; i++)
    {
        firstname = _contacts[i].get_firstname();
        lastname = _contacts[i].get_lastname();
        nickname = _contacts[i].get_nickname();

        std::cout << "|" << std::setw(10) << i << "|";
        std::cout << "|" << std::setw(10) << firstname << "|";
        std::cout << "|" << std::setw(10) << lastname << "|";
        std::cout << "|" << std::setw(10) << nickname << "|";
        std::cout << std::endl;
        
    }




}

void    exit()
{
    exit(0);
}