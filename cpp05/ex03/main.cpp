/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:40:44 by htharrau          #+#    #+#             */
/*   Updated: 2025/06/02 12:46:45 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void coplien() {
    std::cout << MAGENTA << "\n<<< Testing the coplien form >>>" << RESET << std::endl;
    try {
        Intern aa;
        Intern bb(aa);
        Intern cc;
        cc = bb;
    } catch (const std::exception& e) {
        std::cout << YELLOW << e.what() << RESET << std::endl;
    }
}

void function() {
    std::cout << MAGENTA << "\n<<< Testing the functions >>>" << RESET << std::endl;
    {
        try {
            std::cout << CYAN << "\n\t<<< Intern Robotomy stuff >>>" << RESET << std::endl;
            Intern someRandomIntern;
            AForm* rrf;
            rrf = someRandomIntern.makeForm("robotomy request", "Cactus");
            std::cout << *rrf << std::endl;
            Bureaucrat helene("Lenaig", 1);
            std::cout << helene << std::endl;
            helene.executeForm(*rrf);
            rrf->beSigned(helene);
            helene.executeForm(*rrf);
            delete rrf;
        } catch (const std::exception& e) {
            std::cout << YELLOW << e.what() << RESET << std::endl;
        }

        try {
            std::cout << CYAN << "\n\t<<< Intern Presidential stuff >>>" << RESET << std::endl;
            Intern someRandomIntern;
            AForm* ppf;
            ppf = someRandomIntern.makeForm("presidential pardon", "Marcel");
            std::cout << *ppf << std::endl;
            Bureaucrat helene("Lenaig", 6);
            std::cout << helene << std::endl;
            helene.executeForm(*ppf);
            ppf->beSigned(helene);
            helene.executeForm(*ppf);
            helene.incrementGrade();
            std::cout << helene << std::endl;
            helene.executeForm(*ppf);
            delete ppf;
        } catch (const std::exception& e) {
            std::cout << YELLOW << e.what() << RESET << std::endl;
        }

        try {
            std::cout << CYAN << "\n\t<<< Intern Shrubbery stuff >>>" << RESET << std::endl;
            Intern someRandomIntern;
            AForm* scf;
            scf = someRandomIntern.makeForm("shrubbery creation", "Arena");
            std::cout << *scf << std::endl;
            Bureaucrat helene("Lenaig", 100);
            std::cout << helene << std::endl;
            helene.executeForm(*scf);
            scf->beSigned(helene);
            helene.executeForm(*scf);
            delete scf;
        } catch (const std::exception& e) {
            std::cout << YELLOW << e.what() << RESET << std::endl;
        }

        try {
            std::cout << CYAN << "\n\t<<< Intern stuff that dont work >>>" << RESET << std::endl;
            Intern someRandomIntern;
            AForm* rrf;
            rrf = someRandomIntern.makeForm("fffffffffffff", "Bender");
            delete rrf;
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
