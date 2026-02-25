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

    std::string firstname, lastname, phonenumber, nickname;
    int         index = 0;
    
    //interface
    std::cout << "|" << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "Firstname" << "|";
    std::cout << std::setw(10) << "Lastname" << "|";
    std::cout << std::setw(10) << "Nickname" << "|";
    std::cout << std::endl;

    //print array
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
        std::cout << "gief index mannn bomboclat" << std::endl;
        while (true)
        {
        std::cin >> index;
        std::cin.ignore();
        if (index <= _count && index >= 0)
            break;
        }
        
        std::cout << "Firstname: " <<_contacts[index].get_firstname() << std::endl;
        std::cout << "Lastname: " <<_contacts[index].get_lastname() << std::endl;
        std::cout << "Nickname: " <<_contacts[index].get_nickname() << std::endl;
        std::cout << "Phonenumber: " <<_contacts[index].get_phonenumber() << std::endl;
        std::cout << "Dark secret: " <<_contacts[index].get_darksecret() << std::endl;
    }
}

