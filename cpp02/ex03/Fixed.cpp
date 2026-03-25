/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:01:18 by htharrau          #+#    #+#             */
/*   Updated: 2025/05/09 16:24:36 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/////////////////////////////
//	 	 DECONSTRUCTORS		//
/////////////////////////////

Fixed::Fixed() : fixedPoint(0) {}

// overflow: (2^31 - 1) / 2^8 = 8388607
// underflow: -(2^31) / 2^8 = -8388608
Fixed::Fixed(const int inputInt) : fixedPoint(inputInt << dec_bit) {
    if (inputInt > 8388607 || inputInt < -8388608) {
        std::cerr << "Error: overflowing." << std::endl;
        throw std::runtime_error("Overflowing");
    }
}

Fixed::Fixed(const float inputFloat) : fixedPoint(roundf(inputFloat * (1 << dec_bit))) {
    if (inputFloat > 8388607.99609375 || inputFloat < -8388608) {
        std::cerr << "Error: overflowing." << std::endl;
        throw std::runtime_error("Overflowing");
    }
}

Fixed::Fixed(const Fixed& other) : fixedPoint(other.fixedPoint) {}

Fixed::~Fixed() {}

/////////////////////////////
//	 	 CONVERSION			//
/////////////////////////////

float Fixed::toFloat(void) const { return (static_cast<float>(fixedPoint) / (1 << dec_bit)); }

int Fixed::toInt(void) const { return (fixedPoint >> dec_bit); }

Fixed Fixed::fromRaw(int intRawInput) {
    Fixed newObj;
    newObj.fixedPoint = intRawInput;
    return (newObj);
}

/////////////////////////////
//	 	= OPERATORS			//
/////////////////////////////

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) this->fixedPoint = other.fixedPoint;
    return (*this);
}

Fixed& Fixed::operator+=(const Fixed& other) {
    int64_t check = static_cast<int64_t>(this->fixedPoint) + static_cast<int64_t>(other.fixedPoint);
    if (check > 2147483647LL || check < -2147483648LL) {
        std::cerr << "Error: overflowing." << std::endl;
        throw std::runtime_error("Overflowing");
    }
    this->fixedPoint = static_cast<int>(check);
    return (*this);
}

Fixed& Fixed::operator-=(const Fixed& other) {
    int64_t check = static_cast<int64_t>(this->fixedPoint) - static_cast<int64_t>(other.fixedPoint);
    if (check > 2147483647LL || check < -2147483648LL) {
        std::cerr << "Error: overflowing." << std::endl;
        throw std::runtime_error("Overflowing");
    }
    this->fixedPoint = static_cast<int>(check);
    return (*this);
}

Fixed& Fixed::operator*=(const Fixed& other) {
    int64_t result =
        static_cast<int64_t>(this->fixedPoint) * static_cast<int64_t>(other.fixedPoint);
    result = result >> dec_bit;
    if (result > 2147483647LL || result < -2147483648LL) {
        std::cerr << "Error: overflowing." << std::endl;
        throw std::runtime_error("Overflowing");
    }
    this->fixedPoint = static_cast<int>(result);
    return (*this);
}

Fixed& Fixed::operator/=(const Fixed& other) {
    if (other.fixedPoint == 0) {
        std::cerr << "Error: division by zero." << std::endl;
        throw std::runtime_error("Division by zero");
    }
    int64_t numerator = (static_cast<int64_t>(this->fixedPoint) << dec_bit);
    *this = Fixed::fromRaw(static_cast<int>(numerator / other.fixedPoint));
    return (*this);
}

/////////////////////////////////
//		ADD, SUB, DIV, MULT		//
/////////////////////////////////

Fixed Fixed::operator+(const Fixed& other) const {
    int64_t check = static_cast<int64_t>(this->fixedPoint) + static_cast<int64_t>(other.fixedPoint);
    if (check > 2147483647LL || check < -2147483648LL) {
        std::cerr << "Error: overflowing." << std::endl;
        throw std::runtime_error("Overflowing");
    }
    return (Fixed::fromRaw(static_cast<int>(check)));
}

Fixed Fixed::operator-(const Fixed& other) const {
    int64_t check = static_cast<int64_t>(this->fixedPoint) - static_cast<int64_t>(other.fixedPoint);
    if (check > 2147483647LL || check < -2147483648LL) {
        std::cerr << "Error: overflowing." << std::endl;
        throw std::runtime_error("Overflowing");
    }
    return (Fixed::fromRaw(static_cast<int>(check)));
}

Fixed Fixed::operator*(const Fixed& other) const {
    int64_t check = static_cast<int64_t>(this->fixedPoint) * static_cast<int64_t>(other.fixedPoint);
    check = check >> dec_bit;
    if (check > 2147483647LL || check < -2147483648LL) {
        std::cerr << "Error: overflowing." << std::endl;
        throw std::runtime_error("Overflowing");
    }
    return (Fixed::fromRaw(static_cast<int>(check)));
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other.fixedPoint == 0) {
        std::cerr << "Error: Division by zero." << std::endl;
        throw std::runtime_error("Division by zero");
    }
    int64_t numerator = (static_cast<int64_t>(this->fixedPoint) << dec_bit);
    return (Fixed::fromRaw(static_cast<int>(numerator / other.fixedPoint)));
}

/////////////////////////////
//		COMPARISONS			//
/////////////////////////////

bool Fixed::operator>(const Fixed& other) const { return (this->fixedPoint > other.fixedPoint); }

bool Fixed::operator<(const Fixed& other) const { return (this->fixedPoint < other.fixedPoint); }

bool Fixed::operator>=(const Fixed& other) const { return (this->fixedPoint >= other.fixedPoint); }

bool Fixed::operator<=(const Fixed& other) const { return (this->fixedPoint <= other.fixedPoint); }

bool Fixed::operator==(const Fixed& other) const { return (this->fixedPoint == other.fixedPoint); }

bool Fixed::operator!=(const Fixed& other) const { return (this->fixedPoint != other.fixedPoint); }

/////////////////////////////
//	 	 INCREMENTATIONS	//
/////////////////////////////

Fixed& Fixed::operator++() {
    if (this->fixedPoint == 2147483647) {
        std::cerr << "Error: overflowing." << std::endl;
        // exit(1);
        throw std::runtime_error("Overflowing");
    }
    ++(this->fixedPoint);
    return (*this);
}

Fixed& Fixed::operator--() {
    if (this->fixedPoint == -2147483648) {
        std::cerr << "Error: overflowing." << std::endl;
        // exit(1);
        throw std::runtime_error("Overflowing");
    }
    --(this->fixedPoint);
    return (*this);
}

Fixed Fixed::operator++(int) {
    if (this->fixedPoint == 2147483647) {
        std::cerr << "Error: overflowing." << std::endl;
        // exit(1);
        throw std::runtime_error("Overflowing");
    }
    Fixed a = *this;
    ++(this->fixedPoint);
    return (a);
}

Fixed Fixed::operator--(int) {
    if (this->fixedPoint == -2147483648) {
        std::cerr << "Error: overflowing." << std::endl;
        // exit(1);
        throw std::runtime_error("Overflowing");
    }
    Fixed a = *this;
    --(this->fixedPoint);
    return (a);
}

/////////////////////////////
//	 	 MIN AND MAX 		//
/////////////////////////////

const Fixed& Fixed::min(const Fixed& first, const Fixed& second) {
    if (first.fixedPoint < second.fixedPoint)
        return (first);
    else
        return (second);
}

Fixed& Fixed::min(Fixed& first, Fixed& second) {
    if (first.fixedPoint < second.fixedPoint)
        return (first);
    else
        return (second);
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second) {
    if (first.fixedPoint > second.fixedPoint)
        return (first);
    else
        return (second);
}

Fixed& Fixed::max(Fixed& first, Fixed& second) {
    if (first.fixedPoint > second.fixedPoint)
        return (first);
    else
        return (second);
}

/////////////////////////////
//	  	ABSOLUTE			//
/////////////////////////////

Fixed Fixed::absFixed(const Fixed& first, const Fixed& second) {
    if (first > second)
        return (first - second);
    else
        return (second - first);
}

/////////////////////////////
//	  OUT STREAM OVERLOAD	//
/////////////////////////////

std::string Fixed::printBits() const {
    std::string bits;

    for (int i = 31; i >= 0; i--) {
        bits += ((fixedPoint >> i) & 1) ? '1' : '0';
        if (i % 8 == 0 && i != 0) bits += ' ';
    }
    return (bits);
}

std::ostream& operator<<(std::ostream& stream, const Fixed& n) {
    stream << std::fixed << std::setprecision(2) << n.toFloat();
    return (stream);
}

// std::ostream& operator<<(std::ostream& stream, const Fixed& n)
// {
//     stream << std::fixed << std::setprecision(8) << n.toFloat()
//            << " (" << n.printBits() << ") ";
//     return stream;
// }
