#include "Harl.hpp"

void Harl::debug()
{
    std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info()
{
    std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning()
{
    std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}
void Harl::error()
{
    std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    //we create the "keys"
    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    int levelIndex = -1; 
    int numLevels = sizeof(levels) / sizeof(levels[0]);

    //loop through to get the indexLevel
    for (int i = 0; i < numLevels; i++)
    {
        if (level == levels[i])
            levelIndex = i;
            
    }
    //fall through switch
    switch (levelIndex) 
    {
        case 0:
            this->debug();
        case 1:
            this->info();
        case 2:
            this->warning();
        case 3:
            this->error();
            break;
        default:
            std::cout << "Invalid input." << std::endl;
            break;
    }
    return ;

}