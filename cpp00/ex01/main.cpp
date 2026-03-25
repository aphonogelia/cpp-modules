/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:31:20 by htharrau          #+#    #+#             */
/*   Updated: 2025/01/10 15:08:34 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

#include "Contact.hpp"
#include "PhoneBook.hpp"

void removeSpaces(std::string &str) {
    str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
}

int main(void) {
    PhoneBook phonebook;
    std::string command;

    std::cout << std::endl;
    while (true) {
        std::cout << "\033[32m";
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::cout << "\033[0m";
        getline(std::cin, command);
        removeSpaces(command);

        if (command == "EXIT")
            break;
        else if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
            phonebook.searchContact();
        else
            std::cout << "Command invalid."
                      << "\n\n";
    }
    return (0);
}
