#include "Weapon.hpp"
#include <string>
    
Weapon::Weapon(std::string name)
{
    this->_type = name;
}

const std::string& Weapon::getType(void)
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