/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:26:18 by htharrau          #+#    #+#             */
/*   Updated: 2026/03/23 22:31:38 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
    /****** SUBJECT ******/

    std::cout << RED << "\n---------------\nSUBJECT" << RESET << "\n---------------\n";

    std::vector<int> v;
    std::deque<int> d;
    std::list<int> l;

    std::cout << CYAN << "\n\nSPECIFIC INDEX: " << RESET << "\n";
    std::cout << "\n-----\nVECTOR" << RESET << "\n-----\n";
    v.clear();
    fillContainer(v, 100);
    easyfind(v, v[10]);
    easyfind(v, -1);

    std::cout << "\n-----\nDEQUE" << RESET << "\n-----\n";
    d.clear();
    fillContainer(d, 100);
    easyfind(d, d[10]);
    easyfind(d, -1);

    std::cout << "\n-----\nLIST" << RESET << "\n-----\n";
    l.clear();
    fillContainer(l, 100);
    std::list<int>::iterator it = l.begin();
    std::advance(it, 10);
    int list_value = *it;
    easyfind(l, list_value);
    easyfind(l, -1);

    std::srand(static_cast<unsigned int>(std::time(NULL)));

    unsigned int fate = std::rand() % 100;
    std::cout << CYAN << "Random: " << fate << RESET << "\n";

    std::cout << "\n-----\nVECTORS" << RESET << "\n-----\n";
    for (int i = 0; i < 50; i++) {
        v.clear();
        fillContainer(v, 100);
        easyfind(v, fate);
    }

    std::cout << "\n-----\nDEQUE" << RESET << "\n-----\n";
    for (int i = 0; i < 50; i++) {
        d.clear();
        fillContainer(d, 100);
        easyfind(d, fate);
    }

    std::cout << "\n-----\nLIST" << RESET << "\n-----\n";
    for (int i = 0; i < 50; i++) {
        l.clear();
        fillContainer(l, 100);
        easyfind(l, fate);
    }

    return 0;
}