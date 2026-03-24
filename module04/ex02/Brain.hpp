#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
    public:
            std::string ideas[100]; //array of thoughts

            Brain();
            Brain(const Brain& other);
            Brain& operator=(const Brain& other);
            ~Brain();
};


#endif