/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:32:25 by htharrau          #+#    #+#             */
/*   Updated: 2025/05/11 14:53:50 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
    ClapTrap a("Alain");
    a.accessValues();
    a.takeDamage(9);
    a.accessValues();
    ClapTrap b;
    b = a;
    b.accessValues();

    a.takeDamage(9);
    a.accessValues();
    b.takeDamage(2);
    b.accessValues();

    ClapTrap c("Marc");
    c.accessValues();
    c.beRepaired(50);
    c.accessValues();

    ClapTrap d(c);
    d.accessValues();
    d.beRepaired(50);
    d.accessValues();
    a.attack("Karl");
    a.attack("Karl");

    ClapTrap i("Sandrine");
    i.takeDamage(100);
    i.takeDamage(1);

    return (0);
}