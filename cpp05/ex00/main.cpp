/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:40:44 by htharrau          #+#    #+#             */
/*   Updated: 2025/06/02 17:06:36 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define RESET "\033[0m"

void coplien() {
    std::cout << MAGENTA << "\n<<< Testing the coplien form >>>" << RESET << std::endl;
    try {
        Bureaucrat Andre;  // default
        std::cout << Andre << std::endl;
        Bureaucrat Anna("anna", 142);  // parameterized
        std::cout << Anna << std::endl;
        Bureaucrat Alicia(Anna);  // copy
        std::cout << Alicia << std::endl;
        Andre = Alicia;  // assignment
        std::cout << Andre << std::endl;
        Bureaucrat OutOfBound("OutOfBound", -5);  // parameterized
        std::cout << OutOfBound << std::endl;
    } catch (const std::exception& e) {
        std::cout << YELLOW << e.what() << RESET << std::endl;
    }
    try {
        Bureaucrat OutOfBound("OutOfBound", 151);  // parameterized
        std::cout << OutOfBound << std::endl;
    } catch (const std::exception& e) {
        std::cout << YELLOW << e.what() << RESET << std::endl;
    }
}

void function() {
    std::cout << MAGENTA << "\n<<< Testing the functions >>>" << RESET << std::endl;
    {
        try {
            Bureaucrat Andre;  // default
            Andre.decrementGrade();
            std::cout << Andre << std::endl;
        } catch (const std::exception& e) {
            std::cout << YELLOW << e.what() << RESET << std::endl;
        }
        try {
            Bureaucrat Anna("anna", 142);  // parameterized
            for (int i = 0; i < 10; i++) {
                Anna.decrementGrade();
                std::cout << Anna << std::endl;
            }
        } catch (const std::exception& e) {
            std::cout << YELLOW << e.what() << RESET << std::endl;
        }
        try {
            Bureaucrat Anton("Anton", 6);  // parameterized
            for (int i = 0; i < 10; i++) {
                Anton.incrementGrade();
                std::cout << Anton << std::endl;
            }
        } catch (const std::exception& e) {
            std::cout << YELLOW << e.what() << RESET << std::endl;
        }
    }
}

int main(void) {
    coplien();
    function();

    return (0);
}
