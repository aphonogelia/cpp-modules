/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:13:58 by htharrau          #+#    #+#             */
/*   Updated: 2025/05/13 12:31:10 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
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
    printSeparator("Trying to instanciate an animal");
    AAnimal* j = new Dog();
    AAnimal* i = new Cat();
    // AAnimal* k = new AAnimal(); error: allocating an object of abstract class type 'AAnimal'
    delete j;
    delete i;
    // delete k;

    // Animal a;
    Dog b;
    Cat c;

    return (0);
}
