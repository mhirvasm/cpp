#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

// mutantstack inherits from std::stack
template <typename T>
class MutantStack : public std::stack<T> {
public:
    // orthodox canonical form
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack& other) : std::stack<T>(other) {}
    MutantStack& operator=(const MutantStack& rhs) {
        if (this != &rhs) {
            std::stack<T>::operator=(rhs);
        }
        return *this;
    }
    ~MutantStack() {}

    // modern c++ type aliases for iterators
    // std::stack defines 'container_type' as the type of 'c'
    using iterator = typename std::stack<T>::container_type::iterator;
    using const_iterator = typename std::stack<T>::container_type::const_iterator;
    using reverse_iterator = typename std::stack<T>::container_type::reverse_iterator;
    using const_reverse_iterator = typename std::stack<T>::container_type::const_reverse_iterator;

    // iterator methods accessing the protected underlying container 'c'
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }

    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }

    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }

    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif