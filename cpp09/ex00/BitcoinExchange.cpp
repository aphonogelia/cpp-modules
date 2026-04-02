/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:04:51 by htharrau          #+#    #+#             */
/*   Updated: 2026/04/02 13:29:14 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// bool evaluate(const std::string& input) {

//     std::istringstream iss(input);
//     std::string token;

//     while (iss >> token) {
//         if (token.length() != 1) {
//             std::cerr << "[Error] Invalid token: " << token << std::endl;
//             return false;
//         }

//         char c = token[0];
//     }
//     return true;
// }



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
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, separator, rateString;
        double rate;

        if (iss >> date >> separator >>rateString) {

            std::istringstream converter(rateString);
            if (!(converter >> rate))
                std::cerr << "[Error] [data.csv] Invalid rate in line: " << line << std::endl;
            else
                _data[date] = rate;
        }
        else {
            std::cerr << "[Error] [data.csv] Invalid line format: " << line << std::endl;
        }
    }
    file.close();
    printMap(_data);

}


void BitcoinExchange::loadInput(const std::string& inputFile) {
    std::ifstream file(inputFile.c_str());
    if (!file.is_open()) {
        std::cerr << "[Error] [" << inputFile << "] Could not open file: " << inputFile << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, rateString;
        double rate;


        if (std::getline(iss, date, '|') && std::getline(iss, rateString)) {
            std::istringstream converter(rateString);
            if (!(converter >> rate))
                std::cerr << "[Error] [" << inputFile << "] Invalid rate in line: " << line << std::endl;
            else
                _input[date] = rate;
        }
        else {
            std::cerr << "[Error] [" << inputFile << "] Invalid line format: " << line << std::endl;
        }
    }
    printMap(_input);
    file.close();
}

void BitcoinExchange::printMap(const std::map<std::string, double>& myMap) const {
    for (std::map<std::string, double>::const_iterator it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}
