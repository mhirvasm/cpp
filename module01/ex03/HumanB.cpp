#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{
    this->_name = name; 
    this->_weapon = NULL;
}
void HumanB::setWeapon(const Weapon& weapon)
{
    this->_weapon = &weapon;
}
void HumanB::attack(void) const
{
    if (this->_weapon != NULL)
        std::cout << this->_name <<" attacks with their weapon " <<  this->_weapon->getType() << std::endl;
    else //if no weapon
        std::cout << this->_name <<" attacks with their BARE hands!! " << std::endl;
}