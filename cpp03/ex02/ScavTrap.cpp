/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:32:13 by htharrau          #+#    #+#             */
/*   Updated: 2025/05/11 17:10:07 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/////////////////////////////
//		CONSDESTRUCTORS		//
/////////////////////////////

ScavTrap::ScavTrap() : ClapTrap() {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap : Default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap : Parameterized constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap : Copy constructor called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {  // alternativ to self-assignment checks: copy-and-swap idiom
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "ScavTrap : Assignment operator called." << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap : Destructor called on " << this->name << std::endl;
}

/////////////////////////////
//			FUNCTIONS		//
/////////////////////////////

void ScavTrap::attack(const std::string& target) {
    if (this->hitPoints == 0 || this->energyPoints == 0) {
        std::cout << "ScavTrap " << this->name << " can't attack atm." << std::endl;
    } else {
        this->energyPoints -= 1;
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing "
                  << attackDamage << " points of damage!" << std::endl;
    }
}

void ScavTrap::guardGate() { std::cout << "ScavTrap is now in Gate keeper mode." << std::endl; }
