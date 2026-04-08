#include "Dog.hpp"

Dog::Dog()
{
    this->_type = "Dog";
    std::cout << "Default constructor for Dog is called\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Copy constructor for Dog is called\n";
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Copy assignment operator for Dog is called\n";
    if (this != &other)
    {
        Animal::operator=(other);
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Destructor for Dog is called\n";
}

void Dog::makeSound() const
{
    std::cout << "WOOOOOOOOOOOOOOOOOOOOOOOOF🐕\n";
}