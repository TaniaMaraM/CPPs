/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:15:12 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/17 12:52:49 by tmarcos          ###   ########.fr       */
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
	// Constructors & Destructor (Orthodox Canonical Form)
	Fixed(void);
	Fixed(const int n);
	Fixed(const float f);
	Fixed(const Fixed& other);
	~Fixed(void);

	Fixed& operator=(const Fixed& other);
	// Comparison operators
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;
	// Arithmetic operators
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;
	// Increment/Decrement operators
	Fixed& operator++(void); // Pre-increment
	Fixed  operator++(int); //post-increment
	Fixed& operator--(void);
	Fixed  operator--(int);
	// Conversions
	float	toFloat(void) const;
	int		toInt(void) const;
	// Getters/Setters
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	//min and max 
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
