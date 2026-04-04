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

#define DEBUG 0



PmergeMe::PmergeMe(const std::vector<int>& dataV, const std::deque<int>& dataD) : _dataVect(dataV), _dataDeq(dataD) {

    struct timeval start, end;
    _n = _dataVect.size();
    _nComp = 0;
    std::vector<int> toSlice = _dataVect;
    _expJacob = calcJacobsthal();
#if DEBUG
    printVect(_expJacob, "Exp Jacobsthal");
#endif


    printVect(_dataVect, "Before");
    gettimeofday(&start, NULL);
    _sortedVect = sortAlgoV(toSlice);
    gettimeofday(&end, NULL);
    printVect(_sortedVect, "Sorted");

    double vectTime = (end.tv_sec - start.tv_sec) * 1000000.0
        + (end.tv_usec - start.tv_usec);

    std::cout << "Time to process a range of " << _n
        << " elements with std::vector : " << vectTime << " us" << std::endl;

    std::cout << "Number of comparisons " << _nComp << std::endl;
    verif();
}


PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _dataVect = other._dataVect;
        _dataDeq = other._dataDeq;
        _sortedVect = other._sortedVect;
        // _sortedDeq = other._sortedDeq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}



std::vector<int> PmergeMe::sortAlgoV(std::vector<int> toSlice) {

    // 0 or 1 element, already sorted
    if (toSlice.size() < 2)
        return toSlice;


    ///////////////////////// SLICING DOWN ////////////////////////

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
    // comparisons increment for the pairs
    _nComp += toSlice.size() / 2;

    // vector of the winners of the round
    std::vector<int> toSliceNext;
    for (size_t i = 0; i < pairs.size(); i++)
        toSliceNext.push_back(pairs[i].first);

#if DEBUG
    printVect(toSliceNext, "Current winners");
    // std::cout << "ncomp = " << _nComp << std::endl;
#endif

    // recursive call on the winners
    toSliceNext = sortAlgoV(toSliceNext);


    ///////////////////////// INSERTING UP ////////////////////////

#if DEBUG
    printPairs(pairs);
#endif

    // top in one vector, bottom in another
    std::vector<int> orderedUpper = toSliceNext;
    std::vector<int> unorderedLower;
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
    if (orphan != -1) {
        unorderedLower.push_back(orphan);
        orderedUpper.push_back(-1);
    }

#if DEBUG
    printVect(orderedUpper, "orderedUpper");
    printVect(unorderedLower, "unorderedLower");
#endif


    // insert unorderedLower elements in jacobsthal order
    std::vector<bool> inserted(unorderedLower.size(), false);
    for (size_t k = 0; k < unorderedLower.size(); k++) {
        int jacIndex = _expJacob[k];
        if (jacIndex >= (int)unorderedLower.size())
            jacIndex = unorderedLower.size() - 1;
        //    / skip already inserted indices
        while (jacIndex >= 0 && inserted[jacIndex])
            jacIndex--;
        if (jacIndex < 0)
            break;
        inserted[jacIndex] = true;
        int upperbound = orderedUpper[jacIndex];

        // find upperbound's current position in toSliceNext (shifts after each insert)
        size_t upperboundPos = toSliceNext.size();
        if (upperbound != -1)
            upperboundPos = std::lower_bound(toSliceNext.begin(), toSliceNext.end(), upperbound) - toSliceNext.begin();

        binaryInsert(toSliceNext, upperboundPos, unorderedLower[jacIndex]);
    }
    return toSliceNext;
}


void PmergeMe::binaryInsert(std::vector<int>& sorted, size_t upperBoundIndex, int toInsert) {
    size_t left = 0;
    size_t right = upperBoundIndex;

    if (upperBoundIndex == 0) {
#if DEBUG
        std::cout << "inserting " << toInsert << " at position 0" << std::endl;
#endif
        sorted.insert(sorted.begin(), toInsert);
        return;
    }

#if DEBUG
    std::cout << "\n--- binaryInsert ---" << std::endl;
    std::cout << "toInsert: " << toInsert << ", upperBound: " << upperBoundIndex << std::endl;
    std::cout << "searching in: ";
    for (size_t i = 0; i <= upperBoundIndex && i < sorted.size(); i++)
        std::cout << sorted[i] << " ";
    std::cout << std::endl;
#endif

    while (left < right) {
        size_t mid = left + (right - left) / 2;
#if DEBUG
        std::cout << "left=" << sorted[left] << " right index=" << right << " mid=" << sorted[mid] << std::endl;
#endif
        if (toInsert < sorted[mid]) {
#if DEBUG
            std::cout << toInsert << " < " << sorted[mid] << " -> go left" << std::endl;
#endif
            right = mid;
        }
        else if (toInsert == sorted[mid]) {
#if DEBUG
            std::cout << toInsert << " == " << sorted[mid] << " -> insert" << std::endl;
#endif
            left = mid + 1;
            break;
        }
        else {
#if DEBUG
            std::cout << toInsert << " > " << sorted[mid] << " -> go right" << std::endl;
#endif
            left = mid + 1;
        }
        _nComp++;
    }
    sorted.insert(sorted.begin() + left, toInsert);
#if DEBUG
    std::cout << "inserting " << toInsert << " at position " << left << std::endl;
    std::cout << "sorted after insert: ";
    for (size_t i = 0; i < sorted.size(); i++)
        std::cout << sorted[i] << " ";
    // std::cout << "_nComp: " << _nComp << std::endl;
    std::cout << "\n--- end binaryInsert ---\n" << std::endl;
#endif
}


// jacobsthal sequence expanded till _n / 2
std::vector<int> PmergeMe::calcJacobsthal() const {

#if DEBUG
    std::cout << "Calculating Jacobsthal numbers up to " << _n / 2 << std::endl;
#endif
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

#if DEBUG
    std::cout << "jacob.size() " << jacob.size() << std::endl;
#endif
    expanded.push_back(jacob[0] - 1);
    for (size_t i = 1; i < jacob.size(); i++) {
        for (int j = jacob[i]; j > jacob[i - 1]; j--) {
            expanded.push_back(j - 1);
            if (j == 1) break;
        }
        if (jacob[i] >= (int)maxInsert) break;
    }
    return expanded;
}


void PmergeMe::printVect(const std::vector<int>& vec, const std::string& label) {
    std::cout << label << ": ";
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::printPairs(const std::vector<std::pair<int, int> >& pairs) const {
    for (size_t i = 0; i < pairs.size(); i++)
        std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";
    std::cout << std::endl;
}

bool PmergeMe::isSorted(const std::vector<int>& vec) const {
    if (vec.size() < 2)
        return true;
    for (size_t i = 1; i < vec.size(); i++) {
        if (vec[i - 1] > vec[i])
            return false;
    }
    return true;
}

void PmergeMe::verif() {
    if (_sortedVect.size() != _dataVect.size()) {
        std::cerr << "Error: sorted vector size does not match original!" << std::endl;
        exit(1);
    }
    if (!isSorted(_sortedVect)) {
        std::cerr << "Error: vector is not sorted!" << std::endl;
        exit(1);
    }
    std::cout << "sorted OK" << std::endl;
}
