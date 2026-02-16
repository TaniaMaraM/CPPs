/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 21:03:48 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/12 10:51:26 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

// Default constructor - initialiser list is more efficient than assignment in body
Fixed::Fixed( void ) : fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor - creates new object from existing one (Fixed b(a))
Fixed::Fixed( const Fixed& other ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;	// Calls operator= to avoid code duplication (slightly less efficient but DRY)
}

// Copy assignment operator - assigns to already-existing object (c = b)
Fixed& Fixed::operator=( const Fixed& other ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {	// Self-assignment protection: prevents a = a from wasting cycles
		this->fixedPointValue = other.getRawBits();
	}
	return *this;	// Return *this by reference to enable chaining: a = b = c works right-to-left
}

// Destructor - called when object goes out of scope (LIFO order: last created, first destroyed)
Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

// Returns the raw value - const allows calling on const objects, promises not to modify
int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPointValue;
}

// Sets the raw value - not const because it modifies the object
void Fixed::setRawBits( int const raw ) {
	this->fixedPointValue = raw;
}
