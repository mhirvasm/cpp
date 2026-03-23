#include "ScavTrap.hpp"

    ScavTrap::ScavTrap() : ClapTrap()
    {
        this->_name = "Unnamed";
        this->_hitpoints = 100;
        this->_energypoints = 50;
        this->_attackdmg = 20;
        std::cout << "ScavTrap default constructor is called\n";
    }

    ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
    {
        this->_hitpoints = 100;
        this->_energypoints = 50;
        this->_attackdmg = 20;
        std::cout << "ScavTrap constructor is called for:" << this->_name << "\n";
    }
    
    ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
    {  
        std::cout << "ScavTrap copy constructor is called\n";
    }
    ScavTrap& ScavTrap::operator=(const ScavTrap& other)
    {
        std::cout << "ScavTrap copy assignment operator called\n";
        if (this != &other)
        {
            ClapTrap::operator=(other);
            
        }
        return (*this);
    }
    
    ScavTrap::~ScavTrap()
    {
        std::cout << "ScavTrap destructor called for: " << this->_name << std::endl;
    }

    void ScavTrap::attack(const std::string& target)
    {
        if (this->_hitpoints == 0)
    {
        std::cout << "ScavTrap " << this->_name << " is already dead.\n";
        return ;
    }
    if (this->_energypoints == 0)
    {
        std::cout << this->_name << " has no energy left.\n";
        return ;
    }
    std::cout << "Scavtrap " << this->_name << " attacks " << target
    << " causing " << this->_attackdmg << " points of damage!\n";
    _energypoints--;

    }
    void ScavTrap::guardGate()
    {
        std::cout << "ScavTrap " << this->_name << " is in Gate keeping mode.\n";
    }