#include "HumanA.hpp"
#include "Weapon.hpp"

//intialization list is used after ":"
HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
    //we cant use here the this-> syntax, because the reference must be created at the sametime as the object is created
}
void HumanA::attack(void)
{
    std::cout << this->_name <<" attacks with their weapon " << this->_weapon.getType()  << std::endl;
}