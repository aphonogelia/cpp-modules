/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:05:10 by htharrau          #+#    #+#             */
/*   Updated: 2026/04/03 14:58:10 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <fstream>
#include <ctime>

class BitcoinExchange {

private:
    std::map<std::string, double> _data;

    bool loadDict();
    void loadInput(const std::string& filename);
    void handleLine(const std::string& date, const double rate) const;
    bool validDate(const std::string& date, const bool& error) const;
    double getExchangeRate(const std::string& date) const;

public:
    BitcoinExchange(const std::string& filename);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
};
