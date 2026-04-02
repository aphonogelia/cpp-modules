/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:04:51 by htharrau          #+#    #+#             */
/*   Updated: 2026/04/02 17:34:41 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& filename) {
    loadDict();
    loadInput(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _data = other._data;
        _input = other._input;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
}

void BitcoinExchange::loadDict() {
    std::ifstream file("data.csv");
    if (!file.is_open()) {
        std::cerr << "[Error] [data.csv] Could not open file: data.csv" << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // skip header
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, rateString;
        double rate;

        if (std::getline(iss, date, ',') && std::getline(iss, rateString)) {
            std::istringstream converter(rateString);
            if (!(converter >> rate))
                std::cerr << "[Error] [data.csv] Invalid rate in line: " << line << std::endl;
            else
                _data[date] = rate;
        } else {
            std::cerr << "[Error] [data.csv] Invalid line format: " << line << std::endl;
        }
    }
    file.close();
    printMap(_data);

}

void BitcoinExchange::loadInput(const std::string& inputFile) {
    std::ifstream file(inputFile.c_str());
    if (!file.is_open()) {
        std::cerr << "[Error] [input.txt] Could not open file: " << inputFile << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // skip header
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        char pipe;
        double rate;

        if (iss >> date >> pipe >> rate) {
            _input.insert(std::make_pair(date, rate));
            handleLine(date, rate);
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
    file.close();
    // printMultimap(_input);
}

void BitcoinExchange::handleLine(const std::string& date, const double rate) const{
    if (rate < 0) {
        std::cerr << "Error: not a positive number => " << rate << std::endl;
        return;
    }
    else if (rate > 1000) {
        std::cout << "Error: too large a number => " << rate << std::endl;
        return;
    }
    else if (!validDate(date)) {
        std::cout << "Error: invalid date => " << date << std::endl;
        return;
    }
    double exchangeRate = getExchangeRate(date);
    std::cout << date << "| " << rate << " => " << rate * exchangeRate << std::endl;
}
bool BitcoinExchange::validDate(const std::string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    std::istringstream y(date.substr(0, 4));
    std::istringstream m(date.substr(5, 2));
    std::istringstream d(date.substr(8, 2));

    int year, month, day;
    if (!(y >> year) || !(m >> month) || !(d >> day))
        return false;

    if (year < 2009 || month < 1 || month > 12 || day < 1)
        return false;

    // days per month
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // leap year: feb gets 29
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29;

    if (day > daysInMonth[month - 1])
        return false;

    // reject future dates
    time_t now = time(0);
    struct tm* today = localtime(&now);
    char buf[11];
    strftime(buf, sizeof(buf), "%Y-%m-%d", today);
    if (date > std::string(buf))
        return false;

    return true;
}
double BitcoinExchange::getExchangeRate(const std::string& date) const {
    std::map<std::string, double>::const_iterator it = _data.lower_bound(date);
    
    // exact match
    if (it != _data.end() && it->first == date)
        return it->second;
    
    // no earlier date exists
    if (it == _data.begin()) {
        std::cerr << "Error: no data for this date => " << date << std::endl;
        return -1;
    }
    
    // use closest earlier date
    --it;
    return it->second;
}

void BitcoinExchange::printMap(const std::map<std::string, double>& myMap) const {
    for (std::map<std::string, double>::const_iterator it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}


void BitcoinExchange::printMultimap(const std::multimap<std::string, double>& myMap) const {
    for (std::multimap<std::string, double>::const_iterator it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}