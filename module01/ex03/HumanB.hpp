#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include "Weapon.hpp"
#include <iostream>

class HumanB
{
    private:
            std::string _name;
            Weapon* _weapon; //Use the pointer, so object can be "unarmed" or weapon "changed"

    public:
            HumanB(std::string name);
            void setWeapon(Weapon& weapon);
            void attack(void); 
};

#endif