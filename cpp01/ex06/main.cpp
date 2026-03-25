/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:58:31 by htharrau          #+#    #+#             */
/*   Updated: 2025/04/24 19:36:01 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

std::string uppercase(const std::string& string) {
    std::string newString = string;

    for (size_t i = 0; i < newString.length(); i++) newString[i] = std::toupper(newString[i]);

    return (newString);
}

//  If you want to avoid fall through, always use a break at the end of each case

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Please enter one action (DEBUG, INFO, WARNING or ERROR).\n";
        return (1);
    }

    Harl harl;
    std::string message = uppercase(argv[1]);
    int index = harl.getLevel(message);

    switch (index) {
        case 0:
            harl.complain(0);
        case 1:
            harl.complain(1);
        case 2:
            harl.complain(2);
        case 3:
            harl.complain(3);
            break;
        default:
            std::cout << "Error: " << message << " is not a valid input." << std::endl;
    }
    return (0);
}
