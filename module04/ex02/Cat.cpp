#include "Cat.hpp"

Cat::Cat()
{
    this->_type = "Cat";
    this->_brain = new Brain;
    std::cout << "Default constructor for Cat is called\n";
}

Cat::Cat(const Cat& other) : 
Animal(other),
_brain(new Brain(*other._brain))
{
    std::cout << "Copy constructor for Cat is called\n";
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Copy assignment operator for Cat is called\n";
    if (this != &other)
    {
        Animal::operator=(other);

        if (this->_brain) // we need to delete the old brain before we copy the new brain
            delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Destructor for Cat is called\n";
    delete this->_brain;
}

void Cat::makeSound() const
{
    std::cout << "MEEEEEEEEEEEEEEEEEEEEEEEEEEEEOWW🐈\n";
}