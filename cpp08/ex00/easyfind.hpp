/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:08:33 by htharrau          #+#    #+#             */
/*   Updated: 2026/03/24 17:15:36 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define RESET "\033[0m"

/* std::find

Return value:
- if found an iterator to the element,
- if not it returns the end iterator a.end()

Optimal / suboptimal:
- std::vector, std::deque, std::list → fine
- std::map, std::set → suboptimal (O(n) instead of O(log n))
(associative containers - we ignore them)

*/

template <typename T>
void easyfind(T &a, const int value) {
    try {
        typename T::iterator it;
        it = std::find(a.begin(), a.end(), value);
        if (it != a.end())
            std::cout << MAGENTA << "found at pos " << std::distance(a.begin(), it) << RESET
                      << "\n";
        else
            throw std::runtime_error("Value not found in container");
    } catch (const std::runtime_error &e) {
        std::cout << YELLOW << "exception: " << e.what() << RESET << "\n";
    }
}

// helper function for testing

template <typename T>
void fillContainer(T &a, int size) {
    for (int i = 0; i < size; i++) {
        a.push_back(std::rand() % size);
    }
}
