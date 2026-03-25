#include "PhoneBook.hpp"
#include <iomanip> //manipulator functions
#include <cstdlib> //atoi

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
    std::string firstname, lastname, nickname, phonenumber, darkestsecret;

    while (true)
    {
    std::cout << "Enter firstname: ";
    if (!std::getline(std::cin, firstname))
    {
        std::cout << std::endl; //ctrl+d case
        return;
    }
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
    if (!std::getline(std::cin, lastname))
    {
        std::cout << std::endl; //ctrl+d case
        return;
    }
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
    if (!std::getline(std::cin, nickname))
    {
        std::cout << std::endl; //ctrl+d case
        return;
    }
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
    if (!std::getline(std::cin, phonenumber))
    {
        std::cout << std::endl; //ctrl+d case
        return;
    }
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
    if (!std::getline(std::cin, darkestsecret))
    {
        std::cout << std::endl; //ctrl+d case
        return;
    }
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

    std::string firstname, lastname, phonenumber, nickname;
    int         index = 0;
    
    //print array
    if (_count > 0)
    {
        //interface
        std::cout << "|" << std::setw(10) << "Index" << "|";
        std::cout << std::setw(10) << "Firstname" << "|";
        std::cout << std::setw(10) << "Lastname" << "|";
        std::cout << std::setw(10) << "Nickname" << "|";
        std::cout << std::endl;

    }
    for (int i = 0; i < this->_count; i++)
    {
        firstname = _contacts[i].get_firstname();
        lastname = _contacts[i].get_lastname();
        nickname = _contacts[i].get_nickname();

        if (firstname.length() > 10)
        {
            firstname = firstname.substr(0, 9) + ".";
        }
         if (lastname.length() > 10)
        {
            lastname = lastname.substr(0, 9) + ".";
        }
         if (nickname.length() > 10)
        {
            nickname = nickname.substr(0, 9) + ".";
        }

        std::cout << "|" << std::setw(10) << i << "|";
        std::cout << std::setw(10) << firstname << "|";
        std::cout << std::setw(10) << lastname << "|";
        std::cout << std::setw(10) << nickname << "|";
        std::cout << std::endl;   
    }
    if (_count > 0)
    {
        std::cout << "Give index number to watch more information" << std::endl;
        if (this->_count > 0)
    {
        std::string input;
        while (true)
        {
            std::cout << "Enter index to display: ";
            if (!std::getline(std::cin, input)) // Hallitsee Ctrl+D (EOF)
                return;

            if (_is_valid_index(input))
            {
                index = std::atoi(input.c_str());
                std::cout << "Firstname: " << _contacts[index].get_firstname() << std::endl;
                std::cout << "Lastname: " <<_contacts[index].get_lastname() << std::endl;
                std::cout << "Nickname: " <<_contacts[index].get_nickname() << std::endl;
                std::cout << "Phonenumber: " <<_contacts[index].get_phonenumber() << std::endl;
                std::cout << "Dark secret: " <<_contacts[index].get_darksecret() << std::endl;
                break;
            }
            else
            {
                std::cout << "Invalid index! Enter a number between 0 and " << _count - 1 << "." << std::endl;
            }
        }
    }
}
        else 
        {
            std::cout << "Phonebook is empty." << std::endl;
        }
}

bool PhoneBook::_is_valid_index(std::string str) const
{
    // check empty input
    if (str.empty())
        return false;

    // Check that all char are digits
    for (std::string::size_type i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }

    // transform into a number and check that its valid 
    int index = std::atoi(str.c_str());
    if (index >= 0 && index < this->_count)
        return true;

    return false;
}

