#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
        {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("flowers");
        bob.attack();
        std::cout << std::endl;
        }
        {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.attack();
        jim.setWeapon(club);
        jim.attack();
        club.setType("bazooka");
        jim.attack();
        club.setType(""); //type is not changed if its not specified
        jim.attack();
        }
    
    return 0;
}