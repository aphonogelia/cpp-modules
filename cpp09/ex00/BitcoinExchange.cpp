/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:04:51 by htharrau          #+#    #+#             */
/*   Updated: 2026/04/01 20:23:38 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool evaluate(const std::string& input) {

    std::istringstream iss(input);
    std::string token;

    while (iss >> token) {
        if (token.length() != 1) {
            std::cerr << "[Error] Invalid token: " << token << std::endl;
            return false;
        }
        
        char c = token[0];
    }
    return true;
}