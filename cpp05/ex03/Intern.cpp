/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:54:02 by htharrau          #+#    #+#             */
/*   Updated: 2025/06/02 12:31:57 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* *****************************************************************************
The intern has one key ability: the makeForm() function, taking 2 parameters:
                . the first one represents the name of a form, and
                . the second one represents the target of the form.
        - It returns a pointer to a AForm object (corresponding to the 1st parameter),
          with its target initialized to the second parameter.
        - It should print something like: Intern creates <form>
        - If the provided form name does not exist, print an explicit error message.
***************************************************************************** */

#include "Intern.hpp"

// Coplien Form
Intern::Intern() {}
Intern::Intern(const Intern& other) { (void)other; }
Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}
Intern::~Intern() { std::cout << "Intern destructor called" << std::endl; }

// Other
Intern::FormType Intern::getFormType(const std::string& form) const {
    if (form == "robotomy request") return RobotomyRequest;
    if (form == "presidential pardon") return PresidentialPardon;
    if (form == "shrubbery creation") return ShrubberyCreation;
    return (Unknown);
}

AForm* Intern::makeForm(const std::string& form, const std::string& target) const {
    switch (getFormType(form)) {
        case ShrubberyCreation:
            return (new ShrubberyCreationForm(target));
        case RobotomyRequest:
            return (new RobotomyRequestForm(target));
        case PresidentialPardon:
            return (new PresidentialPardonForm(target));
        default:
            throw FormDontExistException();
    }
}

// Exception
const char* Intern::FormDontExistException::what() const throw() { return ("Cant find the form."); }
