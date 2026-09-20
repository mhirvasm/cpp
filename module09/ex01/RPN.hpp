#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <exception>

class RPN {
private:
    std::stack<int> _operands;

    // private helpers for executing the math
    bool _isOperator(const std::string& token) const;
    void _executeOperation(const std::string& op);
    void _clearStack();

public:
    // orthodox canonical form
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& rhs);
    ~RPN();

    // core execution logic
    void calculate(const std::string& expression);

    // standard exception for all malformed inputs
    class ErrorException : public std::exception {
    public:
        virtual const char* what() const noexcept override;
    };
};

#endif