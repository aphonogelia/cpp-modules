/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:02:43 by htharrau          #+#    #+#             */
/*   Updated: 2025/05/12 15:38:52 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/////////////////////////////
// 	CONDESTRUCTORS		//
/////////////////////////////

Brain::Brain() { std::cout << "Brain: Default constructor called" << std::endl; }

Brain::Brain(const Brain& other) {
    std::cout << "Brain: Copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++) ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain: Copy assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++) ideas[i] = other.ideas[i];
    }
    return (*this);
}

Brain::~Brain() { std::cout << "Brain Destructor called." << std::endl; }

/////////////////////////////
// 	  FUNCTIONS			//
/////////////////////////////

std::string Brain::getIdea(int i) {
    if (i >= 0 && i < 100) return (ideas[i]);
    return ("");
}

void Brain::setIdea(int i, const std::string& input) {
    if (i >= 0 && i < 100) ideas[i] = input;
}
