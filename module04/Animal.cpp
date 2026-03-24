#include "Animal.hpp"


    Animal::Animal() :
    _type("Uncategorized")
    {
        std::cout << "Default constructor for Animal is called\n";  
    }
    
    Animal::Animal(const Animal& other) :
    _type(other._type)
    {
        std::cout << "Copy constructor called from Animal.\n";
    }

    Animal& Animal::operator=(const Animal& other)
    {
        std::cout << "Copy assignment operator called from Animal.\n";
        
        if (this != &other)
        {
            this->_type = other._type;
        }
        return (*this);
    }

    Animal::~Animal()
    {
        std::cout << "Destructor called for Animal.\n";
    }

    void Animal::makeSound() const
    {
        std::cout << "General animal sound🎶🌎\n";
    }

    std::string Animal::getType() const
    {
        return (_type);
    }