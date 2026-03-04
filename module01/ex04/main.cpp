#include <iostream> //basic input output
#include <fstream> // filemanipulation
#include <string> //string manipulation 

int main(int argc, char **argv)
{
    std::string fileName = argv[1]; //grab filename
    //check for valid count of parameters
    (void)argv;
    if (argc != 4)
    {
        std::cerr << "Error: Wrong argument count. \n Should be: filename + string1 + string2" << std::endl;
        return (1);
    }

    //We open the file, if there is no file this should also create it.
    std::ofstream MyFile(fileName); //ofstream for writing 
    if (!MyFile.is_open())
    {
        std::cerr << "Error: File open failed." << std::endl;
        return (1);
    }

    MyFile << "Here we are writing to the file, lalalalala hey!\n Here is the second line";

    //parameters are FILE + STRING1 + STRING2

    //We need to open a file, then we copy all of its content to file2.
    //Then we replace every occurance of string1 with string 2

    //we could use the find function to find the words
    //str1.substr(start, length);
    
    //with insert we can insert the string to specified location
    //str1.insert(index, str2);

    //with erase we can remove character of part of the string
    // str1.erase(start, end);

    return 0;
}