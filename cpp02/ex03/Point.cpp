/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:32:42 by htharrau          #+#    #+#             */
/*   Updated: 2026/01/22 12:43:57 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#include "Fixed.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(Fixed i, Fixed j) : x(i), y(j) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

bool Point::operator!=(const Point& other) const {
    return (this->x != other.x || this->y != other.y);
}

Point& Point::operator=(const Point&) { return (*this); }

Point::~Point() {}

Fixed Point::getX() const { return (x); }

Fixed Point::getY() const { return (y); }
