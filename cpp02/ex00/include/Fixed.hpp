/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 21:03:41 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/12 12:10:11 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
private:
	int					fixedPointValue;	// Stores the fixed-point value (actual_value * 256)
	static const int	fractionalBits = 8;	// Class constant: shared by all instances, not per-object

public:
	// Orthodox Canonical Form (Coplien's Form) - the 4 essential functions every class needs
	Fixed( void );							// Default constructor
	Fixed( const Fixed& other );			// Copy constructor - creates new object from existing one
	Fixed& operator=( const Fixed& other );	// Copy assignment - assigns to already-existing object
	~Fixed();								// Destructor - cleanup when object goes out of scope

	// Member functions - encapsulation: controlled access to private data
	void	setRawBits( int const raw );
	int		getRawBits( void ) const;		// const: promises not to modify object, allows use on const objects
};

#endif

/*

 we use 8 fractional bits out of a 32-bit 
 integer. This means we multiply a number 
 by 2^8 (256) to convert it to fixed-point 
 representation, and divide by 256 to convert it back.*/