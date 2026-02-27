#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie stack_zombie;
    stack_zombie.set_zombie_name(name);
    stack_zombie.announce();
}
