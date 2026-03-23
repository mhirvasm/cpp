#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
    this->_name = "unnamed";
    ClapTrap::_name =  _name + "_clap_name";
    std::cout << "DiamondTrap default constructor is called\n";

    this->_hitpoints = 100;    // FragTrapin value
    this->_energypoints = 50;  // ScavTrapin value
    this->_attackdmg = 30;     // FragTrapin value
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
    this->_name = name;
    ClapTrap::_name = name + "_clap_name";
    std::cout << "DiamondTrap constructor is called for:" << this->_name << "\n";

    this->_hitpoints = 100;    // FragTrapin value
    this->_energypoints = 50;  // ScavTrapin value
    this->_attackdmg = 30;     // FragTrapin value
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    this->_name = other._name;
    std::cout << "Diamond copy constructor called!\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << "DiamondTrap copy assighnment operator called\n";
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->_name = other._name;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called for: " << this->_name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << this->_name << " and ClapTrap(parent) name: " << ClapTrap::_name << std::endl;
}