#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
private:
    // delete instantiation to prevent object creation
    ScalarConverter() = delete;
    ScalarConverter(const ScalarConverter&) = delete;
    ScalarConverter& operator=(const ScalarConverter&) = delete;
    ~ScalarConverter();

public:
    // static method declaration only
    static void convert(const std::string& literal);
};

#endif