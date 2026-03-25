/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:42:30 by htharrau          #+#    #+#             */
/*   Updated: 2025/05/30 17:49:00 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include "Bureaucrat.hpp"

/////////////////////////////
//		STATIC CONST INIT	//
/////////////////////////////
const std::string Form::defaultFName = "A412";
const std::string Form::defaultFormEr = "Error: inadequate signing or executing grade.";

/////////////////////
//		COPLIEN 	//
/////////////////////
Form::Form()
    : formName(defaultFName),
      isSigned(false),
      signGrade(defaultSEGrade),
      execGrade(defaultSEGrade) {}

Form::Form(const std::string& inputName, int inputSigGr, int inputExGr)
    : formName(inputName), isSigned(false), signGrade(inputSigGr), execGrade(inputExGr) {
    if (signGrade < 1 || execGrade < 1)
        throw(GradeTooHighException());
    else if (signGrade > 150 || execGrade > 150)
        throw(GradeTooLowException());
}

Form::Form(const Form& other)
    : formName(other.formName),
      isSigned(other.isSigned),
      signGrade(other.signGrade),
      execGrade(other.execGrade) {}

Form& Form::operator=(const Form& other) {
    if (this != &other) isSigned = other.isSigned;
    return (*this);
}

Form::~Form() { std::cout << "Form destructor called on " << formName << std::endl; }

/////////////////////////
//		FUNCTIONS		//
/////////////////////////
void Form::beSigned(const Bureaucrat& b) {
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
int Form::getExecGrade() const { return this->execGrade; }
int Form::getSignGrade() const { return this->signGrade; }
bool Form::getSignStatus() const { return this->isSigned; }
const std::string& Form::getFormName() const { return this->formName; }

/////////////////////////
//		EXCEPTIONS		//
/////////////////////////
Form::GradeTooLowException::GradeTooLowException() : errorMsg(Form::defaultFormEr) {}
Form::GradeTooLowException::GradeTooLowException(const std::string& er) : errorMsg(er) {}
Form::GradeTooLowException::~GradeTooLowException() throw() {}
const char* Form::GradeTooLowException::what() const throw() { return (errorMsg.c_str()); }

Form::GradeTooHighException::GradeTooHighException() : errorMsg(Form::defaultFormEr) {}
Form::GradeTooHighException::GradeTooHighException(const std::string& er) : errorMsg(er) {}
Form::GradeTooHighException::~GradeTooHighException() throw() {}
const char* Form::GradeTooHighException::what() const throw() { return (errorMsg.c_str()); }
const char* Form::AlreadySignedException::what() const throw() { return "Form is already signed."; }

/////////////////////////////
//		INSERTION OVERLOAD	//
/////////////////////////////
std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form " << f.getFormName() << " has an execution grade of " << f.getExecGrade()
       << " and a signing grade of " << f.getSignGrade() << ".\n"
       << "The form has " << (f.getSignStatus() ? "" : "not ") << "been signed.";
    return os;
}
