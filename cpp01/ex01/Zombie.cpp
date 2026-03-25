/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:14:21 by htharrau          #+#    #+#             */
/*   Updated: 2025/01/12 14:14:22 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("temp"){};

Zombie::Zombie(std::string input) : name(input) { std::cout << name << ": enters\n"; }

Zombie::~Zombie() { std::cout << name << ": exits\n"; }

void Zombie::announce(void) { std::cout << name << ": BraiiiiiiinnnzzzZ...\n"; }

void Zombie::baptize(std::string newName) { name = newName; }
