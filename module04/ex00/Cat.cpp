#include "Cat.hpp"

    Cat::Cat()
    {
        this->_type = "Cat";
        std::cout << "Default constructor for Cat is called\n";
    }

    Cat::Cat(const Cat& other) : Animal(other)
    {
        std::cout << "Copy constructor for Cat is called\n";
    }

    Cat& Cat::operator=(const Cat& other)
    {
        std::cout << "Copy assignment operator for Cat is called\n";
        if (this != &other)
        {
            Animal::operator=(other);
        }
        return (*this);
    }

    Cat::~Cat()
    {
        std::cout << "Destructor for Cat is called\n";
    }

    void Cat::makeSound() const
    {
        std::cout << "MEEEEEEEEEEEEEEEEEEEEEEEEEEEEOWW🐈\n";
    }