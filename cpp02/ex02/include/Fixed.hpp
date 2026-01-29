/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:15:12 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/29 16:44:14 by tmarcos          ###   ########.fr       */
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
	Fixed(void);
	Fixed(const int n);
	Fixed(const float f);
	Fixed(const Fixed& other);
	~Fixed(void);
	// Assignment operator
	Fixed& operator=(const Fixed& other);
	// Comparison operators (6)
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;
	// Arithmetic operators (4)
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;
	// Increment/Decrement operators (4)
	Fixed& operator++(void);      // Pre-increment ++a
	Fixed  operator++(int);       // Post-increment a++
	Fixed& operator--(void);      // Pre-decrement
	Fixed  operator--(int);       // Post-decrement
	// Conversions
	float	toFloat(void) const;
	int		toInt(void) const;
	// Getters/Setters
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	// Static member functions (4)
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
};

// Stream insertion operator
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
