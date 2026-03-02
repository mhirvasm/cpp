#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
    private:
            std::string name;

    public:
            HumanA(std::string name, Weapon weapon); //create constructor function
            attack(void); //create attack function

};

#endif