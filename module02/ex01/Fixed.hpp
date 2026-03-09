#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

//OCF is standardized way to make sure memory management and copying is being done safely and predictably 

class Fixed
{
    private:
            int _fixed;
            static const int _fractionalBits = 8;

    public:
    //we need default constructor, constructor without arguments
    Fixed();
    //copy constructor, creates new object by copying object
    Fixed(const Fixed& other);
    //copy assignment operator, transfers objects values into another livin object
    Fixed& operator=(const Fixed& other);
    //destructor
    ~Fixed();

    //that returns the raw value of the fixed-point value.
    int getRawBits(void) const;
    //that sets the raw value of the fixed-point number
    void setRawBits(int const raw);

};

#endif