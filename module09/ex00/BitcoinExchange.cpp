#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>

// default constructor automatically loads the mandatory database
BitcoinExchange::BitcoinExchange() {
    _loadDatabase("data.csv");
}

// copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database) {}

// assignment operator
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
    if (this != &rhs) {
        _database = rhs._database;
    }
    return *this;
}

// destructor
BitcoinExchange::~BitcoinExchange() {}

// loads historical bitcoin data into the std::map
void BitcoinExchange::_loadDatabase(const std::string& db_path) {
    std::ifstream file(db_path.c_str());
    if (!file.is_open()) {
        throw FileException();
    }

    std::string line;
    // skip the first header line ("date,exchange_rate")
    std::getline(file, line);

    while (std::getline(file, line)) {
        size_t delim_pos = line.find(',');
        if (delim_pos == std::string::npos) {
            continue; // skip malformed database lines
        }

        std::string date = line.substr(0, delim_pos);
        std::string rate_str = line.substr(delim_pos + 1);
        
        // convert string to double using stringstream for c++98 safety
        std::stringstream ss(rate_str);
        double rate;
        ss >> rate;

        // map automatically sorts elements by date (the key)
        _database[date] = rate;
    }
    file.close();
}

// core logic: reads input file, validates, and calculates values
void BitcoinExchange::processInput(const std::string& file_path) const {
    std::ifstream file(file_path.c_str());
    if (!file.is_open()) {
        std::cerr << "error: could not open file.\n";
        return;
    }

    std::string line;
    // skip the header line ("date | value")
    std::getline(file, line);

    while (std::getline(file, line)) {
        // find the delimiter
        size_t delim_pos = line.find(" | ");
        if (delim_pos == std::string::npos) {
            std::cerr << "error: bad input => " << line << "\n";
            continue;
        }

        std::string date = line.substr(0, delim_pos);
        std::string value_str = line.substr(delim_pos + 3);
        double value;

        // validate date format and real-world existence
        if (!_isValidDate(date)) {
            std::cerr << "error: bad input => " << date << "\n";
            continue;
        }

        // validate value boundaries (0 to 1000)
        if (!_isValidValue(value_str, value)) {
            continue;
        }

        // the algorithm: search the map using lower_bound
        std::map<std::string, double>::const_iterator it = _database.lower_bound(date);

        // if the date is earlier than the very first date in our database
        if (it == _database.begin() && it->first != date) {
            std::cerr << "error: no historical data available for date => " << date << "\n";
            continue;
        }

        // if exact match is not found, step back one iterator to get the closest lower date
        if (it == _database.end() || it->first != date) {
            --it;
        }

        // output format requested by the subject
        std::cout << date << " => " << value << " = " << (value * it->second) << "\n";
    }
    file.close();
}

// checks for exact yyyy-mm-dd format and valid calendar days
bool BitcoinExchange::_isValidDate(const std::string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }

    std::stringstream ss(date);
    int year, month, day;
    char dash1, dash2;

    ss >> year >> dash1 >> month >> dash2 >> day;

    if (ss.fail() || !ss.eof()) return false;
    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31) return false;

    // handle months with 30 days
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;

    // handle february and leap years
    if (month == 2) {
        bool leap = _isLeapYear(year);
        if (day > (leap ? 29 : 28)) return false;
    }

    return true;
}

// simple leap year math
bool BitcoinExchange::_isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// checks if the value is a valid positive number between 0 and 1000
bool BitcoinExchange::_isValidValue(const std::string& value_str, double& out_value) const {
    char* endptr;
    out_value = std::strtod(value_str.c_str(), &endptr);

    // check if conversion failed completely or left trailing garbage characters
    if (value_str.c_str() == endptr || *endptr != '\0') {
        std::cerr << "error: not a number.\n";
        return false;
    }
    if (out_value < 0) {
        std::cerr << "error: not a positive number.\n";
        return false;
    }
    if (out_value > 1000.0) {
        std::cerr << "error: too large a number.\n";
        return false;
    }

    return true;
}

const char* BitcoinExchange::FileException::what() const noexcept {
    return "fatal error: could not open database file (data.csv).";
}