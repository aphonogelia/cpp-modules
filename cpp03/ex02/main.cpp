/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:17:28 by htharrau          #+#    #+#             */
/*   Updated: 2025/05/11 17:13:41 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
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
    FragTrap Francois("Francois");
    Francois.accessValues();
    Francois.attack("target");
    Francois.takeDamage(30);
    Francois.beRepaired(10);
    Francois.highFivesGuys();
    Francois.accessValues();

    // std::cout << std::endl <<"Self assignment" << std::endl; // wo -Werror flag
    // Francois = Francois;
    // Francois.accessValues();

    std::cout << std::endl;
    FragTrap FragTrapBis = Francois;
    FragTrapBis.attack("target");
    FragTrap Saul;

    std::cout << "Pointer: the reason to declare the claptrap destructor as virtual" << std::endl;
    ClapTrap* FragTrapPtr = new FragTrap("FragTrapPtr");
    FragTrapPtr->attack("target");
    delete (FragTrapPtr);

    std::cout << std::endl << "Exit main" << std::endl;

    return (0);
}