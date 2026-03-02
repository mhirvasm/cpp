#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
    private:
            std::string name;

    public:
            HumanB(std::string name); // create constructor function
            setWeapon(Weapon weapon); // create this function 
            attack(void); //create attack function

};

#endif