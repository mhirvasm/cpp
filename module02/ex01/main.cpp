#include "Fixed.hpp"
#include <iomanip>

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



    //Showing overflow
    Fixed const maxSafeInt(8388607); //Biggest possible int number which 
    std::cout << "Max safe int (8388607): " << maxSafeInt << " (as float: " << maxSafeInt.toFloat() << ")" << std::endl;

    //here happens the overflow 
    Fixed const overflowTest(8388608);
    std::cout << "Overflow test (8388608): " << overflowTest << std::endl;


    std::cout << "\n--- PRECISION AND RANGE TEST ---" << std::endl;
    Fixed const highPrecision(42.00390625f);
    Fixed const largeNumber(30000.5f);
    
    std::cout << "Target: 42.00390625 | Result: " << std::fixed << std::setprecision(10) << highPrecision << std::endl;
    std::cout << "Target: 30000.5     | Result: " << largeNumber << std::endl;

    //precision loss tests
    std::cout << "Precision testing" << std::endl;
    Fixed const precision(42.42424242f);
    std::cout << precision << std::endl;
}