/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:33:03 by htharrau          #+#    #+#             */
/*   Updated: 2025/07/18 17:30:47 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << MAGENTA << "Please enter one (and only one) argument to convert." << RESET
                  << std::endl;
        return (1);
    }
    // (void)argv;
    try {
        ScalarConverter::convert(argv[1]);
        // ScalarConverter::convert("");
    } catch (const std::exception& e) {
        std::cout << BLUE << e.what() << RESET << std::endl;
    }

    return (0);
}
