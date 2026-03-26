/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:59:07 by htharrau          #+#    #+#             */
/*   Updated: 2026/01/06 13:04:18 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <typename T>
Array<T>::Array() {
	mySize = 0;
	myArray = NULL; //  truly empty, No memory allocated, No delete[] needed 
	// myArray = new T[0];     // Technically allocates, but for 0 elements - edge case
}

template <typename T>
Array<T>::Array(unsigned int n) {
	mySize = n;
    if (n > 1000000) {
        throw std::invalid_argument("Array size is unreasonably large");
    }	
	if (n == 0) {
		myArray = NULL;
		return;
	}
	// myArray = new T[mySize]; // not initialized, garbage values (unless T is a class type)
	myArray = new T[mySize]();  // initialized to 0
}

template <typename T>
Array<T>::Array(const Array& other) {
	mySize = other.mySize;
	if (mySize == 0) {
		myArray = NULL;
		return;
	}
	myArray = new T[mySize];
	for (unsigned int i = 0; i < mySize; i++) {
		myArray[i] = other.myArray[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	
	if (this == &other)
		return *this;

	delete[] myArray;
	mySize = other.mySize;
	
	if (mySize == 0) {
		myArray = NULL;
	}
	else {
		myArray = new T[mySize];
		for (unsigned int i = 0; i < mySize; i++) {
			myArray[i] = other.myArray[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete[] myArray;
}


template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= mySize || index < 0|| mySize == 0) {
		throw std::out_of_range("Index out of bounds");
	}
	return (myArray[index]);
}

template <typename T>
unsigned int Array<T>::size() const {
	return mySize;
}

template <typename T>
std::ostream& operator<<(std::ostream &os, Array<T>& arr)  {
	if (arr.size() == 0) {
		os << "Array is empty.";
		return os;
	}
	for (unsigned int i = 0; i < arr.size(); i++) {
		os << arr[i] << " ";
	}
	return os;
}