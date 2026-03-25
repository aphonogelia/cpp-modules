/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:35:33 by htharrau          #+#    #+#             */
/*   Updated: 2025/06/06 21:54:48 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/////////////////////////
// 	Coplien Form 	//
/////////////////////////
Serializer::Serializer() {}
Serializer::Serializer(const Serializer& other) { (void)other; }
Serializer& Serializer::operator=(const Serializer& other) {
    (void)other;
    return *this;
}
Serializer::~Serializer() {}

/////////////////////////
// 	FUNCTIONS 		//
/////////////////////////
uintptr_t Serializer::serialize(Data* ptr) { return (reinterpret_cast<uintptr_t>(ptr)); }

Data* Serializer::deserialize(uintptr_t raw) { return (reinterpret_cast<Data*>(raw)); }