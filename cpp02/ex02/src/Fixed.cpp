/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:15:10 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/17 13:40:35 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

//constructor
Fixed::Fixed(void) : fixedPointValue(0) {
}

// Int constructor: left shift by 8 = multiply by 256 (faster than n * 256
Fixed::Fixed(const int n) : fixedPointValue(n << fractionalBits) {
}

// Float constructor: multiply by 256, round to nearest int (preserves precision better than truncation)
Fixed::Fixed(const float f) : fixedPointValue(roundf(f * (1 << fractionalBits))) {
}

Fixed::Fixed(const Fixed& other) : fixedPointValue(other.fixedPointValue) {
}

//destructor
Fixed::~Fixed(void) {
}
//assigment operator
Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		this->fixedPointValue = other.fixedPointValue;
	return *this;
}

//comparison operators
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

//arithmetric operators
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

//increment/decrement operators

// Pre-increment: ++a - increment first, then return modified object by reference
Fixed& Fixed::operator++(void) {
	this->fixedPointValue++;
	return *this;
}

// Post-increment: a++ - save old, increment, return old value by value
Fixed Fixed::operator++(int) {
	Fixed temp(*this); //save old
	this->fixedPointValue++;
	return temp; //return old
}

Fixed& Fixed::operator--(void) {
	this->fixedPointValue--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->fixedPointValue--;
	return temp;
}
// Cast to float before division to get decimals (int/int would truncate)
float Fixed::toFloat(void) const {
	return static_cast<float>(this->fixedPointValue) / (1 << fractionalBits);
}
// Right shift by 8 = divide by 256, discard fractional bits (extracts integer part)
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

// Compares two numbers and returns the smaller one
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return a;
	return b;
}

// Return smaller one, const version
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if (a < b)
		return a;
	return b;
}

// Compares two numbers and returns the greater one
Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a > b)
		return a;
	return b;
}

// Return bigger one, const version
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	if (a > b)
		return a;
	return b;
}

// Printing Fixed, chained
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}
