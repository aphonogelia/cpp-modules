/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:26:18 by htharrau          #+#    #+#             */
/*   Updated: 2026/03/26 10:07:45 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <deque>
#include <list>
#include <set>

#include "Span.hpp"

int main() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    /* ── subject ── */
    std::cout << MAGENTA << "\n---------------\nSUBJECT"
              << "\n---------------\n"
              << RESET;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.printContainer();
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    /* ── container overflow exception ── */
    std::cout << MAGENTA << "\n---------------\nEXCEPTION: span full\n---------------\n" << RESET;
    try {
        sp.addNumber(10);
    } catch (const std::exception &e) {
        std::cout << YELLOW << "caught: " << e.what() << RESET << "\n";
    }

    /* ── int overflow test ── */
    std::cout << MAGENTA << "\n---------------\nINT OVERFLOW TEST\n---------------\n" << RESET;
    Span spOF = Span(5);
    spOF.addNumber(std::numeric_limits<int>::max());
    spOF.addNumber(std::numeric_limits<int>::min());
    spOF.printContainer();
    std::cout << "Shortest span: " << spOF.shortestSpan() << std::endl;
    std::cout << "Longest span: " << spOF.longestSpan() << std::endl;

    /* ── no span exception ── */
    std::cout << MAGENTA << "\n---------------\nEXCEPTION: too few elements\n---------------\n"
              << RESET;
    try {
        Span sp_empty(1);
        sp_empty.addNumber(42);
        sp_empty.shortestSpan();
    } catch (const std::exception &e) {
        std::cout << YELLOW << "caught: " << e.what() << RESET << "\n";
    }

    /* ── addRange from list, set, deque → Span(200) ── */
    std::cout << MAGENTA
              << "\n---------------\nADDRANGE: list + set + deque -> Span(200)\n---------------\n"
              << RESET;

    std::list<int> myList;
    std::set<int> mySet;
    std::deque<int> myDeque;

    for (int i = 0; i < 50; i++) myList.push_back(std::rand() % 10000);
    for (int i = 0; i < 50; i++) mySet.insert(std::rand() % 10000);
    for (int i = 0; i < 50; i++) myDeque.push_back(std::rand() % 10000);

    Span sp2(200);
    sp2.addRange(myList.begin(), myList.end());
    sp2.printContainer();
    sp2.addRange(mySet.begin(), mySet.end());
    sp2.printContainer();
    sp2.addRange(myDeque.begin() + 25, myDeque.end());
    sp2.printContainer();

    std::cout << "Elements added: 125 (50 list, 50 set, 25 deque)\n";
    std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest span:  " << sp2.longestSpan() << std::endl;

    /* ── 100 000 values ── */
    std::cout << MAGENTA << "\n---------------\n100 000 VALUES\n---------------\n" << RESET;

    std::vector<int> big;
    big.reserve(100000);
    for (int i = 0; i < 100000; i++) big.push_back(std::rand());

    Span sp3(100000);
    sp3.addRange(big.begin(), big.end());

    std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
    std::cout << "Longest span:  " << sp3.longestSpan() << std::endl;

    return 0;
}