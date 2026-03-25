/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:16:17 by htharrau          #+#    #+#             */
/*   Updated: 2025/01/12 14:16:18 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

#include "Weapon.hpp"

HumanA::HumanA(const std::string& inputName, Weapon& inputWeapon)
    : name(inputName), weapon(inputWeapon) {}

HumanA::~HumanA() { std::cout << name << " destructed" << std::endl; }

void HumanA::attack() const {
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
