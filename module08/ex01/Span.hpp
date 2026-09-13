#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>
#include <iterator>

class Span {
private:
    unsigned int _max_size;
    std::vector<int> _numbers;

public:
    // orthodox canonical form
    Span();
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& rhs);
    ~Span();

    // core functionality required by subject
    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

    // advanced: add a range of numbers using iterators
    // templated so it can accept iterators from any container type (vector, list, etc.)
    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end) {
        // calculate how many items we are trying to add
        unsigned int distance = std::distance(begin, end);
        
        // check if we have enough space left
        if (_numbers.size() + distance > _max_size) {
            throw span_full_exception();
        }
        
        // std::vector::insert is the standard way to add a range
        _numbers.insert(_numbers.end(), begin, end);
    }

    // exception classes
    class span_full_exception : public std::exception {
    public:
        virtual const char* what() const noexcept override {
            return "span is full, cannot add more numbers";
        }
    };

    class not_enough_numbers_exception : public std::exception {
    public:
        virtual const char* what() const noexcept override {
            return "not enough numbers to calculate span";
        }
    };
};

#endif