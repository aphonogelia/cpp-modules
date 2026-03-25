/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:55:50 by htharrau          #+#    #+#             */
/*   Updated: 2025/05/12 12:54:59 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/////////////////////////////
// 	CONDESTRUCTORS		//
/////////////////////////////

WrongAnimal::WrongAnimal() : type("WrongCat") {
    std::cout << "WrongAnimal: Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
    std::cout << "WrongAnimal: Parameterized constructor called on " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << "WrongAnimal: Copy constructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) this->type = other.type;
    std::cout << "WrongAnimal: Copy assignment operator called." << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal: Destructor called on " << type << std::endl;
}

/////////////////////////////
// 	  FUNCTIONS			//
/////////////////////////////

void WrongAnimal::makeSound() const {
    std::cout << type << " says CHEEP   CHEEP CHEEP     CHEEP" << std::endl;
}

std::string WrongAnimal::getType() const { return (this->type); }