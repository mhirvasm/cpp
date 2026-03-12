#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap robo;
    ClapTrap roboname("Keijo");

    roboname.attack("ville");
    roboname.beRepaired(11);
    roboname.beRepaired(1);
    roboname.beRepaired('a');
    roboname.takeDamage(-1);
    roboname.takeDamage(20);

    return (0);
}