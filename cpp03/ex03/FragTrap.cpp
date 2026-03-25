/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:32:13 by htharrau          #+#    #+#             */
/*   Updated: 2025/09/26 16:49:10 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/////////////////////////////
//		CONSDESTRUCTORS		//
/////////////////////////////

FragTrap::FragTrap() : ClapTrap() {
    this->hitPoints = defaultHitPoints;
    this->energyPoints = defaultEnergyPoints;
    this->attackDamage = defaultAttackDamage;
    std::cout << "FragTrap : Default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->hitPoints = defaultHitPoints;
    this->energyPoints = defaultEnergyPoints;
    this->attackDamage = defaultAttackDamage;
    std::cout << "FragTrap : Parameterized constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap : Copy constructor called." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "FragTrap : Assignment operator called." << std::endl;
    return (*this);
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap : Destructor called on " << this->name << std::endl;
}

/////////////////////////////
//			FUNCTIONS		//
/////////////////////////////

void FragTrap::highFivesGuys() const {
    std::cout << "FragTrap requests a positive high five ✋" << std::endl;
}