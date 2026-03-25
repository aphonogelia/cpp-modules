/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:41:22 by htharrau          #+#    #+#             */
/*   Updated: 2025/05/31 13:29:24 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/////////////////////////////////
//		STATIC CONST INIT		//
/////////////////////////////////
const std::string Bureaucrat::defaultName = "Kevin";

/////////////////////////////////
//		CONSDESTRUCTORS			//
/////////////////////////////////
Bureaucrat::Bureaucrat() : name(defaultName), grade(minGrade) {}

Bureaucrat::Bureaucrat(const std::string& inputName, int inputGrade)
    : name(inputName), grade(inputGrade) {
    if (grade < maxGrade) throw GradeTooHighException();
    if (grade > minGrade) throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) this->grade = other.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat() { std::cout << "Bureaucrat destructor called on " << name << std::endl; }

/////////////////////////////////
//			GETTERS				//
/////////////////////////////////
const std::string& Bureaucrat::getName() const { return this->name; }
int Bureaucrat::getGrade() const { return this->grade; }

/////////////////////////////////
//		EXCEPTION CLASSES		//
/////////////////////////////////

Bureaucrat::GradeTooHighException::GradeTooHighException() : errorMsg("Error: grade too high.") {}
Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& msg) : errorMsg(msg) {}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}
const char* Bureaucrat::GradeTooHighException::what() const throw() { return (errorMsg.c_str()); }

Bureaucrat::GradeTooLowException::GradeTooLowException() : errorMsg("Error: grade too low.") {}
Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& msg) : errorMsg(msg) {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}
const char* Bureaucrat::GradeTooLowException::what() const throw() { return (errorMsg.c_str()); }

/////////////////////////////////
//			OTHER				//
/////////////////////////////////

void Bureaucrat::incrementGrade() {
    if (grade == maxGrade) {
        std::string msg = "Cannot increment grade for " + name + ": already at maximum.";
        throw GradeTooHighException(msg);
    }
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade == minGrade) {
        std::string msg = "Cannot decrement grade for " + name + ": already at minimum";
        throw GradeTooLowException(msg);
    }
    grade++;
}

/////////////////////////////////
//		INSERTION OVERLOAD		//
/////////////////////////////////
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
