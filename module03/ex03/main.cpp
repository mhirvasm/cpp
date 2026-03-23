#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "\n\033[36m===== 1. BUILDING PHASE (VIRTUAL INHERITANCE) =====\033[0m\n" << std::endl;
    DiamondTrap diamond("Monster");

    std::cout << "\n\033[36m===== 2. ACTION & STATS PHASE =====\033[0m\n" << std::endl;
    diamond.attack("a poor training dummy");
    
    // HP initalized to 100
    diamond.takeDamage(50);
    
    diamond.beRepaired(25);

    std::cout << "\n\033[36m===== 3. SPECIAL ABILITIES PHASE =====\033[0m\n" << std::endl;
    
    // Printing names
    std::cout << "--> Testing whoAmI:" << std::endl;
    diamond.whoAmI();
    
    // Inherited from scavtrap
    std::cout << "--> Testing guardGate:" << std::endl;
    diamond.guardGate();
    
    // inherited  from FragTrap
    std::cout << "--> Testing highFivesGuys:" << std::endl;
    diamond.highFivesGuys();

    std::cout << "\n\033[36m===== 4. OCF (CLONING & ASSIGNMENT) =====\033[0m\n" << std::endl;
    
    // Testing copy constructor
    std::cout << "--> Cloning Monster into Clone..." << std::endl;
    DiamondTrap clone(diamond);
    std::cout << "Clone identifies as: ";
    clone.whoAmI(); // should print same as og

    // testing copy constructor
    std::cout << "\n--> Creating Unnamed and overwriting with Clone..." << std::endl;
    DiamondTrap assigned;
    assigned = clone;
    std::cout << "Assigned identifies as: ";
    assigned.whoAmI(); // should also print parnt parent

    std::cout << "\n\033[36m===== 5. DESTRUCTION PHASE =====\033[0m\n" << std::endl;
    return (0);
}