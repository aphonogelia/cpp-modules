/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:57:50 by htharrau          #+#    #+#             */
/*   Updated: 2025/04/24 19:35:26 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

const std::string Harl::array[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

const Harl::f Harl::function[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

void Harl::debug(void) {
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "Expected ';' before '}' token." << std::endl;
}

void Harl::info(void) {
    std::cout << "[INFO]" << std::endl;
    std::cout << "Note: did you mean \%c?" << std::endl;
}

void Harl::warning(void) {
    std::cout << "[WARNING]" << std::endl;
    std::cout << "Comparison between signed and unsigned integer expressions." << std::endl;
}

void Harl::error(void) {
    std::cout << "[ERROR]" << std::endl;
    std::cout << "Undefined reference to 'complain'" << std::endl;
}

// WITHOUT SWITCH:
// void	Harl::complain(std::string message) {

// 	for (int i = 0; i < 4; i++) {
// 		if (message == this->array[i]) {
// 			for (int j = i; j < 4; j++) {
// 				(this->*function[j])();
// 			}
// 			return ;
// 		}
// 	}
// 	std::cout << "Error: " << message << " is not a valid input." << std::endl;

// }

// FOR SWITCH:
size_t Harl::getLevel(const std::string& message) {
    for (int i = 0; i < 4; i++) {
        if (message == this->array[i]) return (i);
    }
    return (99);
}

void Harl::complain(const size_t& n) { (this->*function[n])(); }
