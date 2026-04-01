/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:04:51 by htharrau          #+#    #+#             */
/*   Updated: 2026/04/01 19:54:57 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool evaluate(const std::string& input) {
    std::stack<long> _stack;
    std::istringstream iss(input);
    std::string token;

    while (iss >> token) {
        if (token.length() != 1 || !(std::isdigit(token[0]) || isOperator(token[0]))) {
            std::cerr << "[Error] Invalid token: " << token << std::endl;
            return false;
        }

        char c = token[0];

        if (std::isdigit(c))
            _stack.push(c - '0');

        else {
            if (_stack.size() < 2u) {
                std::cerr << "[Error] Invalid RPN expression: " << c << std::endl;
                return false;
            }
            long b = _stack.top();
            _stack.pop();
            long a = _stack.top();
            _stack.pop();
            long result;
            switch (c) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    if (b == 0) {
                        std::cerr << "[Error] Division by zero: " << a << c << b << std::endl;
                        return false;
                    }
                    result = a / b;
                    break;
                default:
                    std::cerr << "[Error] Invalid operator: " << c << std::endl;
                    return false;
            }
            _stack.push(result);
        }
    }

    if (_stack.size() != 1) {
        std::cerr << "[Error] Invalid RPN expression" << std::endl;
        return false;
    }
    std::cout << _stack.top() << std::endl;
    return true;
}

bool isOperator(char a) { return (a == '+' || a == '-' || a == '*' || a == '/'); }