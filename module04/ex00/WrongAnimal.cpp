#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") 
{
    std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) 
{
    std::cout << "WrongAnimal copy constructor called\n";
    *this = other; // Use our own copy assignment operator
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) 
{
    std::cout << "WrongAnimal assignment operator called\n";
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

// Not virtual anymore
WrongAnimal::~WrongAnimal() 
{
    std::cout << "WrongAnimal destructor called\n";
}

// Not virtual anymore
void WrongAnimal::makeSound() const 
{
    std::cout << "Whatsup duuuuuuude?\n";
}

std::string WrongAnimal::getType() const 
{
    return this->type;
}