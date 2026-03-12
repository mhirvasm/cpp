#include "Fixed.hpp"

int main(void)
{
    //Cosntructor and destructor messages are commented out 

    //Start of the test provided by the subject
    std::cout << "-----------------------------------------------" << std::endl;
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    //Here ends the tests provided by the subject
    
    //Comparison operators
    std::cout << "\n[ Testing Comparisons ]" << std::endl;
    Fixed const val1(10.5f);
    Fixed const val2(10.5f);
    Fixed const val3(10.51f);

    // we test if the exact same values return true for == and >=
    if (val1 == val2 && val1 >= val2)
    {
        std::cout << "Equality test: PASSED" << std::endl;
    }
    else
    {
        std::cout << "Equality test: FAILED" << std::endl;
    }

    // we test if a slightly larger float is correctly identified
    if (val1 < val3 && val3 != val1)
    {
        std::cout << "Difference test: PASSED" << std::endl;
    }
    else
    {
        std::cout << "Difference test: FAILED" << std::endl;
    }

    //Arithmetic operations
    std::cout << "\n[ Testing Arithmetic ]" << std::endl;
    Fixed const num1(50.5f);
    Fixed const num2(2);

    // we test subtraction and division, comparing them to expected float outputs
    std::cout << "50.5 - 2 = " << (num1 - num2) << " (Expected: 48.5)" << std::endl;
    std::cout << "50.5 / 2 = " << (num1 / num2) << " (Expected: 25.25)" << std::endl;

    // A chained arithmetic test! (Order of operations)
    // Here we test if temporary objects are handled correctly: 50.5 + (2 * 2)
    Fixed const chainedResult = num1 + (num2 * num2);
    std::cout << "50.5 + (2 * 2) = " << chainedResult << " (Expected: 54.5)" << std::endl;

    
    //Min max tests
    std::cout << "\n[ Testing Min and Max ]" << std::endl;
    std::cout << "Finding min value of 50.5 and 2: " << Fixed::min(num1, num2) << std::endl;
    std::cout << "Finding max value of 50.5 and 2: " << Fixed::max(num1, num2) << std::endl;

    return (0);
}