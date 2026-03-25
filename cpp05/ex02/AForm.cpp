/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:42:30 by htharrau          #+#    #+#             */
/*   Updated: 2025/05/30 17:49:00 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/////////////////////////////
//		STATIC CONST INIT	//
/////////////////////////////
const std::string AForm::defaultFName = "undefined";
const std::string AForm::defaultTarget = "undefined";
const int AForm::defaultSEGrade = Bureaucrat::maxGrade;

/////////////////////
//		COPLIEN 	//
/////////////////////
AForm::AForm()
    : formName(defaultFName),
      target(defaultTarget),
      isSigned(false),
      signGrade(defaultSEGrade),
      execGrade(defaultSEGrade) {}

AForm::AForm(const std::string& inputName, const std::string& inputTarget, int inputSigGr,
             int inputExGr)
    : formName(inputName),
      target(inputTarget),
      isSigned(false),
      signGrade(inputSigGr),
      execGrade(inputExGr) {
    if (signGrade < Bureaucrat::maxGrade || execGrade < Bureaucrat::maxGrade)
        throw(GradeTooHighException());
    else if (signGrade > Bureaucrat::minGrade || execGrade > Bureaucrat::minGrade)
        throw(GradeTooLowException());
}

AForm::AForm(const AForm& other)
    : formName(other.formName),
      target(other.target),
      isSigned(other.isSigned),
      signGrade(other.signGrade),
      execGrade(other.execGrade) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) isSigned = other.isSigned;
    return (*this);
}

AForm::~AForm() { std::cout << "AForm destructor called on " << formName << std::endl; }

/////////////////////////
//		FUNCTIONS		//
/////////////////////////
void AForm::beSigned(const Bureaucrat& b) {
    if (this->isSigned)
        throw AlreadySignedException();
    else if (b.getGrade() <= this->signGrade)
        this->isSigned = true;
    else
        throw GradeTooLowException("Grade too low to sign the form.");
}

/////////////////////////
//		GETTERS			//
/////////////////////////
int AForm::getExecGrade() const { return this->execGrade; }
int AForm::getSignGrade() const { return this->signGrade; }
bool AForm::getSignStatus() const { return this->isSigned; }
const std::string& AForm::getFormName() const { return this->formName; }
const std::string& AForm::getTarget() const { return this->target; }

/////////////////////////
//		EXCEPTIONS		//
/////////////////////////
AForm::GradeTooLowException::GradeTooLowException()
    : errorMsg("Error: signing or executing grade is too low.") {}
AForm::GradeTooLowException::GradeTooLowException(const std::string& er) : errorMsg(er) {}
AForm::GradeTooLowException::~GradeTooLowException() throw() {}
const char* AForm::GradeTooLowException::what() const throw() { return (errorMsg.c_str()); }

AForm::GradeTooHighException::GradeTooHighException()
    : errorMsg("Error: signing or executing grade is too high.") {}
AForm::GradeTooHighException::GradeTooHighException(const std::string& er) : errorMsg(er) {}
AForm::GradeTooHighException::~GradeTooHighException() throw() {}
const char* AForm::GradeTooHighException::what() const throw() { return (errorMsg.c_str()); }

const char* AForm::AlreadySignedException::what() const throw() {
    return "Form is already signed.";
}

const char* AForm::ExecGradeTooLowException::what() const throw() {
    return "Execution grade too low.";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form has yet to be signed.";
};

/////////////////////////////
//		INSERTION OVERLOAD	//
/////////////////////////////
std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << f.getFormName() << " (exec. grade " << f.getExecGrade() << ", sign. grade "
       << f.getSignGrade() << ", " << (f.getSignStatus() ? "" : "not ")
       << "signed) has the following target: " << f.getTarget() << ".";
    return os;
}
