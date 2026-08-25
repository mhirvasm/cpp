#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cmath>
#include <cctype>

// Implement the conversion logic here
void ScalarConverter::convert(const std::string& literal) {
    
    double value = 0.0;
    std::size_t pos = 0;

    try {
        // handle single char literal first
        if (literal.length() == 1 && !std::isdigit(literal[0])) {
            value = static_cast<double>(literal[0]);
        } else {
            // parse string update pos
            value = std::stod(literal, &pos);

            // check that the entire string is consumed
            if (pos < literal.length()) {
                // allow the unconsumed character only if it is an 'f' at the very end
                if (pos == literal.length() - 1 && literal[pos] == 'f') {
                    // this is a valid float literal 
                } else {
                    // garbage collector
                    throw std::invalid_argument("Invalid trailing characters");
                }
            }
        }
    } catch (...) {
        // This will catch both std::stod parsing failures and our custom garbage throw
        std::cout << "Invalid input\n";
        return;
    }

    // cast to char and check limits
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max()) 
    {
        std::cout << "impossible\n";
    } else if (!std::isprint(static_cast<char>(value))) {
        std::cout << "Non displayable\n";
    } else {
        std::cout << "'" << static_cast<char>(value) << "'\n";
    }

    // Cast to int and check limits
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) 
    {
        std::cout << "impossible\n";
    } else {
        std::cout << static_cast<int>(value) << "\n";
    }

    bool isWhole = (std::fmod(value, 1.0) == 0.0) && !std::isnan(value) && !std::isinf(value);

    // Cast and print float
    std::cout << "float: " << static_cast<float>(value);
    if (isWhole) 
    {
        std::cout << ".0"; 
    }
    std::cout << "f\n";

    // print double
    std::cout << "double: " << value;
    if (isWhole) 
    {
        // manually append .0 only if the number is whole and valid
        std::cout << ".0"; 
    }
std::cout << "\n";
}