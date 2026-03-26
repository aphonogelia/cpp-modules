/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:08:33 by htharrau          #+#    #+#             */
/*   Updated: 2026/01/06 12:50:37 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>


#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define RESET "\033[0m"

// explicit Array(unsigned int n); // to avoid implicit conversion -1 -> 1844674407
// The conversion from -1 to unsigned int happens before the constructor is called, 
// so explicit can't stop it.


// int* a = new int();    // Allocates memory for one int, Initializes that one int to 0
// int* b = new int;      // Default-initialized (uninitialized, garbage value)
// int* c = new int(42);  // Initialized to 42

// int* a = new int[10];      // NOT initialized (garbage values)
// int* b = new int[10]();    // Value-initialized (all zeros)


// Primitive types (int, double, char, etc.)
// int* a = new int;       // Garbage
// int* b = new int();     // 0
// int* arr = new int[5];  // All garbage

// std::string behaves differently because it's a class type, not a primitive type.
// Class Types Are Always Initialized
// When you use new with class types, their constructors are called, which handle initialization.
// Class types (std::string, std::vector, your custom classes)
// std::string* s = new std::string;           // "" 
// std::string* t = new std::string();         // "" 
// std::string* arr = new std::string[5];      // All "" 


template <typename T>
class Array {

	private:
		T* myArray;
		unsigned int mySize;

	public:
		Array();
		Array(unsigned int n); 
		Array(const Array&);
		Array& operator=(const Array&);
		~Array();

		T& operator[](unsigned int index);
		unsigned int size() const;
};


template <typename T>
std::ostream& operator<<(std::ostream &os, Array<T>& arr);