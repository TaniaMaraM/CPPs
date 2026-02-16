/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:07:38 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/16 21:29:39 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int					fixedPointValue;	// Stores value * 256 (8 fractional bits)
	static const int	fractionalBits = 8;	// All Fixed objects share this constant

public:
	// Constructors & Destructor (Orthodox Canonical Form)
	Fixed( void );							// Default: initialises to 0
	Fixed( const int n );					// Converts int to fixed-point (n << 8)
	Fixed( const float f );					// Converts float to fixed-point (f * 256, rounded)
	Fixed( const Fixed& other );			// Copy constructor
	Fixed& operator=( const Fixed& other );	// Copy assignment operator
	~Fixed( void );							// Destructor
	// Conversions - both const because they only read, don't modify
	float	toFloat( void ) const;			// Converts back to float (rawBits / 256)
	int		toInt( void ) const;			// Extracts integer part (rawBits >> 8)
	// Getters/Setters
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

// MUST be outside class: left operand is std::ostream, not Fixed
// If member function, syntax would be myFixed << cout (backwards!)
std::ostream& operator<<( std::ostream& out, const Fixed& fixed );

#endif

/*
Fixed-point numbers represent fractional values using integers (more predictable than floating-point).
Your Fixed class stores a 32-bit 
integer where 8 bits represent the fractional part. 
*/