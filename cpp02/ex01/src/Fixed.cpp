/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:08:07 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/29 15:41:22 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

// Constructors
Fixed::Fixed(void) : fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : fixedPointValue(n << fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : fixedPointValue(roundf(f * (1 << fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Destructor
Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

// Operators
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixedPointValue = other.getRawBits();
	return *this;
}

// Conversions
float Fixed::toFloat(void) const {
	return static_cast<float>(this->fixedPointValue) / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
	return this->fixedPointValue >> fractionalBits;
}

// Getters/Setters

int Fixed::getRawBits(void) const {
	return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	this->fixedPointValue = raw;
}

// Operator overload (outside class)
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}
