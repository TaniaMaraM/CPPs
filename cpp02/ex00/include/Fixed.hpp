/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 21:03:41 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/11 20:57:49 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
private:
	int					fixedPointValue;
	static const int	fractionalBits = 8;

public:
	// Orthodox Canonical Form
	Fixed( void );							// Default constructor
	Fixed( const Fixed& other );			// Copy constructor
	Fixed& operator=( const Fixed& other );	// Copy assignment operator
	~Fixed();							// Destructor

	// Member functions
	void	setRawBits( int const raw );
	int		getRawBits( void ) const;
};

#endif
