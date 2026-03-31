#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie* horde = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            horde[i].set_zombie_name("First zombie"); // just for demonstration
            i++;
        }
        horde[i].set_zombie_name(name);
    }
    return(horde);
}
