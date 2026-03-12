#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    private:
            std::string _name;
            int         _hitpoints;
            int         _energypoints;
            int         _attackdmg;

    protected:

    public:
            ClapTrap();
            ClapTrap(std::string name); //constructor which sets up name
            ClapTrap(const ClapTrap& other); //copyconstructor
            ClapTrap& operator=(const ClapTrap& other);
            void attack(const std::string& target);
            void takeDamage(unsigned int amount);
            void beRepaired(unsigned int amount);

            // getters and setters?
            ~ClapTrap();
};

# endif
