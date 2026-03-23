#include "Animal.hpp"

    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    ~Animal();

    virtual void makeSound();
    void setType(); //setter
    void getType(); //getter