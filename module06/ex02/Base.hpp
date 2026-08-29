#ifndef BASE_HPP
#define BASE_HPP

class Base {
public:
    // Virtual destructor is mandatory to enable RTTI for dynamic_cast
    virtual ~Base() = default;
};

#endif