/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:54:34 by htharrau          #+#    #+#             */
/*   Updated: 2025/05/12 12:54:35 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/////////////////////////////
// 	CONDESTRUCTORS		//
/////////////////////////////

Cat::Cat() : Animal("Cat") { std::cout << "Cat: Default constructor called" << std::endl; }

Cat::Cat(std::string type) : Animal(type) {
    std::cout << "Cat: Parameterized constructor called on " << type << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat: Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) Animal::operator=(other);  // Call base class assignment operator
    // This ensures that if the base class ever has more members or logic, they are properly copied.
    std::cout << "Cat: Copy assignment operator called" << std::endl;
    return (*this);
}

Cat::~Cat() { std::cout << "Cat: Destructor called on " << type << std::endl; }

/////////////////////////////
// 	  FUNCTIONS			//
/////////////////////////////

void Cat::makeSound() const {
    std::cout << type << " says HHHIIIIIIIIIIIIIIIIIISSSSSSSSSSSSSSSSSSS" << std::endl;
}
