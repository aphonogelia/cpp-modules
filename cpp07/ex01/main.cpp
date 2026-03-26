/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:26:18 by htharrau          #+#    #+#             */
/*   Updated: 2025/09/21 18:25:20 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
    int arrInt[] = {-9, 78, 630, 1};
    float arrFloat[] = {-9.6f, 78.2f, 630.0f, 1.123456789f};
    std::string arrString[] = {"asd", "grand", "foo", "bar"};

    const int constArrInt[] = {-9, 78, 630, 1};
    // const float constArrFloat[] = {-9.6f, 78.2f, 630.0f, 1.123456789f};
    const std::string constArrString[] = {"asd", "grand", "foo", "bar"};

    std::cout << BLUE << "<<<<<< non const arrays - print, change sign, print >>>>>>>" << RESET
              << std::endl;

    std::cout << YELLOW << "int" << RESET << std::endl;
    iter(arrInt, sizeof(arrInt) / sizeof(arrInt[0]), print<int>);
    iter(arrInt, sizeof(arrInt) / sizeof(arrInt[0]), changeSign<int>);
    iter(arrInt, sizeof(arrInt) / sizeof(arrInt[0]), print<int>);
    std::cout << YELLOW << "float" << RESET << std::endl;
    iter(arrFloat, sizeof(arrFloat) / sizeof(arrFloat[0]), print<float>);
    iter(arrFloat, sizeof(arrFloat) / sizeof(arrFloat[0]), changeSign<float>);
    iter(arrFloat, sizeof(arrFloat) / sizeof(arrFloat[0]), print<float>);
    std::cout << YELLOW << "string" << RESET << std::endl;
    iter(arrString, sizeof(arrString) / sizeof(arrString[0]), print<std::string>);
    // iter(arrString, sizeof(arrString) / sizeof(arrString[0]), changeSign<std::string>);

    std::cout << BLUE << "<<<<<< const arrays - print, change sign, print >>>>>>>" << RESET
              << std::endl;

    std::cout << YELLOW << "int" << RESET << std::endl;
    iter(constArrInt, sizeof(constArrInt) / sizeof(constArrInt[0]), print<int>);
    // iter(constArrInt, sizeof(constArrInt) / sizeof(constArrInt[0]), changeSign<int>);
    std::cout << YELLOW << "string" << RESET << std::endl;
    iter(constArrString, sizeof(constArrString) / sizeof(constArrString[0]), print<std::string>);
    // iter(constArrString, sizeof(constArrString) / sizeof(constArrString[0]),
    // changeSign<std::string>);

    return 0;
}