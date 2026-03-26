/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:08:33 by htharrau          #+#    #+#             */
/*   Updated: 2026/03/26 11:17:40 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
std::sort uses introsort, a hybrid of:
   + quicksort — average O(n log n), fast in practice
   + heapsort — kicks in if recursion depth gets too deep, guarantees O(n log n)
         worst case
   + insertion sort — used for small partitions (typically n < 16), very fast on
         nearly-sorted small arrays
*/

#include "Span.hpp"

Span::Span(unsigned int n) : N(n) { container.reserve(N); }

Span::Span(const Span& other) : N(other.N) { container = other.container; }

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        N = other.N;
        container = other.container;
    }
    return *this;
}

Span::~Span() {}

long Span::shortestSpan() const {
    if (container.size() < 2) {
        throw std::runtime_error("Less than 2 numbers: no span available");
    }
    std::vector<int> sorted = container;
    std::sort(sorted.begin(), sorted.end());
    long min_diff = static_cast<long>(sorted[1]) - sorted[0];
    for (size_t i = 0; i < sorted.size() - 1; ++i) {
        long diff = static_cast<long>(sorted[i + 1]) - sorted[i];
        if (diff < min_diff) {
            min_diff = diff;
        }
    }
    return min_diff;
}

/* std::min_element returns an iterator to the smallest element  -> needs deference */
long Span::longestSpan() const {
    if (container.size() < 2) {
        throw std::runtime_error("Less than 2 numbers: no span available");
    }
    long min_val = *std::min_element(container.begin(), container.end());
    long max_val = *std::max_element(container.begin(), container.end());
    return (max_val - min_val);
}

void Span::addNumber(int number) {
    if (container.size() >= N) {
        throw std::runtime_error("Could not add the new integer (span is full)");
    }
    container.push_back(number);
}

void Span::printContainer() const {
    std::cout << "Container: ";
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}
