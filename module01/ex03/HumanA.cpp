#include "HumanA.hpp"
#include "Weapon.hpp"

//intialization list
HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
    //we cant use here the this-> syntax, because the reference must be created at the sametime as the object is created
}