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

    //EX01 additions
    Fixed::Fixed(const int int_val) : _fixed(int_val << _fractionalBits)
    {
        std::cout << "Int constructor called\n";
    }

    Fixed::Fixed(const float float_val)
    {
        std::cout << "Float constructor called\n";

        this->_fixed = roundf(float_val * (1 << _fractionalBits));
    }

    float Fixed::toFloat(void) const
    {
        float floatNum;
        floatNum = ((float)this->_fixed / (1 << _fractionalBits));
        return (floatNum);
    }

    int Fixed::toInt(void) const
    {
        int intNum;
        intNum = this->_fixed >> _fractionalBits;
        return (intNum);
    }

    std::ostream& operator<<(std::ostream& out, const Fixed& fixed_obj)
    {
        out << fixed_obj.toFloat();
        return (out);
    }

    //ex02 ---->
    bool Fixed::operator>(const Fixed& other) const
    {
        if (this->_fixed > other._fixed) 
            return (true);
        else
            return (false);
    }

    bool Fixed::operator<(const Fixed& other) const
    {
        return (this->_fixed < other._fixed); // <-- Cleaner way
    }

    bool Fixed::operator>=(const Fixed& other) const
    {
        return (this->_fixed >= other._fixed);
    }
    bool Fixed::operator<=(const Fixed& other) const
    {
        return (this->_fixed <= other._fixed);
    }

    bool Fixed::operator==(const Fixed& other) const
    {
        return (this->_fixed == other._fixed);
    }

    bool Fixed::operator!=(const Fixed& other) const
    {
        return (this->_fixed != other._fixed);
    }

    //arithmetic operators
    Fixed Fixed::operator+(const Fixed& other) const
    {
        Fixed result;
        result._fixed = this->_fixed + other._fixed; //not so clean, and tighter range of number to use compared to next function style
        return (result);
    }

    Fixed Fixed::operator-(const Fixed& other) const
    {
        return Fixed(this->toFloat() - other.toFloat()); // <--- cleaner way 
        // also when using floats, we can use bigger numbers, than when using just raw data like in +
    }

    Fixed Fixed::operator*(const Fixed& other) const
    {
        return Fixed(this->toFloat() * other.toFloat());
    }

    Fixed Fixed::operator/(const Fixed& other) const
    {
        return Fixed(this->toFloat() / other.toFloat());
    }

    //increment and decrement
    //pre increments
    Fixed& Fixed::operator++(void)
    {
        this->_fixed++;
        return (*this);
    }

    Fixed& Fixed::operator--(void)
    {
        this->_fixed--;
        return (*this);
    }

    //post increments
    Fixed Fixed::operator++(int) //dummy parameter
    {
        Fixed temp = *this; // as we can see post increment needs to create temporary copy
        ++this->_fixed;     // which means that its not as efficient as pre incrementing
        return (temp); 
    }

    Fixed Fixed::operator--(int)  //dummy parameter
    {
        //another style for post increment/decrement
        Fixed temp(*this); // take a snapshot
        --(*this); //here we are using our own pre increment
        return (temp);
    }

    //min and max functions
    //const ones
    static const Fixed& max(const Fixed& obj1, const Fixed& obj2)
    {

    }

    static const Fixed& min(const Fixed& obj1, const Fixed& obj2)
    {

    }

    //non const
    static Fixed& max(Fixed& obj1, Fixed& obj2)
    {

    }

    static Fixed& min(Fixed& obj1, Fixed& obj2)
    {

    }
