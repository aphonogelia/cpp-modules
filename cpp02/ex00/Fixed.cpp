/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:32:43 by htharrau          #+#    #+#             */
/*   Updated: 2025/05/01 16:21:46 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : integer(0) { std::cout << "Default constructor called" << std::endl; }

// Fixed::Fixed(int integer) : integer(integer) {
// 	std::cout << "Int constructor called" << std::endl;
// }

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed(const Fixed& other) : integer(other.integer) {
    std::cout << "Copy constructor called" << std::endl;
    this->integer = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->integer = other.getRawBits();
    }
    return (*this);
}

// retourne la partie entiere sans la convertir.
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->integer);
}

// initialise la partie entiere avec celle passée en paramètre.
void Fixed::setRawBits(int const raw) { this->integer = raw; }
