/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:05:10 by htharrau          #+#    #+#             */
/*   Updated: 2026/04/03 15:10:47 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <fstream>
#include <ctime>

class PmergeMe {

private:
    std::map<std::string, double> _data;

    bool loadDict();
    void loadInput(const std::string& filename);
    void handleLine(const std::string& date, const double rate) const;
    bool validDate(const std::string& date, const bool& error) const;
    double getExchangeRate(const std::string& date) const;

public:
    PmergeMe(const std::string& filename);
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
};
