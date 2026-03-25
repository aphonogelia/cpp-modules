/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:33:03 by htharrau          #+#    #+#             */
/*   Updated: 2025/06/07 14:49:13 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int main() {
    Data test;
    test.name = "Greta";
    test.number = 5;

    std::cout << "Pointer &test: " << &test << std::endl;
    std::cout << "Data: name = " << test.name << ", number = " << test.number << std::endl;

    uintptr_t unsignedint = Serializer::serialize(&test);
    std::cout << "Serialized (uintptr_t): " << unsignedint << std::endl;

    Data* ptr = Serializer::deserialize(unsignedint);
    std::cout << "Deserialized pointer: " << ptr << std::endl;
    std::cout << "Deserialized data: n = " << ptr->name << ", s = " << ptr->number << std::endl;

    return 0;
}