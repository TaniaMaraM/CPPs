/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 21:03:48 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/29 15:07:17 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

// Default constructor
Fixed::Fixed( void ) : fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed( const Fixed& other ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator
Fixed& Fixed::operator=( const Fixed& other ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->fixedPointValue = other.getRawBits();
	}
	return *this; // ← Retorna referência para permitir a = b = c;
}

// Destructor
Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

// Returns the raw value of the fixed-point value
int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPointValue;
}

// Sets the raw value of the fixed-point number
void Fixed::setRawBits( int const raw ) {
	this->fixedPointValue = raw;
}

//const no final: promete não modificar o objeto
