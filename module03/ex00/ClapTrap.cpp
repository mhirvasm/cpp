#include "ClapTrap.hpp"


//constructor (remember display messages) and use initiationlist - 10 10 0
ClapTrap::ClapTrap(std::string name) :
_name(name),
_hitpoints(10),
_energypoints(10),
_attackdmg(0)
{
    std::cout << "ClapTrap default constructor is called with name parameter\n";
}

ClapTrap::ClapTrap() :
_name("Unnamed"),
_hitpoints(10),
_energypoints(10),
_attackdmg(0)
{
    std::cout << "ClapTrap default constructor is called\n";
}
//copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) :
_name(other._name),
_hitpoints(other._hitpoints),
_energypoints(other._energypoints),
_attackdmg(other._attackdmg)
{
    std::cout << "ClapTrap copy constructor is called\n";
}
//copy assignment
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap copy assignment operator called\n";
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitpoints = other._hitpoints;
        this->_energypoints = other._energypoints;
        this->_attackdmg = other._attackdmg;
    }
    return (*this);
}
//destructor
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called for: " << this->_name << std::endl;
}
//ClapTrap <name> attacks <target>, causing <damage> points of damage!
//attack
void ClapTrap::attack(const std::string& target)
{
    if (this->_hitpoints == 0)
    {
        std::cout << "ClaptTrap " << this->_name << " is already dead.\n";
        return ;
    }
    if (this->_energypoints == 0)
    {
        std::cout << this->_name << " has no energy left.\n";
        return ;
    }
    std::cout << "Claptrap " << this->_name << " attacks " << target
    << " causing " << this->_attackdmg << " points of damage!\n";
    _energypoints--;
}

//takedamage
void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitpoints == 0)
    {
        std::cout << "ClaptTrap " << this->_name << " is already dead.\n";
        return ;
    }
    if ((unsigned int)this-> _hitpoints <= amount)
        this->_hitpoints = 0;
    else
        this->_hitpoints = this->_hitpoints - amount;
    
    std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage\n";
    if (this->_hitpoints == 0)
    {
        std::cout << "ClaptTrap " << this->_name << " died.\n";
        return ;
    }
}
//berepaired
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energypoints == 0)
    {
        std::cout << this->_name << " has no energy left.\n";
        return ;
    }
    else
    {
        _hitpoints = _hitpoints + amount;
        std::cout << _name << " healed " << amount << " and has now " << _hitpoints << " health!\n";
        _energypoints--;
        return ;
    }
}