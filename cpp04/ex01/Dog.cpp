/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:56:08 by htharrau          #+#    #+#             */
/*   Updated: 2025/05/12 15:37:18 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/////////////////////////////
// 	CONDESTRUCTORS		//
/////////////////////////////

Dog::Dog() : Animal("Dog") {
    brain = new Brain();
    std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
    brain = new Brain();
    std::cout << "Dog: Parameterized constructor called on " << type << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Dog: Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        *brain = *other.brain;     // Deep copy
        Animal::operator=(other);  // Call base class assignment operator
        // This ensures that if the base class ever has more members or logic, they are properly
        // copied.
    }
    std::cout << "Dog: Copy assignment operator called" << std::endl;
    return (*this);
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog: Destructor called on " << type << ", Brain deleted" << std::endl;
}

/////////////////////////////
// 	  FUNCTIONS			//
/////////////////////////////

void Dog::makeSound() const { std::cout << type << " says WOUAFF" << std::endl; }

void Dog::setIdea(int i, const std::string& idea) { brain->setIdea(i, idea); }
std::string Dog::getIdea(int i) const { return brain->getIdea(i); }
