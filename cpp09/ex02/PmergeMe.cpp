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


PmergeMe::PmergeMe(const std::vector<int>& dataV, const std::deque<int>& dataD) : _dataVect(dataV), _dataDeq(dataD) {

    _n = _dataVect.size();
    std::vector<int> toSlice = _dataVect;
    _expJacob = calcJacobsthal();
    printVect(_expJacob, "Exp Jacohstahl");
    _nComp = 0;

    printVect(_dataVect, "Before");
    _sortedVect = sortAlgoV(toSlice);
    printVect(_sortedVect, "Sorted");

}


PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _dataVect = other._dataVect;
        _dataDeq = other._dataDeq;
        _sortedVect = other._sortedVect;
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

    // debug print
    printVect(toSliceNext, "Current winners");
    std::cout << "ncomp = " << _nComp << std::endl;

    // recursive call on the winners
    toSliceNext = sortAlgoV(toSliceNext);



    ///////////////////////// INSERTING UP ////////////////////////


    // debug print
    printPairs(pairs);


    // implement insertion with jacobstahl

    // top in one vector, bottom in another
    std::vector<int> orderedUpper = toSliceNext; // for indexes
    std::vector<int> unorderedLower;
    for (size_t i = 0; i < orderedUpper.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].first == orderedUpper[i]) {
                unorderedLower.push_back(pairs[j].second);
            }
        }
    }
    printVect(orderedUpper, "orderedUpper");
    printVect(unorderedLower, "unorderedLower");

    // to insert : unorderedLower[i] in toSliceNext with upperBound = _expJacob[toSliceNext[i]]
    for (size_t k = 0; k < unorderedLower.size(); k++) {
        int jacIndex = _expJacob[k];  // which lower element to insert 
        if (jacIndex >= (int)orderedUpper.size())
            jacIndex = orderedUpper.size() - 1; // if jacobstahl index exceeds, take the last one as upperbound
        int upperbound = orderedUpper[jacIndex];  // its winner/upperbound value

        // find upperbound's current position in toSliceNext (shifts after each insert)
        size_t upperboundPos = 0;
        for (size_t i = 0; i < toSliceNext.size(); i++) {
            if (toSliceNext[i] == upperbound) {
                upperboundPos = i;
                break;
            }
        }
        std::cout << "upperboundPos = " << upperbound <<  ", unorderedLower[jacIndex] = "<<  unorderedLower[jacIndex] << std::endl;
        binaryInsert(toSliceNext, upperboundPos, unorderedLower[jacIndex]);
    }



    // if orphan: back in (after the pairs of the round) upperbound: last element
    std::cout << "putting back orphan = " << orphan << std::endl;
    if (orphan != -1)
        binaryInsert(toSliceNext, toSliceNext.size(), orphan);

    // returning the sorted vector!!
    return(toSliceNext);

}

void PmergeMe::binaryInsert(std::vector<int>& sorted, size_t upperBoundIndex, int toInsert) {
    size_t left = 0;
    size_t right = upperBoundIndex;

    if (upperBoundIndex == 0) {
        std::cout << "inserting " << toInsert << " at position " << upperBoundIndex << std::endl;
        sorted.insert(sorted.begin() + upperBoundIndex, toInsert);
        return;
    }

    std::cout << "\n--- binaryInsert ---" << std::endl;
    std::cout << "toInsert: " << toInsert << ", upperBound: " << upperBoundIndex << std::endl;
    std::cout << "searching in: ";
    for (size_t i = 0; i <= upperBoundIndex && i < sorted.size(); i++)
        std::cout << sorted[i] << " ";
    std::cout << std::endl;

    while (left < right) {
        size_t mid = left + (right - left) / 2;
        std::cout << "left=" << sorted[left] << " right index=" << right << " mid=" << sorted[mid] << std::endl;
        if (toInsert < sorted[mid]) {
            std::cout << toInsert << " < " << sorted[mid] << " -> go left" << std::endl;
            right = mid;
        }
        else {
            std::cout << toInsert << " >= " << sorted[mid] << " -> go right" << std::endl;
            left = mid + 1;
        }
        _nComp++;
    }
    std::cout << "inserting " << toInsert << " at position " << left << std::endl;
    sorted.insert(sorted.begin() + left, toInsert);

    std::cout << "sorted after insert: ";
    for (size_t i = 0; i < sorted.size(); i++)
        std::cout << sorted[i] << " ";
    std::cout << "_nComp: " << _nComp << std::endl;
    std::cout << "\n--- end binaryInsert ---\n" << std::endl;
}



// jacobstahl sequence expanded till _n / 2 
std::vector<int> PmergeMe::calcJacobsthal() const {

    std::cout << "Calculating Jacobsthal numbers up to " << _n / 2 << std::endl;
    const size_t maxInsert = _n / 2;

    std::vector<int> jacob;
    jacob.push_back(1);
    jacob.push_back(3);
    while (jacob.back() < (int)maxInsert) {
        size_t i = jacob.size();
        jacob.push_back(jacob[i - 1] + 2 * jacob[i - 2]);
    }

    // jacobstahl expanded + removing 1 to have indexes ready to use
    std::vector<int> expanded;

    std::cout << "jacob.size() " << jacob.size() << std::endl;
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


// print function for vector with a label
void PmergeMe::printVect(const std::vector<int>& vec, const std::string& label) {
    std::cout << label << ": ";
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


// debug function to print the pairs of the round
void PmergeMe::printPairs(const std::vector<std::pair<int, int> >& pairs) const {
    for (size_t i = 0; i < pairs.size(); i++) {
        std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";
    }
    std::cout << std::endl;
}
