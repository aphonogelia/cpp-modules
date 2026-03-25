/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:40:44 by htharrau          #+#    #+#             */
/*   Updated: 2025/06/01 18:52:47 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void coplien() {
    std::cout << MAGENTA << "\n<<< Testing the coplien forms >>>" << RESET << std::endl;
    try {
        RobotomyRequestForm alpha;  // default
        std::cout << alpha << std::endl;
        RobotomyRequestForm alpha2(alpha);  // copy
        std::cout << alpha2 << std::endl;
        alpha = alpha2;  // assignment
        std::cout << alpha << std::endl;

        PresidentialPardonForm beta("Mug");  // parameterized
        std::cout << beta << std::endl;
        PresidentialPardonForm beta2(beta);  // copy
        std::cout << beta2 << std::endl;
        beta2 = beta;  // assignment
        std::cout << beta2 << std::endl;

        ShrubberyCreationForm phi("Garden");  // parameterized
        std::cout << phi << std::endl;
        ShrubberyCreationForm phi2(phi);  // copy
        std::cout << phi2 << std::endl;
        phi2 = phi;  // assignment
        std::cout << phi2 << std::endl;
    } catch (const std::exception& e) {
        std::cout << YELLOW << e.what() << RESET << std::endl;
    }
}

void function() {
    std::cout << MAGENTA << "\n<<< Testing the functions >>>" << RESET << std::endl;
    {
        try {
            std::cout << CYAN << "\t<<< executeForm on Robotomy >>>" << RESET << std::endl;
            Bureaucrat helene("Lenaig", 1);
            RobotomyRequestForm beta("cat");
            std::cout << beta << std::endl;
            std::cout << helene << std::endl;
            helene.executeForm(beta);
            beta.beSigned(helene);
            helene.executeForm(beta);
        } catch (const std::exception& e) {
            std::cout << YELLOW << e.what() << RESET << std::endl;
        }

        try {
            std::cout << CYAN << "\t<<< executeForm on Robotomy - grade too low >>>" << RESET
                      << std::endl;
            Bureaucrat helene("Lenaig", 150);
            RobotomyRequestForm beta("cat");
            std::cout << beta << std::endl;
            std::cout << helene << std::endl;
            helene.executeForm(beta);
            beta.beSigned(helene);
            helene.executeForm(beta);
        } catch (const std::exception& e) {
            std::cout << YELLOW << e.what() << RESET << std::endl;
        }

        try {
            std::cout << CYAN << "\t<<< executeForm on Shrubbery >>>" << RESET << std::endl;
            Bureaucrat mario("Mario", 10);
            ShrubberyCreationForm beta("balcony");
            std::cout << beta << std::endl;
            std::cout << mario << std::endl;
            mario.executeForm(beta);
            beta.beSigned(mario);
            mario.executeForm(beta);
        } catch (const std::exception& e) {
            std::cout << YELLOW << e.what() << RESET << std::endl;
        }

        try {
            std::cout << CYAN << "\t<<< executeForm on Shrubbery >>>" << RESET << std::endl;
            Bureaucrat mario("Mario", 150);
            ShrubberyCreationForm beta("balcony");
            std::cout << beta << std::endl;
            std::cout << mario << std::endl;
            mario.executeForm(beta);
            beta.beSigned(mario);
            mario.executeForm(beta);
        } catch (const std::exception& e) {
            std::cout << YELLOW << e.what() << RESET << std::endl;
        }

        try {
            std::cout << CYAN << "\t<<< executeForm on Presidential >>>" << RESET << std::endl;
            Bureaucrat Karl("Karl", 1);
            PresidentialPardonForm beta("Alfred");
            std::cout << beta << std::endl;
            std::cout << Karl << std::endl;
            Karl.executeForm(beta);
            beta.beSigned(Karl);
            Karl.executeForm(beta);
        } catch (const std::exception& e) {
            std::cout << YELLOW << e.what() << RESET << std::endl;
        }

        try {
            std::cout << CYAN << "\t<<< executeForm on Presidential >>>" << RESET << std::endl;
            Bureaucrat Karl("Karl", 150);
            PresidentialPardonForm beta("Alfred");
            std::cout << beta << std::endl;
            std::cout << Karl << std::endl;
            Karl.executeForm(beta);
            beta.beSigned(Karl);
            Karl.executeForm(beta);
        } catch (const std::exception& e) {
            std::cout << YELLOW << e.what() << RESET << std::endl;
        }

        try {
            std::cout << CYAN << "\t<<< From Execute >>>" << RESET << std::endl;
            PresidentialPardonForm form("Albert");
            Bureaucrat alice("alice", 1);
            form.execute(alice);
            form.beSigned(alice);
            form.execute(alice);
        } catch (const std::exception& e) {
            std::cout << YELLOW << e.what() << RESET << std::endl;
        }

        try {
            std::cout << CYAN << "\t<<< From Execute >>>" << RESET << std::endl;
            PresidentialPardonForm form("Albert");
            Bureaucrat alice("alice", 1);
            form.beSigned(alice);
            form.execute(alice);
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
