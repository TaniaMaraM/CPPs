/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:07:38 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/29 15:49:26 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int					fixedPointValue;
	static const int	fractionalBits = 8;

public:
	// Constructors & Destructor
	Fixed( void );
	Fixed( const int n );
	Fixed( const float f );
	Fixed( const Fixed& other );
	Fixed& operator=( const Fixed& other );
	~Fixed( void );
	// Conversions
	float	toFloat( void ) const;
	int		toInt( void ) const;
	// Getters/Setters
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

// Operator overload (fora da classe!) <<  STREAM INSERTION OPERATOR
std::ostream& operator<<( std::ostream& out, const Fixed& fixed );

#endif
