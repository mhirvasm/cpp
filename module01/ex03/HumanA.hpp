#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
    private:
            std::string name;
            Weapon& weapon; //Use the reference, because object is constructed with specific weapon

    public:
            HumanA(std::string name, Weapon weapon); //create constructor function
            void attack(void); //create attack function

};

#endif