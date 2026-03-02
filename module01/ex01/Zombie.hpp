#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream> // input and output

class Zombie
{
    private:
            std::string _name;
    
    public:
            Zombie(); //constructor
            ~Zombie(); //destructor
            void set_zombie_name(std::string zombie_name);
            void announce(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif