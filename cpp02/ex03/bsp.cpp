/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:32:39 by htharrau          #+#    #+#             */
/*   Updated: 2026/01/22 12:38:05 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Line.hpp"
#include "Point.hpp"

bool bsp(Point const &a, Point const &b, Point const &c, Point const &point) {
    std::cout << "Triangle A(" << a.getX() << ", " << a.getY() << "), B(" << b.getX() << ", "
              << b.getY() << "), C(" << c.getX() << ", " << c.getY() << ")." << std::endl;

    std::cout << "Is the point (" << point.getX() << ", " << point.getY()
              << ") inside the triangle?" << std::endl;
    Line AB(a, b);
    Line BC(b, c);
    Line CA(c, a);

    if (AB.coLineaire(c) == true) {
        std::cout << "Fail: The point is not inside the triangle ABC. A, B and C are colineaires."
                  << std::endl;
        return (false);
    } else if (AB.coLineaire(point) || BC.coLineaire(point) || CA.coLineaire(point)) {
        std::cout << "Fail: The point is not inside the triangle ABC. The point is colineaire to "
                     "one of the arret."
                  << std::endl;
        return (false);
    }

    else if (AB.aboveLeft(c) == AB.aboveLeft(point) && BC.aboveLeft(a) == BC.aboveLeft(point) &&
             CA.aboveLeft(b) == CA.aboveLeft(point)) {
        std::cout << "Success: The point is inside the triangle ABC." << std::endl;
        return (true);
    }

    else {
        std::cout << "Fail: The point is not inside the triangle ABC." << std::endl;
        return (false);
    }
}