#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <cctype>

// default constructor
RPN::RPN() {}

// copy constructor
RPN::RPN(const RPN& other) : _operands(other._operands) {}

// assignment operator
RPN& RPN::operator=(const RPN& rhs) {
    if (this != &rhs) {
        _operands = rhs._operands;
    }
    return *this;
}

// destructor
RPN::~RPN() {}

// clears stack state in case the same object is used for multiple calculations
void RPN::_clearStack() {
    while (!_operands.empty()) {
        _operands.pop();
    }
}

// verifies if token is a valid math operator
bool RPN::_isOperator(const std::string& token) const {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

// extracts the top two operands and executes the calculation
void RPN::_executeOperation(const std::string& op) {
    // an operator requires exactly two operands
    if (_operands.size() < 2) {
        throw ErrorException();
    }

    // right operand is popped first due to lifo structure
    int right = _operands.top();
    _operands.pop();
    
    // left operand is popped second
    int left = _operands.top();
    _operands.pop();

    int result = 0;

    if (op == "+") result = left + right;
    else if (op == "-") result = left - right;
    else if (op == "*") result = left * right;
    else if (op == "/") {
        if (right == 0) throw ErrorException(); // prevent division by zero crash
        result = left / right;
    }

    // push the result back onto the stack for the next operation
    _operands.push(result);
}

// parses the string and processes tokens
void RPN::calculate(const std::string& expression) {
    _clearStack();
    std::stringstream ss(expression);
    std::string token;

    // extract tokens separated by spaces
    while (ss >> token) {
        // if token is a single digit (0-9)
        if (token.length() == 1 && std::isdigit(token[0])) {
            _operands.push(token[0] - '0'); // convert char to int and push
        }
        // if token is an operator
        else if (_isOperator(token)) {
            _executeOperation(token);
        }
        // anything else is a malformed formula
        else {
            throw ErrorException();
        }
    }

    // after parsing, exactly one value (the final result) must remain
    if (_operands.size() != 1) {
        throw ErrorException();
    }

    std::cout << _operands.top() << "\n";
}

// error message output
const char* RPN::ErrorException::what() const noexcept {
    return "Error";
}