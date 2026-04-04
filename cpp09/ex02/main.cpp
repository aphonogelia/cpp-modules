/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:02:16 by htharrau          #+#    #+#             */
/*   Updated: 2026/04/03 18:16:38 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " positive integer sequence " << std::endl;
        return 1;
    }

    std::vector<int> inputV;
    std::deque<int> inputD;

    for (int i = 1; i < argc; i++) {
        std::istringstream iss(argv[i]);
        int value;

        iss >> value;

        if (iss.fail() || !iss.eof() || value < 0) {
            std::cerr << "[Error] invalid input: " << argv[i] << std::endl;
            return 1;
        }
        inputV.push_back(value);
        inputD.push_back(value);
    }

    PmergeMe exchange(inputV, inputD);

    return 0;
}