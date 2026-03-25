#include "PhoneBook.hpp"
#include "Contact.hpp"

void print_welcome() {

    std::cout << "******************************************" << std::endl;
    std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
    std::cout << "******************************************" << std::endl;
}

int main ()
{
    std::string input;
    PhoneBook phonebook;
    
    while(1 == 1)
    {
        print_welcome();
        if (!std::getline(std::cin, input)) // Fixing ctrl+d scenario
        {
            std::cout << std::endl;
            break;
        }
        if (input == "ADD")
        {
            phonebook.add_contact();
            continue;
        }
            
        if (input == "SEARCH")
        {
            phonebook.search_contact();
            continue;
            
        }
        else if (input == "EXIT")
            return (0);
        else
            std::cout << "Use the available commands provided: ADD, SEARCH or EXIT";
        std::cout << std::endl;
    } 
}
 