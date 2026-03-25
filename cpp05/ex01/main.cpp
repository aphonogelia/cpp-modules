/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:40:44 by htharrau          #+#    #+#             */
/*   Updated: 2025/05/30 20:13:40 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void coplien() {
    std::cout << MAGENTA << "\n<<< Testing the coplien form and sign function for Form >>>" << RESET
              << std::endl;
    try {
        Form alpha;  // default
        std::cout << alpha << std::endl;
        Form beta("B512", 142, 1);  // parameterized
        std::cout << beta << std::endl;
        Form phi(beta);  // copy
        std::cout << phi << std::endl;
        alpha = phi;  // assignment
        std::cout << alpha << std::endl;

        Form OutOfBound("OutOfBound", 0, 120);  // parameterized
        std::cout << OutOfBound << std::endl;

    } catch (const std::exception& e) {
        std::cout << YELLOW << e.what() << RESET << std::endl;
    }
    try {
        Form OutOfBound("OutOfBound", 1, 1020);  // parameterized
        std::cout << OutOfBound << std::endl;

    } catch (const std::exception& e) {
        std::cout << YELLOW << e.what() << RESET << std::endl;
    }
    try {
        Bureaucrat OutOfBound("OutOfBound", -5);  // parameterized
        std::cout << OutOfBound << std::endl;
    } catch (const std::exception& e) {
        std::cout << YELLOW << e.what() << RESET << std::endl;
    }
    try {
        Bureaucrat OutOfBound("OutOfBound", 555);  // parameterized
        std::cout << OutOfBound << std::endl;
    } catch (const std::exception& e) {
        std::cout << YELLOW << e.what() << RESET << std::endl;
    }
}

void function() {
    std::cout << MAGENTA << "\n<<< Testing the functions >>>" << RESET << std::endl;
    {
        try {
            std::cout << CYAN << "\t<<< beSigned function >>>" << RESET << std::endl;
            Bureaucrat helene("Lenaig", 1);
            Form beta("B512", 142, 1);
            std::cout << helene << std::endl;
            beta.beSigned(helene);
            std::cout << beta << std::endl;
        } catch (const std::exception& e) {
            std::cout << YELLOW << e.what() << RESET << std::endl;
        }
        try {
            std::cout << CYAN << "\t<<< beSigned function x2 >>>" << RESET << std::endl;
            Bureaucrat helene("Lenaig", 1);
            Form beta("B512", 142, 1);
            std::cout << helene << std::endl;
            beta.beSigned(helene);
            std::cout << beta << std::endl;
            beta.beSigned(helene);
            std::cout << beta << std::endl;
        } catch (const std::exception& e) {
            std::cout << YELLOW << e.what() << RESET << std::endl;
        }
        try {
            std::cout << CYAN << "\t<<< signForm function >>>" << RESET << std::endl;
            Bureaucrat mario("Mario", 5);
            Form r6985("R6985", 4, 1);
            std::cout << mario << std::endl;
            std::cout << r6985 << std::endl;
            mario.signForm(r6985);
            std::cout << r6985 << std::endl;
            mario.incrementGrade();
            std::cout << mario << std::endl;
            mario.signForm(r6985);
            std::cout << r6985 << std::endl;
            mario.signForm(r6985);
            std::cout << r6985 << std::endl;
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
