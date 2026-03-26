/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:08:33 by htharrau          #+#    #+#             */
/*   Updated: 2025/09/21 18:23:15 by htharrau         ###   ########.fr       */
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

/* first param pointer because when we pass an array to a function:
	int arr[3];
	iter(arr, 3, f);
arr becomes int*.
*/


template <typename T, typename F>
void iter(T *array, const std::size_t size, F f) {
	for (std::size_t i = 0; i < size; ++i) {
		f(array[i]);
	}
}

template <typename T>
void changeSign(T &value) {
	value = -value;
}

template <typename T>
void print(const T &value) {
	std::cout << value << std::endl;
}