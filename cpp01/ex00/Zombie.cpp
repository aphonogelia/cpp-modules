/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:14:11 by htharrau          #+#    #+#             */
/*   Updated: 2025/01/13 13:52:18 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string input) : name(input) { std::cout << name << ": enters\n"; }

Zombie::~Zombie() { std::cout << name << ": exits\n"; }

void Zombie::announce(void) { std::cout << name << ": BraiiiiiiinnnzzzZ...\n"; }