/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:17:26 by htharrau          #+#    #+#             */
/*   Updated: 2025/04/24 18:50:16 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

const std::string Harl::array[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

const Harl::f Harl::function[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

void Harl::debug(void) { std::cout << "Six seasons and a movie!" << std::endl; }

void Harl::info(void) { std::cout << "Some flies are too awesome for the wall." << std::endl; }

void Harl::warning(void) {
    std::cout << "I'm going to eat spaceman paninis with black Hitler and there's nothing you can "
                 "do about it!"
              << std::endl;
}

void Harl::error(void) {
    std::cout << "Knock, knock. Who's there? Cancer. Oh good, come on in, I thought it was Britta!"
              << std::endl;
}

void Harl::complain(std::string message) {
    for (int i = 0; i < 4; i++) {
        if (message == this->array[i]) {
            (this->*function[i])();
            return;
        }
    }
    std::cout << "Error: " << message << " is not a valid input." << std::endl;
}