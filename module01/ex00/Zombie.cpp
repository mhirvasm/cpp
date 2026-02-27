#include "Zombie.hpp"

Zombie::Zombie()
{
    
}

Zombie::~Zombie()
{
    std::cout << this->_name << " is destroyed." << std::endl;
}
void Zombie::set_zombie_name(std::string zombie_name)
{
    this->_name = zombie_name;
}

void    Zombie::announce(void)
{
    std::cout << this->_name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}