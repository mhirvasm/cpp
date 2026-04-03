#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

//OCF is standardized way to make sure memory management and copying is being done safely and predictably 

class Fixed
{
    private:
            int              _fixed;
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
    
    //EX01 additions
    Fixed(const int int_val);
    Fixed(const float float_val);
    float toFloat(void) const;
    int toInt(void) const;
    //that returns the raw value of the fixed-point value.
    int getRawBits(void) const;
    //that sets the raw value of the fixed-point number
    void setRawBits(int const raw);

    //overload operators

    //comparison operators
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    //arithmetic operators
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    //increment and decrement
    //pre increments
    Fixed& operator++(void);
    Fixed& operator--(void);
    //post increments
    Fixed operator++(int); //dummy parameter
    Fixed operator--(int); //dummy parameter

    //min and max functions
    //const ones
    static const Fixed& max(const Fixed& obj1, const Fixed& obj2);
    static const Fixed& min(const Fixed& obj1, const Fixed& obj2);
    //non const
    static Fixed& max(Fixed& obj1, Fixed& obj2);
    static Fixed& min(Fixed& obj1, Fixed& obj2);
};
    //This needs to be added outside of the class
    std::ostream& operator<<(std::ostream& out, const Fixed& fixed_obj);
    
#endif