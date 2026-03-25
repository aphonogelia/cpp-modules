/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:56:15 by htharrau          #+#    #+#             */
/*   Updated: 2025/05/12 12:54:25 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/////////////////////////////
// 	CONDESTRUCTORS		//
/////////////////////////////

Animal::Animal() : type("Animal") {
    std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
    std::cout << "Animal: Parameterized constructor called on " << type << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal: Copy constructor called." << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) this->type = other.type;
    std::cout << "Animal: Copy assignment operator called." << std::endl;
    return (*this);
}

Animal::~Animal() { std::cout << "Animal: Destructor called on " << type << std::endl; }

/////////////////////////////
// 	  FUNCTIONS			//
/////////////////////////////

void Animal::makeSound() const {
    std::cout << type << " says CHEEP   CHEEP CHEEP     CHEEP" << std::endl;
}

std::string Animal::getType() const { return (this->type); }