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

