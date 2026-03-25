/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:09:27 by htharrau          #+#    #+#             */
/*   Updated: 2025/05/01 15:48:13 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : integer(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const int inputInt) : integer(inputInt << dec_bit) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float inputFloat) : integer(roundf(inputFloat * (1 << dec_bit))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : integer(other.integer) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->integer = other.integer;
    }
    return (*this);
}

// int Fixed::getRawBits(void) const {
// 	std::cout << "getRawBits member function called" << std::endl;
// 	return (this->integer);
// }

// void Fixed::setRawBits(int const raw) {
// 	this->integer = raw;
// }

float Fixed::toFloat(void) const { return (static_cast<float>(integer) / (1 << dec_bit)); }

int Fixed::toInt(void) const { return (integer >> dec_bit); }

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed) {
    stream << fixed.toFloat();
    return (stream);
}
