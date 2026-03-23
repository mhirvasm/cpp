#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    std::cout << "\n===== BUILDING FRAGTRAP =====" << std::endl;
    
    FragTrap fraggy("Fraggy");

    std::cout << "\n===== ACTION PHASE =====" << std::endl;
    fraggy.attack("a wooden target");
    
    fraggy.takeDamage(50); // Drops to 50 HP
    fraggy.beRepaired(50); // Heals back to 100 HP

    std::cout << "\n===== SPECIAL ABILITY =====" << std::endl;
    
    fraggy.highFivesGuys();

    std::cout << "\n===== OCF TESTING =====" << std::endl;
    FragTrap clone(fraggy); // Testing deep copy
    FragTrap clone2 = clone; // testing copy assignment

    std::cout << "\n===== DESTRUCTION PHASE =====" << std::endl;
    
    return (0);
}