#include <iostream> //basic input output
#include <fstream> // filemanipulation
#include <string> //string manipulation 
#include <cstring>

int main(int argc, char **argv)
{
    //check for valid count of parameters
    if (argc != 4)
    {
        std::cerr << "Error: Wrong argument count. \n Should be: filename + string1 + string2" << std::endl;
        return (1);
    }
    //parse parameters
    std::string fileName = argv[1]; // grab filename
    std::string file2Name = fileName + ".replace";
    std::string string1 = argv[2]; // grab string1 
    std::string string2 = argv[3]; // grab string2
    std::string myText; // text variable to catch lines

    //Checking that the strings given are not empty
    if (string1.empty() || string2.empty())
    {
        std::cerr << "Error: string1 or string2 is empty" << std::endl;
        return (1);
    }
    //We open the file, if there is no file this should also create it.
    std::ifstream MyFile(fileName); //ifstream to first try to just read from a file
    if (!MyFile.is_open()) //Check for file opening
    {
        std::cout << "File not found. Created file: " << fileName  << std::endl;
        std::ofstream writeStream(fileName); // Here we create the file.
        if (!writeStream.is_open()) //always check after creating a file that its opened.
        {
            std::cerr << "Error: Opening file " << fileName << " failed." << std::endl;
            return (1);
        }
        std::cout << "Writing into a file. Type 'EXIT' to stop writing into the file." << std::endl;
        while(!!true)
        {
            std::cout << "Writing into the file:"; //prompt
            std::getline(std::cin, myText); //gettin the line
            if (myText == "EXIT") // check for stop writing
                break ;
            writeStream << myText << "\n";
        }
        writeStream.close();

        MyFile.clear(); // Reset error flags, so stream can be used again.
        MyFile.open(fileName); // Open the file, lets use the same variable
    }
    std::ofstream MyFile2(file2Name); // Here we create the second file.
    if (!MyFile2.is_open() || !MyFile.is_open()) //always check after creating a file that its opened.
    {
        std::cerr << "Error: Opening file " << std::endl;
        return (1);
    }
    //Now we need to read from 1st file, take a line, if there is occurance
    //if there is, we use remove, and then add. and then we add position the len of str2
    std::string currentStr;
    std::string modified;
    std::size_t position;
    //std::size_t position = 0;
    
    while(getline(MyFile, currentStr))
    {
        //std::cout << currentStr << std::endl; //print test
        position = currentStr.find(string1);
        while(position != std::string::npos)
        {
            currentStr.erase(position, string1.length()); //erase the 
            currentStr.insert(position, string2);
            position += string2.length();
            position = currentStr.find(string1);
        }
        MyFile2 << currentStr << "\n";
    }

    return 0;
}