/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:08:07 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/17 13:10:55 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

//Constructors
Fixed::Fixed(void) : fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

// Int constructor: left shift by 8 = multiply by 256
Fixed::Fixed(const int n) : fixedPointValue(n << fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

// Float constructor: multiply by 256
Fixed::Fixed(const float f) : fixedPointValue(roundf(f * (1 << fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

//Copy constructor
Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

//Destructor
Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

//Operator
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixedPointValue = other.getRawBits();
	return *this;
}

//Conversions
//Cast to float before division to get proper decimals
float Fixed::toFloat(void) const {
	return static_cast<float>(this->fixedPointValue) / (1 << fractionalBits);
}

// Right shift by 8 = divide by 256, discarding fractional part (extracts integer part)
int Fixed::toInt(void) const {
	return this->fixedPointValue >> fractionalBits;
}

//setters and getters
int Fixed::getRawBits(void) const {
	return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	this->fixedPointValue = raw;
}

// Printing Fixed, chained
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}
