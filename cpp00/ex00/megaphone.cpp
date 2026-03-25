/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:32:09 by htharrau          #+#    #+#             */
/*   Updated: 2026/03/25 11:50:45 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	$>./megaphone "shhhhh... I think the students are asleep..."
        SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
        $>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
        DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
        $>./megaphone
        * LOUD AND UNBEARABLE FEEDBACK NOISE *
        $>
 */

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

struct ToUpper {
    char operator()(char c) const { return std::toupper(static_cast<unsigned char>(c)); }
};

void uppercase(int argc, char* argv[]) {
    int i;

    i = 1;
    while (i < argc) {
        std::string arg(argv[i]);  // create a new string called arg, allocate and deallocate memory
        std::transform(arg.begin(), arg.end(), arg.begin(), ToUpper());
        std::cout << arg;
        i++;
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
        uppercase(argc, argv);
    return (0);
}
