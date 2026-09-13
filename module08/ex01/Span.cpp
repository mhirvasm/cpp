#include "Span.hpp"
#include <algorithm>
#include <limits>

// default constructor
Span::Span() : _max_size(0) {}

// parameterized constructor
Span::Span(unsigned int n) : _max_size(n) {}

// copy constructor
Span::Span(const Span& other) : _max_size(other._max_size), _numbers(other._numbers) {}

// assignment operator
Span& Span::operator=(const Span& rhs) {
    if (this != &rhs) {
        _max_size = rhs._max_size;
        _numbers = rhs._numbers;
    }
    return *this;
}

// destructor
Span::~Span() {}

// adds a single number, throws if capacity is reached
void Span::addNumber(int number) {
    if (_numbers.size() >= _max_size) {
        throw span_full_exception();
    }
    _numbers.push_back(number);
}

// calculates the shortest span between any two numbers
int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw not_enough_numbers_exception();
    }

    // copy the vector to maintain const correctness of the object
    std::vector<int> sorted = _numbers;
    
    // sort the copy in ascending order
    std::sort(sorted.begin(), sorted.end());

    int min_span = std::numeric_limits<int>::max();

    // iterate and compare adjacent elements
    for (size_t i = 0; i < sorted.size() - 1; ++i) {
        int current_span = sorted[i + 1] - sorted[i];
        if (current_span < min_span) {
            min_span = current_span;
        }
    }

    return min_span;
}

// calculates the longest span between any two numbers
int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw not_enough_numbers_exception();
    }

    // std::minmax_element returns a pair of iterators pointing to min and max
    auto result = std::minmax_element(_numbers.begin(), _numbers.end());
    
    // dereference the iterators to get the actual integer values
    return *result.second - *result.first;
}