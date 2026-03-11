#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    a = Fixed( 1234.4321f );

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    //zero tests
    Fixed const zero(0.0f);
    std::cout << "divide by zero test " << zero.toFloat() << std::endl;
    std::cout << "divide by zero test " << zero.toInt() << " as integer" << std::endl;
    //precision loss tests
    Fixed const precision(42.42424242f);
    std::cout << precision << std::endl;

    //Showing overlofw
    Fixed const maxSafeInt(8388607); //Biggest possible int number which 
    std::cout << "Max safe int (8388607): " << maxSafeInt << " (as float: " << maxSafeInt.toFloat() << ")" << std::endl;

    //here happens the overflow 
    Fixed const overflowTest(8388608);
    std::cout << "Overflow test (8388608): " << overflowTest << std::endl;
}