/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:18:10 by htharrau          #+#    #+#             */
/*   Updated: 2025/09/21 16:25:20 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main() {
    {
        std::cout << BLUE << "<<<<<< swap FUNCTION >>>>>>>" << RESET << std::endl;
        int x = 5;
        int y = 30;
        std::cout << "x: " << x << ", y: " << y << std::endl;
        swap(x, y);
        std::cout << "new x: " << x << ", new y: " << y << std::endl;

        std::string str1 = "First string";
        std::string str2 = "Second string";
        std::cout << "str1: " << str1 << ", str2: " << str2 << std::endl;
        swap(str1, str2);
        std::cout << "new str1: " << str1 << ", new str2: " << str2 << std::endl;

        std::cout << BLUE << "<<<<<< min FUNCTION >>>>>>>" << RESET << std::endl;
        std::cout << min(5, 10) << std::endl;
        std::cout << min(3.4545, 3.4546) << std::endl;
        std::cout << min("TEST1", "TEST2") << std::endl;

        std::cout << BLUE << "<<<<<< max FUNCTION >>>>>>>" << RESET << std::endl;
        std::cout << max(5, 10) << std::endl;
        std::cout << max(3.4545, 3.4546) << std::endl;
        std::cout << max("TEST1", "TEST2") << std::endl;
    }

    {
        std::cout << BLUE << "<<<<<< FROM SUBJECT >>>>>>>" << RESET << std::endl;
        int a = 2;
        int b = 3;
        ::swap(a, b);
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
        std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
        std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
    }

    return 0;
}