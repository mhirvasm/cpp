#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
{
    this->_name = name;
    this->_weapon = weapon;
    
}