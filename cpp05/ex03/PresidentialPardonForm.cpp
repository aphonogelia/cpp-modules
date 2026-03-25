/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:50:41 by htharrau          #+#    #+#             */
/*   Updated: 2025/06/01 18:41:58 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* PresidentialPardonForm: Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox.	*/

#include "PresidentialPardonForm.hpp"

///////////////
//  Coplien  //
///////////////

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", "undefined", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& inputTarget)
    : AForm("PresidentialPardonForm", inputTarget, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) AForm::operator=(other);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called on " << getTarget() << std::endl;
}

///////////////
//  Function //
///////////////
void PresidentialPardonForm::execute(const Bureaucrat& b) const {
    if (!getSignStatus()) throw FormNotSignedException();

    if (b.getGrade() > getExecGrade())
        throw GradeTooLowException("Executor grade too low to execute.");

    std::cout << BLUE << getTarget() << " has been pardoned by Zaphod Beeblebrox." << RESET
              << std::endl;
}