#include <iostream>
#include <vector>
#include "Span.hpp"

int main() {
    std::cout << "--- test 1: subject main ---" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    // expected output: 2 and 14
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "\n--- test 2: 10,000 numbers ---" << std::endl;
    Span massive_span(10000);
    std::vector<int> bulk_data;
    
    // generate 10000 consecutive numbers
    for (int i = 0; i < 10000; ++i) {
        bulk_data.push_back(i * 3); // interval of 3
    }
    
    try {
        // use the templated range insert
        massive_span.addNumbers(bulk_data.begin(), bulk_data.end());
        std::cout << "added 10000 numbers successfully." << std::endl;
        
        // expected shortest: 3, longest: 29997
        std::cout << "shortest span: " << massive_span.shortestSpan() << std::endl;
        std::cout << "longest span: " << massive_span.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "error: " << e.what() << std::endl;
    }

    std::cout << "\n--- test 3: exception handling ---" << std::endl;
    Span tiny_span(1);
    tiny_span.addNumber(42);
    
    try {
        tiny_span.addNumber(43); // should throw
    } catch (const std::exception& e) {
        std::cerr << "caught full span: " << e.what() << std::endl;
    }
    
    try {
        tiny_span.shortestSpan(); // should throw
    } catch (const std::exception& e) {
        std::cerr << "caught not enough numbers: " << e.what() << std::endl;
    }

    return 0;
}