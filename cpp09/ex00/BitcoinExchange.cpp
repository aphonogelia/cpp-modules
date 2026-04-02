/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:04:51 by htharrau          #+#    #+#             */
/*   Updated: 2026/04/02 13:39:56 by htharrau         ###   ########.fr       */
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
        } else {
            std::cerr << "[Error] [input.txt] Invalid line format: " << line << std::endl;
        }
    }
    file.close();
    printMultimap(_input);
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