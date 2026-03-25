/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:50:54 by htharrau          #+#    #+#             */
/*   Updated: 2025/06/01 18:13:04 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************
ShrubberyCreationForm: Required grades: sign 145, exec 137
Creates a file <target>_shrubbery in the working directory and writes ASCII
trees inside it.
******************************************************************************/

#include "ShrubberyCreationForm.hpp"

#include <fstream>

///////////////
//  Coplien  //
///////////////

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", "undefined", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& inputTarget)
    : AForm("ShrubberyCreationForm", inputTarget, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called on " << getTarget() << std::endl;
}

///////////////
//  Function //
///////////////
void ShrubberyCreationForm::execute(const Bureaucrat& b) const {
    if (!getSignStatus()) throw FormNotSignedException();

    if (b.getGrade() > getExecGrade())
        throw GradeTooLowException("Executor grade too low to execute.");

    std::ofstream ofs((getTarget() + "_shrubbery").c_str());
    if (!ofs) throw std::runtime_error("Failed to open file.");
    ofs << "──▒▒▒▒▒▒▒▒───▒▒▒▒▒▒▒▒─\n"
           "─▒▐▒▐▒▒▒▒▌▒─▒▒▌▒▒▐▒▒▌▒\n"
           "──▒▀▄█▒▄▀▒───▒▀▄▒▌▄▀▒─\n"
           "─────██─────────██────\n"
           "░░░▄▄██▄░░░░░░░▄██▄░░░\n";
    ofs.close();
}
