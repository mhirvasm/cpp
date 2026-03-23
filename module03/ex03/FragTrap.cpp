#include "FragTrap.hpp"

    FragTrap::FragTrap() : ClapTrap()
    {
        this->_name = "Unnamed";
        this->_hitpoints = 100;
        this->_energypoints = 100;
        this->_attackdmg = 30;
        std::cout << "FragTrap default constructor is called\n";
    }
    
    FragTrap::FragTrap(std::string name) : ClapTrap(name)
    {
        this->_hitpoints = 100;
        this->_energypoints = 100;
        this->_attackdmg = 30;
        std::cout << "FragTrap constructor is called for:" << this->_name << "\n";
    }

    FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
    {
        std::cout << "FragTrap copy constructor is called\n";
    }

    FragTrap& FragTrap::operator=(const FragTrap& other)
    {
        std::cout << "FragTrap copy assignment operator called\n";
        if (this != &other)
        {
            ClapTrap::operator=(other);
            
        }
        return (*this);
    }

    FragTrap::~FragTrap()
    {
        std::cout << "FragTrap destructor called for: " << this->_name << std::endl;
    }
    
    void FragTrap::highFivesGuys(void)
    {
        std::cout << this->_name << " FragTrap highfives! 🙏🏼"  << std::endl;
    }