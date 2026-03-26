/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:26:18 by htharrau          #+#    #+#             */
/*   Updated: 2026/03/25 21:21:43 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define RESET "\033[0m"

#include <iostream>
#include <list>
#include <vector>

#include "MutantStack.hpp"

int main() {
    /* ── subject ── */
    std::cout << MAGENTA << "\n--- SUBJECT ---\n" << RESET;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top:  " << mstack.top() << "\n";
    mstack.pop();
    std::cout << "size: " << mstack.size() << "\n";
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) std::cout << *it++ << " ";
    std::cout << "\n";
    std::stack<int> s(mstack);

    /* ── stack functions ── */
    std::cout << MAGENTA << "\n--- STACK FUNCTIONS ---\n" << RESET;
    std::cout << "empty: " << (mstack.empty() ? "true" : "false") << "\n";
    std::cout << "size:  " << mstack.size() << "\n";
    std::cout << "top:   " << mstack.top() << "\n";
    mstack.pop();
    std::cout << "top after pop: " << mstack.top() << "\n";

    /* ── iterators: forward, reverse, const ── */
    std::cout << MAGENTA << "\n--- ITERATORS ---\n" << RESET;
    MutantStack<int> ms;
    ms.push(1);
    ms.push(2);
    ms.push(3);
    ms.push(4);
    ms.push(5);

    std::cout << "forward:        ";
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it) std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "reverse:        ";
    for (MutantStack<int>::reverse_iterator it = ms.rbegin(); it != ms.rend(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    const MutantStack<int> cms(ms);
    std::cout << "const forward:  ";
    for (MutantStack<int>::const_iterator it = cms.begin(); it != cms.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "const reverse:  ";
    for (MutantStack<int>::const_reverse_iterator it = cms.rbegin(); it != cms.rend(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    /* ── comparison with list, deque, vector ── */
    std::cout << MAGENTA << "\n--- COMPARISON WITH LIST / DEQUE / VECTOR ---\n" << RESET;

    MutantStack<int> myMutant;
    std::list<int> myList;
    std::deque<int> myDeque;
    std::vector<int> myVector;

    for (int i = 1; i <= 5; i++) {
        myMutant.push(i * 10);
        myList.push_back(i * 10);
        myDeque.push_back(i * 10);
        myVector.push_back(i * 10);
    }

    std::cout << "MutantStack: ";
    for (MutantStack<int>::iterator it = myMutant.begin(); it != myMutant.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "std::list:   ";
    for (std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "std::deque:  ";
    for (std::deque<int>::iterator it = myDeque.begin(); it != myDeque.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "std::vector: ";
    for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    return 0;
}
