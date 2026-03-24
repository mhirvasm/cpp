#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
class Cat : public Animal
{
    public:
            //big 4
            Cat();
            Cat(const Cat& other);
            Cat& operator=(const Cat& other);
            ~Cat();
            void makeSound() const override;
};

#endif