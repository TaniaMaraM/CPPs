/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:15:10 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/29 16:58:29 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

// CONSTRUCTORS & DESTRUCTOR
Fixed::Fixed(void) : fixedPointValue(0) {
}

Fixed::Fixed(const int n) : fixedPointValue(n << fractionalBits) {
}

Fixed::Fixed(const float f) : fixedPointValue(roundf(f * (1 << fractionalBits))) {
}

Fixed::Fixed(const Fixed& other) : fixedPointValue(other.fixedPointValue) {
}

Fixed::~Fixed(void) {
}
// ASSIGNMENT OPERATOR
Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		this->fixedPointValue = other.fixedPointValue;
	return *this;
}
// COMPARISON OPERATORS
bool Fixed::operator>(const Fixed& other) const {
	return this->fixedPointValue > other.fixedPointValue;
}

bool Fixed::operator<(const Fixed& other) const {
	return this->fixedPointValue < other.fixedPointValue;
}

bool Fixed::operator>=(const Fixed& other) const {
	return this->fixedPointValue >= other.fixedPointValue;
}

bool Fixed::operator<=(const Fixed& other) const {
	return this->fixedPointValue <= other.fixedPointValue;
}

bool Fixed::operator==(const Fixed& other) const {
	return this->fixedPointValue == other.fixedPointValue;
}

bool Fixed::operator!=(const Fixed& other) const {
	return this->fixedPointValue != other.fixedPointValue;
}
// ARITHMETIC OPERATORS
Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
	return Fixed(this->toFloat() / other.toFloat());
}
// INCREMENT/DECREMENT OPERATORS
// Pre-increment: ++a
Fixed& Fixed::operator++(void) {
	this->fixedPointValue++;
	return *this;
}
// Post-increment: a++
Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	this->fixedPointValue++;
	return temp;
}
// Pre-decrement: --a
Fixed& Fixed::operator--(void) {
	this->fixedPointValue--;
	return *this;
}
// Post-decrement: a--
Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->fixedPointValue--;
	return temp;
}
// CONVERSION FUNCTIONS
float Fixed::toFloat(void) const {
	return static_cast<float>(this->fixedPointValue) / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
	return this->fixedPointValue >> fractionalBits;
}
// GETTERS/SETTERS
int Fixed::getRawBits(void) const {
	return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	this->fixedPointValue = raw;
}
// STATIC MEMBER FUNCTIONS
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	if (a > b)
		return a;
	return b;
}
// STREAM INSERTION OPERATOR
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}
