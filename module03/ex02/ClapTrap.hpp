#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    protected: // we change this from private  to protected, so we unlock these attributes
            std::string _name;
            int         _hitpoints;
            int         _energypoints;
            int         _attackdmg;

    public:
            ClapTrap();
            ClapTrap(std::string name);
            ClapTrap(const ClapTrap& other);
            ClapTrap& operator=(const ClapTrap& other);
            void attack(const std::string& target);
            void takeDamage(unsigned int amount);
            void beRepaired(unsigned int amount);

            
            ~ClapTrap();
};

# endif
