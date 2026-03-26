/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:19:33 by htharrau          #+#    #+#             */
/*   Updated: 2025/08/27 19:33:54 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define RESET "\033[0m"


template<typename T>
void swap(T &a, T &b) {
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
	std::cout << "swap function called" << std::endl;

}

template<typename T>
T min(T a, T b) {
	return (a > b)? b : a;
}

template<typename T>
T max(T a, T b) {
	return (a > b)? a : b;
}