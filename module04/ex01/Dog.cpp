#include "Dog.hpp"

Dog::Dog()
{
    this->_type = "Dog";
    this->_brain = new Brain;
    std::cout << "Default constructor for Dog is called\n";
}

Dog::Dog(const Dog& other) :
Animal(other),
_brain(new Brain(*other._brain))
{
    std::cout << "Copy constructor for Dog is called\n";
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Copy assignment operator for Dog is called\n";
    if (this != &other)
    {
        Animal::operator=(other);

        if (this->_brain) // we need to delete the old brain before we copy the new brain
            delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Destructor for Dog is called\n";
    delete this->_brain;
}

void Dog::makeSound() const
{
    std::cout << "WOOOOOOOOOOOOOOOOOOOOOOOOF🐕\n";
}

Brain* Dog::getBrain() const
{
return this->_brain;
}