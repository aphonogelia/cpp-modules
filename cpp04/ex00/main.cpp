/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:13:58 by htharrau          #+#    #+#             */
/*   Updated: 2025/05/12 12:59:16 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// SMART POINTERS: from C++11
// You Cannot Use std::shared_ptr or std::unique_ptr in C++98
// These are only available starting from C++11.

// POLYMORPHISM
// Dog inherits from Animal.
// new Dog("Dodo") creates a Dog object on the heap.
// const Animal* dodo is a pointer to Animal, but it points to a Dog object.
// This is called polymorphism. It means you can use a base class pointer or ref
// erence (Animal*) to point to any object of a derived class (Dog, Cat, etc.).

// STATIC vs DYNAMIC BINDING
// Without virtual, C++ uses static binding: the function called depends on the
// type of the pointer/reference, not the actual object type.
// With virtual, C++ uses dynamic binding (runtime polymorphism): the function
// called depends on the actual object type.

int main(void) {
    std::cout << "\n<<<<< Wrong polymorphism (slicing): animal = dog >>>>>" << std::endl;
    Animal doggo = Dog();
    std::cout << doggo.getType() << std::endl;
    doggo.makeSound();
    // Without pointers or references, if you store objects by value (e.g., Ani-
    // mal dog = Dog();), you get object slicing: only the base part (Animal) is
    // kept, and the derived part (Dog) is lost. prints CHEEEEP

    std::cout << "\n<<<<< True polymorphism: pointing >>>>>" << std::endl;
    const Animal* dodo = new Dog("Dodo");
    std::cout << dodo->getType() << std::endl;
    dodo->makeSound();
    const Animal* kitty = new Cat("Kitty");
    std::cout << kitty->getType() << std::endl;
    kitty->makeSound();
    delete dodo;  // delete before reassignment otherwise leak. points now to invalid memory
    dodo = kitty;
    std::cout << dodo->getType() << std::endl;
    dodo->makeSound();
    delete kitty;
    // delete dodo; No car points to Kitty, double free -> segfault

    std::cout << "\n<<<<< Animal Class is not abstract >>>>>" << std::endl;
    const Animal* meta = new Animal();
    std::cout << meta->getType() << std::endl;
    meta->makeSound();  // would fail if the class was abstract
    delete meta;

    std::cout << "\n<<<<< Direct use of derived class >>>>>" << std::endl;
    Dog directDog("DirectDog");
    // const Animal* directDog = new Animal();
    directDog.makeSound();

    std::cout << "\n<<<<< Wrong test - STATIC BINDING>>>>>" << std::endl;
    const WrongAnimal* ostrich = new WrongAnimal();
    const WrongAnimal* bad_kitty = new WrongCat();
    std::cout << bad_kitty->getType() << " " << std::endl;
    bad_kitty->makeSound();  // will notoutput the cat sound!
    ostrich->makeSound();
    delete bad_kitty;
    delete ostrich;

    std::cout << "\n<<<<< Wrong Cat: Direct use of derived class - STATIC BINDING>>>>>"
              << std::endl;
    WrongCat wc;
    wc.makeSound();  // Should print WrongCat's sound if overridden

    return (0);
}