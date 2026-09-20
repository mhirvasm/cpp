#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <exception>

class BitcoinExchange {
private:
    std::map<std::string, double> _database;

    // private helper functions for internal logic
    void _loadDatabase(const std::string& db_path);
    bool _isValidDate(const std::string& date) const;
    bool _isValidValue(const std::string& value_str, double& out_value) const;
    bool _isLeapYear(int year) const;

public:
    // orthodox canonical form
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& rhs);
    ~BitcoinExchange();

    // core execution method
    void processInput(const std::string& file_path) const;

    // custom exception for fatal file errors
    class FileException : public std::exception {
    public:
        virtual const char* what() const noexcept override;
    };
};

#endif