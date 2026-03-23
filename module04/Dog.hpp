#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
class Dog : public Animal
{
    public:
        //big 4
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();
        void makeSound() override;
};

#endif