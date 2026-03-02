#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
    private:
            std::string _name;
            Weapon* _weapon; //Use the pointer, so object can be "unarmed" or weapon "changed"

    public:
            HumanB(std::string name); // create constructor function
            void setWeapon(Weapon* weapon); // create this function 
            void attack(void); //create attack function

};

#endif