#include "Zombie.hpp"

int main(void)
{
    Zombie *horde;
    
    horde = zombieHorde(50, "Bob");

    for (int i = 0; i < 50; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
}