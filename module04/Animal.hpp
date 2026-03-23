#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
             std::string _type;   
    public:
            //big four
            Animal();
            Animal(const Animal& other);
            Animal& operator=(const Animal& other);
            ~Animal();

            virtual void makeSound();
            void setType(); //setter
            void getType(); //getter
};

#endif