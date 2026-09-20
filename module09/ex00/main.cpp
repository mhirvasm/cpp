#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
    // strictly one argument required
    if (argc != 2) {
        std::cerr << "error: could not open file.\n";
        return 1;
    }

    try {
        // instantiation automatically parses data.csv
        BitcoinExchange btc;
        
        // executes the lookup algorithm on the user's file
        btc.processInput(argv[1]);
    } 
    catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }

    return 0;
}