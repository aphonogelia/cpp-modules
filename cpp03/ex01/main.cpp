/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:41:01 by htharrau          #+#    #+#             */
/*   Updated: 2025/05/13 17:03:52 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ScavTrap.hpp"

int main(void) {
    std::cout << std::endl;
    ClapTrap Cartman("Cartman");
    Cartman.accessValues();
    Cartman.attack("target");
    Cartman.takeDamage(5);
    Cartman.beRepaired(3);
    Cartman.accessValues();

    std::cout << std::endl;
    ScavTrap Samuel("Samuel");
    Samuel.accessValues();
    Samuel.attack("target");
    Samuel.takeDamage(30);
    Samuel.beRepaired(10);
    Samuel.guardGate();
    Samuel.accessValues();

    std::cout << std::endl;
    ScavTrap Samuelbis;
    Samuelbis = Samuel;
    Samuelbis.attack("target");
    ScavTrap Saul;

    std::cout << "Pointer: the reason to declare the claptrap destructor as virtual" << std::endl;
    ClapTrap* ScavTrapPtr = new ScavTrap("ScavTrapPtr");
    ScavTrapPtr->attack("target");
    delete (ScavTrapPtr);

    std::cout << std::endl << "Exit main" << std::endl;

    return (0);
}
