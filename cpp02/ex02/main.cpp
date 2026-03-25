/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:25:42 by htharrau          #+#    #+#             */
/*   Updated: 2025/05/06 11:43:08 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>

#include "Fixed.hpp"

// SMALLEST STEP : 1/2^8 = 1/256 ≈ 0.00390625
// 1.001 * 2^8 = 256.256 rounded to 256.

int main(void) {
    Fixed q(1.025f);
    Fixed p(1000.025f);
    Fixed w(100000.025f);
    Fixed n(1000000.025f);
    std::cout << std::fixed << q << std::endl;
    std::cout << std::fixed << p << std::endl;
    std::cout << std::fixed << w << std::endl;
    std::cout << std::fixed << n << std::endl;

    // std::cout <<  std::fixed << q.toFloat() <<std::endl;
    // std::cout <<  std::fixed << p.toFloat() <<std::endl;
    // std::cout <<  std::fixed << w.toFloat() <<std::endl;
    // std::cout <<  std::fixed << n.toFloat() <<std::endl;

    std::cout << "=== Overflowing bit by bit ===" << std::endl;

    Fixed myInt(8388607.5555555f);
    std::cout << std::fixed << myInt.toFloat() << std::endl;

    try {
        Fixed myInt(8388607);
        for (int i = 240; i < 270; i++) std::cout << myInt + Fixed(i * 0.00390625f) << std::endl;
    } catch (...) {
        std::cout << "Exception caught !" << std::endl;
    }

    try {
        Fixed myFloat(-8388607.705f);
        for (int i = 100; i < 270; i++) std::cout << myFloat - Fixed(i * 0.00390625f) << std::endl;
    } catch (...) {
        std::cout << "Exception caught !" << std::endl;
    }

    std::cout << "=== Basic Construction ===" << std::endl;
    Fixed a(42);        // int constructor
    Fixed b(3.14159f);  // float constructor
    Fixed c(a);         // copy constructor
    Fixed d;            // default constructor
    std::cout << "a (int): " << a.toFloat() << " (int: " << a.toInt() << ")\n";
    std::cout << "b (float): " << b.toFloat() << " (int: " << b.toInt() << ")\n";
    std::cout << "c (copy of a): " << c.toFloat() << " (int: " << c.toInt() << ")\n";
    std::cout << "d (default): " << d.toFloat() << " (int: " << d.toInt() << ")\n\n";

    std::cout << "=== Arithmetic Operators ===" << std::endl;
    Fixed e = a + b;
    Fixed f = a - b;
    Fixed g = a * b;
    Fixed h = a / b;
    std::cout << "a + b = " << e.toFloat() << "\n";
    std::cout << "a - b = " << f.toFloat() << "\n";
    std::cout << "a * b = " << g.toFloat() << "\n";
    std::cout << "a / b = " << h.toFloat() << "\n\n";

    std::cout << "=== Compound Assignment Operators ===" << std::endl;
    Fixed x(10.5f);
    x += Fixed(2.25f);
    std::cout << "x += 2.25 -> " << x.toFloat() << "\n";
    x -= Fixed(1.75f);
    std::cout << "x -= 1.75 -> " << x.toFloat() << "\n";
    x *= Fixed(3);
    std::cout << "x *= 3 -> " << x.toFloat() << "\n";
    x /= Fixed(2);
    std::cout << "x /= 2 -> " << x.toFloat() << "\n\n";

    std::cout << "=== Edge Cases ===" << std::endl;
    try {
        Fixed max(8388607);
        Fixed one(1);
        std::cout << "max + one (should overflow and exit): " << std::endl;
        Fixed result = max + one;  // This should trigger overflow and exit
        std::cout << "Result: " << result.toFloat() << std::endl;
    } catch (...) {
        std::cout << "Exception caught !" << std::endl;
    }
    try {
        Fixed zero;
        std::cout << "b / zero (should division by zero and exit): " << std::endl;
        Fixed divzero = b / zero;
        std::cout << "Result: " << divzero.toFloat() << std::endl;
    } catch (...) {
        std::cout << "Exception caught !" << std::endl;
    }

    return (0);
}