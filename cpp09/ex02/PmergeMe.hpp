/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:05:10 by htharrau          #+#    #+#             */
/*   Updated: 2026/04/04 16:11:40 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
#include <deque>
#include <algorithm>
#include <sys/time.h>

class PmergeMe {

private:
    std::vector<int> _dataVect;
    std::deque<int> _dataDeq;
    std::vector<int> _sortedVect;
    size_t _nComp;
    size_t _n;
    std::vector<int> _expJacob;

    std::vector<int> sortAlgoV(std::vector<int> a);
    std::vector<int> calcJacobsthal() const;
    void printPairs(const std::vector<std::pair<int, int> >& pairs) const;
    void printVect(const std::vector<int>& vec, const std::string& label);
    void binaryInsert(std::vector<int>& sorted, size_t upperBound, int loser);
    bool isSorted(const std::vector<int>& vec) const;
    void verif();


public:
    PmergeMe(const std::vector<int>& dataV, const std::deque<int>& dataD);
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
};
