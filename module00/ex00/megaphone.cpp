/*
$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.

$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *

$>*/

//funny things in :
// statements can be split into different lines.
// maybe make the upper by moving bits? check if can
//i++, i-- initalizations 

//bool yes = !false
//bool no = !yes

#include <iostream> //input and output
#include <string> //string manipulation
#include <cctype> //toupper

std::string    stringToUpper(char *input)
{
    std::string s = input;
    for (auto& x : s)
        x = std::toupper(x);
    return (s);
}
    
int main(int argc, char **argv) 
{
    int counter = 1;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        return (0);
    }
    else
    {
        while (argv[counter])
            {
                std::string s = stringToUpper(argv[counter]);
                std::cout << s;
                counter++;
            }

    }
    return (0);

}

