/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:31:44 by htharrau          #+#    #+#             */
/*   Updated: 2025/09/26 16:48:35 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/////////////////////////////
//		CONSDESTRUCTORS		//
/////////////////////////////

DiamondTrap::DiamondTrap() : ClapTrap("temp_clap_name"), ScavTrap(), FragTrap(), name("temp") {
    this->hitPoints = FragTrap::getDefaultHitPoints();
    this->energyPoints = ScavTrap::getDefaultEnergyPoints();
    this->attackDamage = FragTrap::getDefaultAttackDamage();
    std::cout << "DiamondTrap : Default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), name(name) {
    this->hitPoints = FragTrap::getDefaultHitPoints();
    this->energyPoints = ScavTrap::getDefaultEnergyPoints();
    this->attackDamage = FragTrap::getDefaultAttackDamage();
    std::cout << "DiamondTrap : Parameterized constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name) {
    std::cout << "DiamondTrap : Copy constructor called." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {  // alternativ to self-assignment checks: copy-and-swap idiom
        ClapTrap::operator=(
            other);  // Call base class assignment operators to ensure all base parts are copied
        ScavTrap::operator=(
            other);  // Call base class assignment operators to ensure all base parts are copied
        FragTrap::operator=(
            other);  // Call base class assignment operators to ensure all base parts are copied
        this->name = other.name;
    }
    std::cout << "DiamondTrap : Assignment operator called." << std::endl;
    return (*this);
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap : Destructor called on " << this->name << std::endl;
}

/////////////////////////////
//			FUNCTIONS		//
/////////////////////////////

void DiamondTrap::whoAmI() const {
    std::cout << "Diamond name is " << name << ", Clap name is " << ClapTrap::name << std::endl;
}