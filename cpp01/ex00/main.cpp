/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:13:58 by htharrau          #+#    #+#             */
/*   Updated: 2025/01/13 13:52:53 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    // Stack allocated zombie
    std::cout << "Stack alloc zombie:" << std::endl;
    randomChump("Pierre");
    randomChump("Paul");
    randomChump("Jacques");
    std::cout << std::endl;

    // Heap allocated zombie
    std::cout << "Heap alloc zombie:" << std::endl;
    Zombie* zombie1 = newZombie("Helene");
    Zombie* zombie2 = newZombie("Hannah");
    Zombie* zombie3 = newZombie("Hillary");
    zombie1->announce();
    zombie2->announce();
    zombie3->announce();
    delete zombie1;
    delete zombie2;
    delete zombie3;
    std::cout << std::endl;

    return (0);
}
