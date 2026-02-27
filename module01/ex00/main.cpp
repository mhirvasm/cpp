#include "Zombie.hpp"

int main(void)
{
    Zombie *zombie;

    zombie = newZombie("Heaper");
    randomChump("Stacker");

    zombie->announce();
    delete zombie;
}