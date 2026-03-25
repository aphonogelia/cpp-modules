/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:55:59 by htharrau          #+#    #+#             */
/*   Updated: 2025/05/12 12:54:49 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/////////////////////////////
// 	CONDESTRUCTORS		//
/////////////////////////////

WrongCat::WrongCat() : WrongAnimal("WrongAnimal") {
    std::cout << "WrongCat: Default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
    std::cout << "WrongCat: Parameterized constructor called on " << type << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat: Copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) WrongAnimal::operator=(other);  // Call base class assignment operator
    // This ensures that if the base class ever has more members or logic, they are properly copied.
    std::cout << "WrongCat: Copy assignment operator called" << std::endl;
    return (*this);
}

WrongCat::~WrongCat() { std::cout << "WrongCat: Destructor called on " << type << std::endl; }

/////////////////////////////
// 	  FUNCTIONS			//
/////////////////////////////

void WrongCat::makeSound() const {
    std::cout << type << " says HHHIIIIIIIIIIIIIIIIIISSSSSSSSSSSSSSSSSSS" << std::endl;
}