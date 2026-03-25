/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:50:48 by htharrau          #+#    #+#             */
/*   Updated: 2025/06/01 18:42:27 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************
 RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises, then informs that <target> has been robotomized
successfully 50% of the time. Otherwise, it informs that the robotomy failed.
*******************************************************************************/

#include "RobotomyRequestForm.hpp"

#include <cstdlib>  // for rand, srand
#include <ctime>    // for time

///////////////
//  Coplien  //
///////////////

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "undefined", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& inputTarget)
    : AForm("RobotomyRequestForm", inputTarget, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) AForm::operator=(other);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called on " << getTarget() << std::endl;
}

///////////////
//  Function //
///////////////
void RobotomyRequestForm::execute(const Bureaucrat& b) const {
    if (!getSignStatus()) throw FormNotSignedException();

    if (b.getGrade() > getExecGrade())
        throw GradeTooLowException("Executor grade too low to execute.");

    std::cout << BLUE << "DRILLL.....DRILL....DRIIIIIILLLLLLLL" << std::endl;

    std::srand(std::time(NULL));
    if (std::rand() % 2)
        std::cout << getTarget() << " has been robotomized successfully." << RESET << std::endl;
    else
        std::cout << "Robotomy failed on " << getTarget() << RESET << std::endl;
}
