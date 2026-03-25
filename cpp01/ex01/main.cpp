/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:14:17 by htharrau          #+#    #+#             */
/*   Updated: 2025/01/12 14:14:18 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    Zombie* horde0;
    Zombie* horde1;
    Zombie* horde2;
    int n0 = 5;
    int n1 = 13;
    int n2 = -1;

    horde0 = zombieHorde(n0, "Karl");
    hordeAnnounce(n0, horde0);
    delete[] horde0;

    horde1 = zombieHorde(n1, "Gabe");
    hordeAnnounce(n1, horde1);
    delete[] horde1;

    horde2 = zombieHorde(n2, "Erreur");
    hordeAnnounce(n2, horde2);
    delete[] horde2;

    return (0);
}
