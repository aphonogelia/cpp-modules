/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:56:15 by htharrau          #+#    #+#             */
/*   Updated: 2025/05/13 12:17:34 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/////////////////////////////
// 	CONDESTRUCTORS		//
/////////////////////////////

AAnimal::AAnimal() : type("AAnimal") {
    std::cout << "AAnimal: Default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type) {
    std::cout << "AAnimal: Parameterized constructor called on " << type << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type) {
    std::cout << "AAnimal: Copy constructor called." << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    if (this != &other) this->type = other.type;
    std::cout << "AAnimal: Copy assignment operator called." << std::endl;
    return (*this);
}

AAnimal::~AAnimal() { std::cout << "AAnimal: Destructor called on " << type << std::endl; }

/////////////////////////////
// 	  FUNCTIONS			//
/////////////////////////////

std::string AAnimal::getType() const { return (this->type); }