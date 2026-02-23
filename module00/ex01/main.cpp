#include "PhoneBook.hpp"
#include "Contact.hpp"

void print_welcome() {
    std::cout << "******************************************" << std::endl;
    std::cout << "* *" << std::endl;
    std::cout << "* WELCOME TO MY AWESOME PHONEBOOK      *" << std::endl;
    std::cout << "* VERSION 1.0                *" << std::endl;
    std::cout << "* *" << std::endl;
    std::cout << "******************************************" << std::endl;
    std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
    std::cout << "******************************************" << std::endl;
}

int main ()
{
    std::string input;
    PhoneBook phonebook;
    //make the loop here
    while(1 == 1)
    {
        print_welcome();
        std::getline(std::cin, input);
        if (input == "ADD")
            phonebook.add_contact();
            
        else if (input == "SEARCH")
            phonebook.search_contact();
        else if (input == "EXIT")
            return (0);
        else
            std::cout << "Bad input";
        std::endl (std::cout);
    }
    //We need two classes, phonebook and contacts

    //phonebook has array of contacts. max 8 contacts. if 9 contact, replace oldest.
    //dynamic allocation is forbidden

    //contact stands for phonebook contact
    
    
    /*At program start-up, the phonebook is empty and the user is prompted to enter one
    of three commands. The program only accepts ADD, SEARCH and EXIT.*/
    //any other input is ignored 
}
 