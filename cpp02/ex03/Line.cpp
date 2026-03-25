/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Line.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:37:19 by htharrau          #+#    #+#             */
/*   Updated: 2026/01/22 12:40:07 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Line.hpp"

#include "Fixed.hpp"
#include "Point.hpp"

Line::Line() : p1(), p2(), m(0), b(0), vertical(false) {}

Line::Line(Point i, Point j) : p1(i), p2(j), m(0), b(0), vertical(false) {
    if (Fixed::absFixed(p1.getX(), p2.getX()) < Fixed(EPSILON))
        vertical = true;

    else {
        m = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
        b = p1.getY() - m * p1.getX();
    }
    std::cout << "y = " << m << " * x + (" << b << ")" << std::endl;
}

Line& Line::operator=(const Line& other) {
    if (this != &other) {
        this->p1 = other.p1;
        this->p2 = other.p2;
        this->m = other.m;
        this->b = other.b;
        this->vertical = other.vertical;
    }
    return (*this);
}

Line::~Line() {}

bool Line::coLineaire(Point k) const {
    if (vertical == false) {
        Fixed tempY = m * k.getX() + b;
        return (Fixed::absFixed(tempY, k.getY()) < Fixed(EPSILON));
    } else  // if (vertical == true)
        return (Fixed::absFixed(p1.getX(), k.getX()) < Fixed(EPSILON));
}

bool Line::aboveLeft(Point k) const {
    if (vertical == false) {
        Fixed tempY = m * k.getX() + b;
        return (k.getY() > tempY);
    } else  // vertical == true
        return (p1.getX() > k.getX());
}