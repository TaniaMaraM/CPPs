/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:07:38 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/17 12:27:57 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int					fixedPointValue; // Stores value * 256 (8 fractional bits)
	static const int	fractionalBits = 8; //shared by all instances

public:
	// Constructors & Destructor (Orthodox Canonical Form)
	Fixed(void);
	Fixed(const int n);
	Fixed(const float f);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed(void);
	//Conversions
	float	toFloat(void) const;
	int		toInt(void) const;
	// Getters/Setters
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
