#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

// exception class for missing values
class not_found_exception : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "value not found in container";
    }
};

// template function to find an integer in a container
template <typename T>
typename T::iterator easyfind(T& container, int value) {
    
    // std::find searches from begin to end
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    
    // if iterator equals end(), the value is not present
    if (it == container.end()) {
        throw not_found_exception();
    }
    
    // return the iterator pointing to the found value
    return it;
}

#endif