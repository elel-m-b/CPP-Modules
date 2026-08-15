#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cctype>

BitcoinExchange::BitcoinExchange()
{
    loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): _database(other._database)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _database = other._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::isWhitespace(char c) const
{
    return std::isspace(static_cast<unsigned char>(c)) != 0;
}

std::string BitcoinExchange::trim(const std::string &str) const
{
    std::string::size_type start = 0;
    std::string::size_type end = str.size();

    while (start < end && isWhitespace(str[start]))
        ++start;

    while (end > start && isWhitespace(str[end - 1]))
        --end;

    return str.substr(start, end - start);
}

bool BitcoinExchange::isLeapYear(int year) const
{
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    return (year % 4 == 0);
}

int BitcoinExchange::daysInMonth(int year, int month) const
{
    if (month == 2){
        if (isLeapYear(year))
            return 29;
        return 28;
    }
    if (month == 4 ||month == 6 ||month == 9||month == 11)
        return 30;
    return 31;
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.size() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 10; ++i){
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 1)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > daysInMonth(year, month))
        return false;
    return true;
}

bool BitcoinExchange::isValidValue(const std::string &value) const
{
    if (value.empty())
        return false;

    char *end;
    errno = 0;

    const char *str = value.c_str();
    double number = std::strtod(str, &end);

    while (*end != '\0' && std::isspace(static_cast<unsigned char>(*end)))
        ++end;

    if (*end != '\0')
        return false;

    if (errno == ERANGE)
        return false;

    if (number < 0)
        return false;

    if (number > 1000)
        return false;

    return true;
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
    {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }

    std::string line;

    if (!std::getline(file, line))
    {
        std::cerr << "Error: empty database." << std::endl;
        return;
    }

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        std::string::size_type comma = line.find(',');

        if (comma == std::string::npos)
            continue;

        std::string date = trim(line.substr(0, comma));
        std::string rateString = trim(line.substr(comma + 1));

        if (!isValidDate(date))
            continue;

        char *end;
        errno = 0;

        double rate = std::strtod(rateString.c_str(), &end);

        while (*end != '\0' && std::isspace(static_cast<unsigned char>(*end)))
            ++end;

        if (*end != '\0' || errno == ERANGE)
            continue;

        _database[date] = rate;
    }
}

void BitcoinExchange::processLine(const std::string &line) const
{
    if (line.empty())
        return;

    std::string::size_type pipe = line.find('|');

    if (pipe == std::string::npos)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }

    std::string date = trim(line.substr(0, pipe));
    std::string valueString = trim(line.substr(pipe + 1));

    if (!isValidDate(date))
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }

    if (!isValidValue(valueString))
    {
        char *end;
        errno = 0;

        double value = std::strtod(valueString.c_str(), &end);

        while (*end != '\0' && std::isspace(static_cast<unsigned char>(*end)))
            ++end;

        if (*end == '\0' && errno != ERANGE && value > 1000)
            std::cerr << "Error: too large a number." << std::endl;
        else
            std::cerr << "Error: not a positive number." << std::endl;

        return;
    }

    double value = std::strtod(valueString.c_str(), NULL);

    if (_database.empty())
    {
        std::cerr << "Error: database is empty." << std::endl;
        return;
    }

    std::map<std::string, double>::const_iterator it = _database.lower_bound(date);

    if (it == _database.end())
    {
        --it;
    }
    else if (it->first != date)
    {
        if (it == _database.begin())
        {
            std::cerr << "Error: no exchange rate available for date => "
                      << date << std::endl;
            return;
        }
        --it;
    }

    double result = value * it->second;

    std::cout << date << " => " << valueString << " = " << result<< std::endl;
}

void BitcoinExchange::processInput(const std::string &filename) const
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;

    if (!std::getline(file, line))
    {
        std::cerr << "Error: empty file." << std::endl;
        return;
    }

    if (trim(line) != "date | value")
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }

    while (std::getline(file, line))
        processLine(line);
}