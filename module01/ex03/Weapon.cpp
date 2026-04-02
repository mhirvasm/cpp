#include "Weapon.hpp"
#include <string>

Weapon::Weapon() : _type("default weapon") 
{
    
}

Weapon::Weapon(std::string type) :
_type(type)
{

}

const std::string& Weapon::getType(void) const
{
    return (this->_type);
}
void Weapon::setType(std::string type)
{
    // if given empty string, then nothing is changed
    if (type.empty())
        return ;
    this->_type = type;
}