/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:47:48 by htharrau          #+#    #+#             */
/*   Updated: 2025/04/24 19:36:11 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

std::string uppercase(const std::string& string) {
    std::string newString = string;

    for (size_t i = 0; i < newString.length(); i++) newString[i] = std::toupper(newString[i]);

    return (newString);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Please enter one action (DEBUG, INFO, WARNING or ERROR).\n";
        return (1);
    }

    Harl harl;
    std::string message = uppercase(argv[1]);

    harl.complain(message);

    return (0);
}
