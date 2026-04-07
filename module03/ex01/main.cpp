#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

    //ex01 tests
    std::cout << "\n===== BUILDING PHASE =====" << std::endl;

    ClapTrap baseRobot("Clappy");
    ScavTrap scavvy("Scavvy");

    std::cout << "\n===== ACTION PHASE =====" << std::endl;
    baseRobot.attack("Target A");
    scavvy.attack("Target B");

    std::cout << "\n===== INHERITANCE PHASE =====" << std::endl;
    scavvy.takeDamage(50); // HP from 100 to 50
    std::cout << "^It says ClapTrap, beacuse we inherit the the takeDamage function from clapTrap\n";
    scavvy.beRepaired(20); // HP increases from 50 to 70

    std::cout << "\n===== SPECIAL ABILITY PHASE =====" << std::endl;
    scavvy.guardGate();
    std::cout << "\n===== DESTRUCTION PHASE =====" << std::endl;

    return (0);
}