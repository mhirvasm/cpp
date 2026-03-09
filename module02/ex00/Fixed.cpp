#include "Fixed.hpp"

    //we need default constructor, constructor without arguments
    Fixed::Fixed() : _fixed(0)
    {
        std::cout << "Default constructor called\n";
    }
    //copy constructor, creates new object by copying object
    Fixed::Fixed(const Fixed& other) : _fixed(other.getRawBits())
    {
        std::cout << "Copy constructor called\n";
    }
    //copy assignment operator, transfers objects values into another livin object
    Fixed& Fixed::operator=(const Fixed& other)
    {
        std::cout << "Copy assignment operator called\n";
        if (this != &other)
        {
            this->_fixed = other._fixed;
        }
        return (*this);
    }
    //destructor
    Fixed::~Fixed()
    {
        std::cout << "Destructor called\n";
    }

    //that returns the raw value of the fixed-point value.
    int Fixed::getRawBits(void) const
    {
        std::cout << "getRawBits member function called\n";
        return (this->_fixed);
    }
    //that sets the raw value of the fixed-point number
    void Fixed::setRawBits(int const raw)
    {
        this->_fixed = raw;
    }