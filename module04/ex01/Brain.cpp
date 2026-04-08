#include "Brain.hpp"
#include <iostream>
#include <sstream> // for brain intialization

Brain::Brain()
{

    std::cout << "Brain default constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
    {   std::stringstream ss;
        ss << "Empty thought " << i;
        this->ideas[i] = ss.str();
    }
}

Brain::Brain(const Brain& other)
{
    std::cout << "Copy constructor called for the Brain.\n";
    *this = other;
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Copy assignment operator called for the Brain.\n";
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = other.ideas[i]; 
        }
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Destructor called for Brain.\n";
}