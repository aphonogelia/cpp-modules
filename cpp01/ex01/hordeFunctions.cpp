/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:14:24 by htharrau          #+#    #+#             */
/*   Updated: 2025/01/12 14:14:25 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0) {
        std::cerr << "ERRoR: A hord is composed of at least 1 zombie.\n";
        return (NULL);
    }

    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; i++) {
        horde[i].baptize(name);
    }
    return (horde);
}

void hordeAnnounce(int N, Zombie* horde) {
    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }
}
