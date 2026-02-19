#include <iostream>
#include <string>

int main ()
{
    std::string input;
    //make the loop here
    while(1 == 1)
    {
        std::cin >> input;
        if (input == "ADD")
            std::cout << "hey!";
        else if (input == "SEARCH")
            std::cout << "hoi";
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
 