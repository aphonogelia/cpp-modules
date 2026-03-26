/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:08:33 by htharrau          #+#    #+#             */
/*   Updated: 2026/03/24 18:01:59 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define RESET "\033[0m"

class Span {
   private:
    unsigned int N;
    std::vector<int> container;

   public:
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    long shortestSpan() const;
    long longestSpan() const;
    void addNumber(int number);
    void printContainer() const;

    /* for convenience :
     it works with any range (source.begin() + 100, source.begin() + 200)),
     And with any container type (lists, sets, arrays, anything with iterators) */
    template <typename Iter>
    void addRange(Iter first, Iter last) {
        while (first != last) {
            addNumber(*first);
            ++first;
        }
    }
};
