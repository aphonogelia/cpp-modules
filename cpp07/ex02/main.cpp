/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:26:18 by htharrau          #+#    #+#             */
/*   Updated: 2026/01/06 14:00:27 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"

#define MAX_VAL 7

int main() {
    /* ============================================================
     * 1) DIFFERENTS TYPES (T)
     * ============================================================ */
    try {
        std::cout << BLUE << "\n[1] Testing different template types\n" << RESET;

        Array<int> intArray(5);
        Array<float> floatArray(5);
        Array<std::string> stringArray(3);

        for (int i = 0; i < 5; i++) {
            intArray[i] = i * 10;
            floatArray[i] = i * 0.5f;
        }
        stringArray[0] = "hello";
        stringArray[1] = "42";
        stringArray[2] = "world";
        // stringArray[3] = "invalid";
        // stringArray[-20] = "invalid";

        std::cout << "intArray    : " << intArray << std::endl;
        std::cout << "floatArray  : " << floatArray << std::endl;
        std::cout << "stringArray : " << stringArray << std::endl;
    } catch (const std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    /* ============================================================
     * 2) CONSTRUCTORS
     * ============================================================ */
    try {
        std::cout << BLUE << "\n[2] Testing constructors\n" << RESET;

        // Default constructor
        Array<int> emptyArray;
        std::cout << "emptyArray (default constructor) size = " << emptyArray.size() << std::endl;

        // Size constructor
        Array<int> array10(10);
        std::cout << "array10 size = " << array10.size() << std::endl;

        // Copy constructor
        Array<int> copy(array10);
        std::cout << "copy = sized size = " << copy.size() << std::endl;

        // Assignment operator
        Array<int> temp20(20);
        temp20[19] = 42;
        std::cout << "temp20 before reassignment: " << temp20 << std::endl;
        temp20 = array10;
        std::cout << "temp20 after reassignment: " << temp20 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    /* ============================================================
     * 3) INVALID
     * ============================================================ */
    try {
        std::cout << BLUE << "\n[3] Testing invalid values\n" << RESET;

        Array<int> invalid(-1);  // should throw
        std::cout << invalid << std::endl;
    } catch (const std::exception &e) {
        std::cerr << RED << "Constructor error: " << e.what() << RESET << std::endl;
    }

    try {
        Array<int> a(5);
        a[-1] = 42;  // invalid index
    } catch (const std::exception &e) {
        std::cerr << RED << "Index error: " << e.what() << RESET << std::endl;
    }

    try {
        Array<int> a(5);
        a[5] = 42;  // invalid index
    } catch (const std::exception &e) {
        std::cerr << RED << "Index error: " << e.what() << RESET << std::endl;
    }

    /* ============================================================
     * 4) SUBJECT MAIN
     * ============================================================ */
    std::cout << BLUE << "\n[4] Subject main test\n" << RESET;

    Array<int> numbers(MAX_VAL);
    int *mirror = new int[MAX_VAL];

    srand(time(NULL));
    // Fill both arrays with the same random values
    std::cout << "mirror : ";
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
        std::cout << mirror[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "numbers : " << numbers << std::endl;

    // Test copy constructor & assignment operator
    {
        Array<int> tmp = numbers;
        Array<int> testassign(tmp);

        std::cout << "tmp : " << tmp << std::endl;
        std::cout << "test : " << testassign << std::endl;
    }
    // Verify deep copy
    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << RED << "ERROR: values differ after copy!" << RESET << std::endl;
            delete[] mirror;
            return 1;
        }
    }

    // Out of bounds access tests
    try {
        numbers[-2] = 0;
    } catch (const std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    try {
        numbers[MAX_VAL] = 0;
    } catch (const std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    delete[] mirror;
    return 0;
}
