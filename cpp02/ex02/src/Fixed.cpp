/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:15:10 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/15 23:09:27 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

// CONSTRUCTORS & DESTRUCTOR - silent (no debug messages) for production-ready numeric type
Fixed::Fixed(void) : fixedPointValue(0) {
}

Fixed::Fixed(const int n) : fixedPointValue(n << fractionalBits) {	// Left shift by 8 = multiply by 256
}

Fixed::Fixed(const float f) : fixedPointValue(roundf(f * (1 << fractionalBits))) {	// Multiply by 256, round
}

Fixed::Fixed(const Fixed& other) : fixedPointValue(other.fixedPointValue) {	// Direct initialiser list (efficient)
}

Fixed::~Fixed(void) {
}
// ASSIGNMENT OPERATOR

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)	// Self-assignment protection
		this->fixedPointValue = other.fixedPointValue;
	return *this;	// Return reference for chaining: a = b = c
}
// COMPARISON OPERATORS - compare raw values directly (fast, accurate since same scaling)
// Ordering preserved: 10.5*256=2688 > 5.25*256=1344 correctly reflects 10.5 > 5.25
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
// ARITHMETIC OPERATORS - convert to float, operate, convert back (handles fractional results)
// Can't multiply raw values: 512*768=393216 but should be 2*3=6 then *256=1536
Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

// Division by zero NOT protected - undefined behaviour (produces inf/nan)
Fixed Fixed::operator/(const Fixed& other) const {
	return Fixed(this->toFloat() / other.toFloat());
}
// INCREMENT/DECREMENT OPERATORS - increment by 1 raw unit = 1/256 (0.00390625) actual value
// Pre-increment: ++a - increment first, then return modified object by reference
Fixed& Fixed::operator++(void) {
	this->fixedPointValue++;	// Increment by 1 raw unit
	return *this;	// Return reference to allow chaining: ++(++a)
}
// Post-increment: a++ - save old, increment, return old value by value
// Dummy int parameter distinguishes from prefix (never used, compiler passes 0)
Fixed Fixed::operator++(int) {
	Fixed temp(*this);	// Save old value (creates copy - less efficient than prefix)
	this->fixedPointValue++;
	return temp;	// Return old value by value (can't return reference to local)
}
// Pre-decrement: --a - same logic as pre-increment
Fixed& Fixed::operator--(void) {
	this->fixedPointValue--;
	return *this;
}
// Post-decrement: a-- - same logic as post-increment
Fixed Fixed::operator--(int) {
	Fixed temp(*this);	// Save old value
	this->fixedPointValue--;
	return temp;	// Return old value
}
// CONVERSION FUNCTIONS - both const (read-only operations)
// Cast to float before division to get decimals (int/int would truncate)
float Fixed::toFloat(void) const {
	return static_cast<float>(this->fixedPointValue) / (1 << fractionalBits);
}

// Right shift by 8 = divide by 256, discard fractional bits (extracts integer part)
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
// STATIC MEMBER FUNCTIONS - don't need object to call: Fixed::min(a, b) not a.min(b)
// Function overloading: two versions of each (const and non-const) for const-correctness
// Non-const version: returns modifiable reference (allows Fixed::min(a,b) = Fixed(5))
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return a;
	return b;
}

// Const version: accepts const objects, returns const reference (read-only)
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
// STREAM INSERTION OPERATOR - must be outside class (left operand is ostream)
// Returns ostream& to enable chaining: cout << a << b works left-to-right
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();	// Print as float representation
	return out;
}
