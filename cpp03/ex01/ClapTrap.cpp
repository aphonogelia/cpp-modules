/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:32:03 by htharrau          #+#    #+#             */
/*   Updated: 2025/05/11 15:16:23 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/////////////////////////////
//		CONSDESTRUCTORS		//
/////////////////////////////

ClapTrap::ClapTrap() : name("temp"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap : Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap : Parameterized constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name(other.name),
      hitPoints(other.hitPoints),
      energyPoints(other.energyPoints),
      attackDamage(other.attackDamage) {
    std::cout << "ClapTrap : Copy constructor called." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap : Assignment operator called." << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap : Destructor called on " << this->name << std::endl;
}

/////////////////////////////
//			FUNCTIONS		//
/////////////////////////////

void ClapTrap::attack(const std::string& target) {
    if (this->hitPoints == 0 || this->energyPoints == 0) {
        std::cout << "ClapTrap " << this->name << " can't attack atm." << std::endl;
    } else {
        this->energyPoints -= 1;
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing "
                  << attackDamage << " points of damage." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->hitPoints == 0) {
        std::cout << "ClapTrap " << this->name
                  << " does not take damage as it does not have hit points." << std::endl;
    } else {
        if (this->hitPoints < amount)
            this->hitPoints = 0;
        else
            this->hitPoints -= amount;
        std::cout << "ClapTrap " << this->name << " gets " << amount
                  << " points of damage and has now " << this->hitPoints << " hit points."
                  << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->hitPoints == 0 || this->energyPoints == 0) {
        std::cout << "ClapTrap " << this->name << " can't be repaired atm." << std::endl;
    }

    else {
        this->energyPoints -= 1;
        this->hitPoints += amount;
        std::cout << "ClapTrap " << this->name << " gets " << amount
                  << " reparation points and has now " << hitPoints << " hit points." << std::endl;
    }
}

void ClapTrap::accessValues() {
    std::cout << "ClapTrap " << this->name << " has " << this->hitPoints << " hit points and "
              << this->energyPoints << " energy points." << std::endl;
}