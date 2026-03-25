/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:17:28 by htharrau          #+#    #+#             */
/*   Updated: 2025/05/11 18:36:14 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
    std::cout << "\nDefault constructor:" << std::endl;
    DiamondTrap Dan;
    Dan.accessValues();
    Dan.attack("target");
    Dan.takeDamage(30);
    Dan.beRepaired(10);
    Dan.guardGate();
    Dan.accessValues();
    Dan.whoAmI();

    std::cout << "\nParametereized constructor:" << std::endl;
    DiamondTrap Denise("Denise");
    Denise.accessValues();
    Denise.attack("target");
    Denise.takeDamage(5);
    Denise.beRepaired(3);
    Denise.accessValues();
    Denise.whoAmI();

    std::cout << "\nCopy assignment constructor:" << std::endl;
    Dan = Denise;
    Dan.accessValues();
    Dan.attack("target");
    Dan.takeDamage(30);
    Dan.beRepaired(10);
    Dan.highFivesGuys();
    Dan.accessValues();
    Dan.whoAmI();

    std::cout << "\nCopy constructor:" << std::endl;
    DiamondTrap CopyDenise(Denise);
    CopyDenise.accessValues();
    CopyDenise.whoAmI();

    std::cout << "Pointer: the reason to declare the claptrap destructor as virtual" << std::endl;
    ClapTrap* DiamondTrapPtr = new DiamondTrap("DiamondTrapPtr");
    DiamondTrapPtr->attack("target");
    delete (DiamondTrapPtr);

    std::cout << "\nExit main" << std::endl;

    return (0);
}