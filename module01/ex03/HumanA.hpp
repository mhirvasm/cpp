#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include "Weapon.hpp"
#include <iostream>

class HumanA
{
    private:
            std::string _name;
            const Weapon& _weapon; //Use the reference, because object is constructed with specific weapon

    public:
            HumanA(std::string name, const Weapon& weapon); //create constructor function
            void attack(void) const; //create attack function

};

#endif