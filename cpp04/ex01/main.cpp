/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:13:58 by htharrau          #+#    #+#             */
/*   Updated: 2025/05/13 12:06:17 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

/*******************************************************************************
When you create a Dog object in C++, the order of construction is strictly defi-
ned by the language rules. Here is the sequence:
- Base Class Constructor: The constructor for the base class is called first.
- Member Objects: After the base class, all non-static data members (like Brain)
are constructed, in the order they are declared in the class definition.
- Derived Class Constructor Body: Finally, the body of the derived class's cons-
tructor (Dog) is executed
*******************************************************************************/

void printSeparator(const std::string& title) {
    std::cout << "\n===== " << title << " =====\n" << std::endl;
}

int main(void) {
    printSeparator("Main from subject");
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    printSeparator("Basic Brain idea usage in Dog and Cat");
    Dog felix;
    Cat garfield;
    felix.setIdea(5, "Fetch me a Wurst");
    garfield.setIdea(0, "You are a bad slave");
    garfield.setIdea(200, "Out of range");
    std::cout << "felix idea 0: " << felix.getIdea(0) << std::endl;
    std::cout << "felix idea 5: " << felix.getIdea(5) << std::endl;
    std::cout << "garfield idea 0: " << garfield.getIdea(0) << std::endl;
    std::cout << "garfield idea out of range : " << garfield.getIdea(200) << std::endl;
    felix.setIdea(5, "A leberwurst");
    std::cout << "felix changed idea 5: " << felix.getIdea(5) << std::endl;

    printSeparator("Deep copy: Copy constructor and Assignment operator");
    Dog felixbis(felix);
    Cat garfieldbis = garfield;
    std::cout << "felixbis idea 5 (after copy): " << felixbis.getIdea(5) << std::endl;
    std::cout << "garfieldbis idea 0 (after copy): " << garfieldbis.getIdea(0) << std::endl;
    felixbis.setIdea(5, "Jumping");
    garfieldbis.setIdea(0, "Napping");
    std::cout << "felix idea 5 (should be unchanged): " << felix.getIdea(5) << std::endl;
    std::cout << "felixbis idea 5 (changed): " << felixbis.getIdea(5) << std::endl;
    std::cout << "garfield idea 0 (should be unchanged): " << garfield.getIdea(0) << std::endl;
    std::cout << "garfieldbis idea 0 (changed): " << garfieldbis.getIdea(0) << std::endl;

    printSeparator("Array of Animals with Brains");
    const int size = 4;
    Animal* animals[size];
    for (int i = 0; i < size / 2; i++) animals[i] = new Dog();
    for (int i = size / 2; i < size; i++) animals[i] = new Cat();
    for (int i = 0; i < size; ++i) animals[i]->makeSound();

    // Set and get ideas through base pointers (requires virtual or public interface in Animal)
    Dog* asDog = dynamic_cast<Dog*>(animals[0]);
    Cat* asCat = dynamic_cast<Cat*>(animals[2]);
    if (asDog) asDog->setIdea(1, "I want to play!");
    if (asCat) asCat->setIdea(1, "I want to climb!");
    if (asDog) std::cout << "animals[0] dog idea 1: " << asDog->getIdea(1) << std::endl;
    if (asCat) std::cout << "animals[2] cat idea 1: " << asCat->getIdea(1) << std::endl;

    for (int i = 0; i < size; ++i) delete animals[i];

    return (0);
}
