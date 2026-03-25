/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:16:01 by htharrau          #+#    #+#             */
/*   Updated: 2025/01/12 14:16:02 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& inputWeapon) : type(inputWeapon) {
    std::cout << this->type << " created" << std::endl;
}

Weapon::~Weapon(void) { std::cout << this->type << " destructed." << std::endl; }

const std::string& Weapon::getType(void) const { return (this->type); };

void Weapon::setType(const std::string& newWeapon) { this->type = newWeapon; };
