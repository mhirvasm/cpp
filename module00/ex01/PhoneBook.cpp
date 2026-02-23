#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->_index = 0;
    this->_count = 0;
}

PhoneBook::~PhoneBook()
{

}

void    add_contact()
{
    /*
     If the user enters this command, they are prompted to input the information
     of the new contact one field at a time. Once all the fields have been completed,
     add the contact to the phonebook.
     ◦ The contact fields are: first name, last name, nickname, phone number, and
     darkest secret. A saved contact can’t have empty fields.
    */
}

void    search_contact()
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
}