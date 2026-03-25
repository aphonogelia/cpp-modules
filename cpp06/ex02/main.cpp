/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:51:15 by htharrau          #+#    #+#             */
/*   Updated: 2025/06/07 17:24:37 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

int main(void) {
    Base *a = generate();
    identify(a);
    identify(*a);
    delete a;

    std::cout << ">> test class A" << std::endl;
    A r;
    identify(&r);
    identify(r);

    std::cout << ">> test class B" << std::endl;
    B s;
    identify(&s);
    identify(s);

    std::cout << ">> test class C" << std::endl;
    C t;
    identify(&t);
    identify(t);

    return (0);
}
