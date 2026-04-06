/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:04:51 by htharrau          #+#    #+#             */
/*   Updated: 2026/04/03 15:10:51 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ************************************************************************** */
/*   Coplien                                                                   */
/* ************************************************************************** */

PmergeMe::PmergeMe(const std::vector<int>& dataV, const std::deque<int>& dataD)
    : _dataVect(dataV), _dataDeq(dataD) {

    struct timeval startV, endV, startD, endD;
    _n = _dataVect.size();
    _nCompV = 0;
    _nCompD = 0;

    _expJacob = calcJacobsthal();
    printVect(_expJacob, "Exp Jacobsthal");

    std::vector<int> toSliceV = _dataVect;
    std::deque<int>  toSliceD = _dataDeq;

    printVect(_dataVect, "Before");

    gettimeofday(&startV, NULL);
    _sortedVect = sortAlgoV(toSliceV);
    gettimeofday(&endV, NULL);

    gettimeofday(&startD, NULL);
    _sortedDeq = sortAlgoD(toSliceD);
    gettimeofday(&endD, NULL);

    printVect(_sortedVect, "Sorted");

    double vectTime = (endV.tv_sec - startV.tv_sec) * 1000000.0
        + (endV.tv_usec - startV.tv_usec);
    double deqTime = (endD.tv_sec - startD.tv_sec) * 1000000.0
        + (endD.tv_usec - startD.tv_usec);

    std::cout << "Time to process a range of " << _n
        << " elements with std::vector : " << vectTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _n
        << " elements with std::deque  : " << deqTime << " us" << std::endl;


    std::cout << "Number of comparisons (vector): " << _nCompV << std::endl;
    std::cout << "Number of comparisons (deque) : " << _nCompD << std::endl;
    verif(_sortedVect, _dataVect);
    verif(_sortedDeq, _dataDeq);
}

PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _dataVect = other._dataVect;
        _dataDeq = other._dataDeq;
        _sortedVect = other._sortedVect;
        _sortedDeq = other._sortedDeq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

/* ************************************************************************** */
/*   Sort - vector                                                             */
/* ************************************************************************** */

std::vector<int> PmergeMe::sortAlgoV(std::vector<int> toSlice) {

    // 1 element, already sorted
    if (toSlice.size() < 2)
        return toSlice;

    // ── Slicing down ─────────────────────────────────────────────────────────

    // checking for orphans (vector size odd)
    int orphan = -1;
    if (toSlice.size() % 2 != 0) {
        orphan = toSlice.back();
        toSlice.pop_back();
    }

    // storing the pairs (bigger, smaller)
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < toSlice.size(); i += 2) {
        if (toSlice[i] > toSlice[i + 1])
            pairs.push_back(std::make_pair(toSlice[i], toSlice[i + 1]));
        else
            pairs.push_back(std::make_pair(toSlice[i + 1], toSlice[i]));
    }
    _nCompV += toSlice.size() / 2;

    // recursive call on the winners
    std::vector<int> toSliceNext;
    for (size_t i = 0; i < pairs.size(); i++)
        toSliceNext.push_back(pairs[i].first);
    // printVect(toSliceNext, "Current winners");
    toSliceNext = sortAlgoV(toSliceNext);

    // ── Inserting up ─────────────────────────────────────────────────────────

    // top in one vector, bottom in another
    std::vector<int>  orderedUpper = toSliceNext;
    std::vector<int>  unorderedLower;
    std::vector<bool> used(pairs.size(), false);

    for (size_t i = 0; i < orderedUpper.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (!used[j] && pairs[j].first == orderedUpper[i]) {
                unorderedLower.push_back(pairs[j].second);
                used[j] = true;
                break;
            }
        }
    }
    // orphan has no partner: -1 sentinel triggers full chain search
    if (orphan != -1) {
        unorderedLower.push_back(orphan);
        orderedUpper.push_back(-1);
    }
    // printVect(orderedUpper,    "orderedUpper");
    // printVect(unorderedLower,  "unorderedLower");

    // jacobSthal sequence limited to the length on unorderedLower
    std::vector<int> currentExpJacob;
    for (size_t k = 0; k < _expJacob.size(); k++) {
        if (_expJacob[k] < (int)unorderedLower.size())
            currentExpJacob.push_back(_expJacob[k]);
    }
    // printVect(currentExpJacob, "Exp Jacobsthal");
    // printVect(toSliceNext, "toSliceNext before insertions");
    // std::cout << "unorderedLower.size():" << unorderedLower.size() << std::endl;

    // insert unorderedLower elements in jacobsthal order
    for (size_t k = 0; k < currentExpJacob.size(); k++) {
        int jacIndex = currentExpJacob[k];
        int upperbound = orderedUpper[jacIndex];
        size_t upperboundPos = 0;
        // orphan: full chain search
        if (upperbound == -1)
            upperboundPos = toSliceNext.size();
        // otherwise find the upperbound position
        else
            for (size_t i = 0; i < toSliceNext.size(); i++) {
                if (toSliceNext[i] == upperbound) {
                    upperboundPos = i;
                    break;
                }
            }
        // std::cout << "Inserting " << unorderedLower[jacIndex] << ", upperbound = " << upperbound << ", upperboundPos = " << upperboundPos << std::endl;
        binaryInsertV(toSliceNext, upperboundPos, unorderedLower[jacIndex]);
    }
    return toSliceNext;
}

/* ************************************************************************** */
/*   Sort - deque                                                              */
/* ************************************************************************** */

std::deque<int> PmergeMe::sortAlgoD(std::deque<int> toSlice) {

    // 0 or 1 element, already sorted
    if (toSlice.size() < 2)
        return toSlice;

    // ── Slicing down ─────────────────────────────────────────────────────────

    // checking for orphans (deque size odd)
    int orphan = -1;
    if (toSlice.size() % 2 != 0) {
        orphan = toSlice.back();
        toSlice.pop_back();
    }

    // storing the pairs (bigger, smaller)
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < toSlice.size(); i += 2) {
        if (toSlice[i] > toSlice[i + 1])
            pairs.push_back(std::make_pair(toSlice[i], toSlice[i + 1]));
        else
            pairs.push_back(std::make_pair(toSlice[i + 1], toSlice[i]));
    }
    _nCompD += toSlice.size() / 2;

    // recursive call on the winners
    std::deque<int> toSliceNext;
    for (size_t i = 0; i < pairs.size(); i++)
        toSliceNext.push_back(pairs[i].first);
    toSliceNext = sortAlgoD(toSliceNext);

    // ── Inserting up ─────────────────────────────────────────────────────────

    // top in one deque, bottom in another
    std::deque<int>  orderedUpper = toSliceNext;
    std::deque<int>  unorderedLower;
    std::deque<bool> used(pairs.size(), false);

    for (size_t i = 0; i < orderedUpper.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (!used[j] && pairs[j].first == orderedUpper[i]) {
                unorderedLower.push_back(pairs[j].second);
                used[j] = true;
                break;
            }
        }
    }
    // orphan has no partner: -1 sentinel triggers full chain search
    if (orphan != -1) {
        unorderedLower.push_back(orphan);
        orderedUpper.push_back(-1);
    }


    // jacobSthal sequence limited to the length on unorderedLower
    std::deque<int> currentExpJacob;
    for (size_t k = 0; k < _expJacob.size(); k++) {
        if (_expJacob[k] < (int)unorderedLower.size())
            currentExpJacob.push_back(_expJacob[k]);
    }
    // printVect(currentExpJacob, "Exp Jacobsthal");
    // printVect(toSliceNext, "toSliceNext before insertions");
    // std::cout << "unorderedLower.size():" << unorderedLower.size() << std::endl;

    // insert unorderedLower elements in jacobsthal order
    for (size_t k = 0; k < currentExpJacob.size(); k++) {
        int jacIndex = currentExpJacob[k];
        int upperbound = orderedUpper[jacIndex];
        size_t upperboundPos = 0;
        // orphan: full chain search
        if (upperbound == -1)
            upperboundPos = toSliceNext.size();
        // otherwise find the upperbound position
        else
            for (size_t i = 0; i < toSliceNext.size(); i++) {
                if (toSliceNext[i] == upperbound) {
                    upperboundPos = i;
                    break;
                }
            }
        // std::cout << "Inserting " << unorderedLower[jacIndex] << ", upperbound = " << upperbound << ", upperboundPos = " << upperboundPos << std::endl;
        binaryInsertD(toSliceNext, upperboundPos, unorderedLower[jacIndex]);
    }
    return toSliceNext;
}

/* ************************************************************************** */
/*   Binary insert                                                             */
/* ************************************************************************** */

void PmergeMe::binaryInsertV(std::vector<int>& sorted, size_t upperBoundIndex, int toInsert) {
    size_t left = 0;
    size_t right = upperBoundIndex;

    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (toInsert < sorted[mid])
            right = mid;
        else if (toInsert == sorted[mid]) {
            left = mid + 1;
            break;
        }
        else
            left = mid + 1;
        _nCompV++;
    }
    sorted.insert(sorted.begin() + left, toInsert);
}

void PmergeMe::binaryInsertD(std::deque<int>& sorted, size_t upperBoundIndex, int toInsert) {
    size_t left = 0;
    size_t right = upperBoundIndex;

    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (toInsert < sorted[mid])
            right = mid;
        else if (toInsert == sorted[mid]) {
            left = mid + 1;
            break;
        }
        else
            left = mid + 1;
        _nCompD++;
    }
    sorted.insert(sorted.begin() + left, toInsert);
}

/* ************************************************************************** */
/*   Jacobsthal sequence                                                       */
/* ************************************************************************** */

// expanded sequence as 0-based indexes, up to _n / 2 + 1
std::vector<int> PmergeMe::calcJacobsthal() const {

    const size_t maxInsert = _n / 2 + 1;

    std::vector<int> jacob;
    jacob.push_back(1);
    jacob.push_back(3);
    while (jacob.back() < (int)maxInsert) {
        size_t i = jacob.size();
        jacob.push_back(jacob[i - 1] + 2 * jacob[i - 2]);
    }

    // jacobsthal expanded + subtracting 1 to have 0-based indexes
    std::vector<int> expanded;
    expanded.push_back(jacob[0] - 1);
    for (size_t i = 1; i < jacob.size(); i++) {
        for (int j = jacob[i]; j > jacob[i - 1]; j--)
            expanded.push_back(j - 1);
        if (jacob[i] >= (int)maxInsert)
            break;
    }
    return expanded;
}

/* ************************************************************************** */
/*   Utils                                                                     */
/* ************************************************************************** */

void PmergeMe::printVect(const std::vector<int>& vec, const std::string& label) {
    std::cout << label << ": ";
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::printDeq(const std::deque<int>& deq, const std::string& label) {
    std::cout << label << ": ";
    for (std::deque<int>::const_iterator it = deq.begin(); it != deq.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::printPairs(const std::vector<std::pair<int, int> >& pairs) const {
    for (size_t i = 0; i < pairs.size(); i++)
        std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";
    std::cout << std::endl;
}

bool PmergeMe::isSorted(const std::vector<int>& vec) const {
    for (size_t i = 1; i < vec.size(); i++)
        if (vec[i - 1] > vec[i])
            return false;
    return true;
}

bool PmergeMe::isSorted(const std::deque<int>& deq) const {
    for (size_t i = 1; i < deq.size(); i++)
        if (deq[i - 1] > deq[i])
            return false;
    return true;
}

void PmergeMe::verif(const std::vector<int>& sorted, const std::vector<int>& original) {
    if (sorted.size() != original.size()) {
        std::cerr << "Error: sorted vector size does not match original!" << std::endl;
        exit(1);
    }
    if (!isSorted(sorted)) {
        std::cerr << "Error: vector is not sorted!" << std::endl;
        exit(1);
    }
    std::cout << "vector sorted OK" << std::endl;
}

void PmergeMe::verif(const std::deque<int>& sorted, const std::deque<int>& original) {
    if (sorted.size() != original.size()) {
        std::cerr << "Error: sorted deque size does not match original!" << std::endl;
        exit(1);
    }
    if (!isSorted(sorted)) {
        std::cerr << "Error: deque is not sorted!" << std::endl;
        exit(1);
    }
    std::cout << "deque sorted OK" << std::endl;
}