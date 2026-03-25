/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:14:27 by htharrau          #+#    #+#             */
/*   Updated: 2025/01/12 14:14:28 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*******************************************************************************
 Write a program that contains:
• A string variable initialized to "HI THIS IS BRAIN".
• stringPTR: a pointer to the string.
• stringREF: a reference to the string.

Your program must print:
• The memory address of the string variable.
• The memory address held by stringPTR.
• The memory address held by stringREF.

And then:
• The value of the string variable.
• The value pointed to by stringPTR.
• The value pointed to by stringREF
*******************************************************************************/

#include <iostream>
#include <string>

int main(void) {
    std::string mystring;
    std::string* mystringPTR;
    std::string& mystringREF = mystring;

    mystring = "HI THIS IS BRAIN";
    mystringPTR = &mystring;

    std::cout << std::endl;

    std::cout << "Address of the string: " << &mystring << std::endl;
    std::cout << "Address held by stringPTR: " << mystringPTR << std::endl;
    std::cout << "Address held by stringREF: " << &mystringREF << std::endl;

    std::cout << std::endl;

    std::cout << "Value of the string: " << mystring << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *mystringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << mystringREF << std::endl;

    std::cout << std::endl;

    return (0);
}