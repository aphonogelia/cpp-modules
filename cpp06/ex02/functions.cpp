/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:10:44 by htharrau          #+#    #+#             */
/*   Updated: 2025/06/07 17:10:27 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*******************************************************************************
Run-Time Type Information:
C++ feature that allows you to determine the actual type of an object during pro-
gram execution, even if you only have a pointer or reference to a base class.
RTTI provides:
- dynamic_cast (for safe downcasting)
- typeid (to get the exact type info)
- std::type_info (the object returned by typeid)
RTTI only works for polymorphic classes (classes with at least one virtual fct)
*******************************************************************************/

#include "functions.hpp"

// randomly instantiates A, B, or C and returns the instance as a Base pointer.
Base* generate(void) {
    std::srand(std::time(NULL));

    int a = std::rand();

    if (a % 3 == 0) {
        std::cout << "generate() returns an A pointer." << std::endl;
        return (new A());
    } else if (a % 3 == 1) {
        std::cout << "generate() returns an B pointer." << std::endl;
        return (new B());
    } else if (a % 3 == 2) {
        std::cout << "generate() returns an C pointer." << std::endl;
        return (new C());
    }
    return (NULL);
}

// dynamic_cast on a pointer: If the cast fails, it returns a nullptr
void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "class A object" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "class B object" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "class C object" << std::endl;
}

// dynamic_cast on a reference: If the cast fails, it throws a std::bad_cast exception.
// the bad_cast exception is from typeinfo that we cant use.
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "class A object" << std::endl;
        return;
    } catch (...) {
    }
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "class B object" << std::endl;
        return;
    } catch (...) {
    }
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "class C object" << std::endl;
        return;
    } catch (...) {
    }
}