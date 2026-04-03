/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:04:51 by htharrau          #+#    #+#             */
/*   Updated: 2026/04/03 14:57:45 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& filename) {
    if (loadDict()) loadInput(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _data = other._data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
}



bool BitcoinExchange::loadDict() {

    std::ifstream file("data.csv");
    if (!file.is_open()) {
        std::cerr << "[Error] [data.csv] Could not open file: data.csv" << std::endl;
        return false;
    }

    std::string line;
    std::getline(file, line); // skip header
    size_t lineNb = 2;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, rateString;
        double rate;
        if (!(std::getline(iss, date, ',') && std::getline(iss, rateString))) {
            std::cerr << "[Error] [data.csv] Invalid line format " << lineNb << ": " << line << std::endl;
            return false;
        }
        std::istringstream converter(rateString);
        if (!(converter >> rate) || rate < 0) {
            std::cerr << "[Error] [data.csv] Invalid rate in line " << lineNb << ": " << line << std::endl;
            return false;
        }
        else if (!validDate(date, false)) {
            std::cout << "[Error] [data.csv] Invalid date in line " << lineNb << ": " << line << std::endl;
            return false;
        }
        _data[date] = rate;
        lineNb++;
    }
    file.close();
    return true;
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

        if (iss >> date >> pipe >> rate && (pipe == '|')) {
            handleLine(date, rate);
        }
        else {
            std::cerr << "Error: bad input (" << line << ")" << std::endl;
        }
    }
    file.close();
}

void BitcoinExchange::handleLine(const std::string& date, const double rate) const {
    if (rate < 0) {
        std::cerr << "Error: not a positive number (" << rate << ")" << std::endl;
        return;
    }
    else if (rate > 1000) {
        std::cout << "Error: too large a number (" << rate << ")" << std::endl;
        return;
    }
    else if (!validDate(date, true)) {
        return;
    }
    std::cout << date << " | " << rate << " => " << rate * getExchangeRate(date) << std::endl;
}


bool BitcoinExchange::validDate(const std::string& date, const bool &error) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        std::cout << "Error: invalid date (" << date << ")" << std::endl;
        return false;
    }

    std::istringstream y(date.substr(0, 4));
    std::istringstream m(date.substr(5, 2));
    std::istringstream d(date.substr(8, 2));

    int year, month, day;
    if (!(y >> year) || !(m >> month) || !(d >> day)) {
        if (error) std::cout << "Error: invalid date (" << date << ")" << std::endl;
        return false;
    }

    if (month < 1 || month > 12 || day < 1) {
        if (error) std::cout << "Error: invalid date (" << date << ")" << std::endl;
        return false;
    }

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29;
    if (day > daysInMonth[month - 1]) {
        if (error) std::cout << "Error: invalid date (" << date << ")" << std::endl;
        return false;
    }

    // reject dates before first entry in data
    if (!_data.empty() && date < _data.begin()->first) {
        if (error) std::cout << "Error: no rate for this date (" << date << ")" << std::endl;
        return false;
    }

    // reject dates that are in the future
    time_t now = time(0);
    struct tm* today = localtime(&now);
    char buf[11];
    strftime(buf, sizeof(buf), "%Y-%m-%d", today);
    if (date > std::string(buf)) {
        std::cout << "Error: date is in the future (" << date << ")" << std::endl;
        return false;
    }

    return true;
}


// map alwayz sorted in ascending key order
double BitcoinExchange::getExchangeRate(const std::string& date) const {
    std::map<std::string, double>::const_iterator it = _data.lower_bound(date);

    if (it != _data.end() && it->first == date)
        return it->second;

    --it;
    return it->second;
}
