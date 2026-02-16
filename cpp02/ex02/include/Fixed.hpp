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
	int					fixedPointValue;	// Stores value * 256
	static const int	fractionalBits = 8;	// Shared constant for all instances

public:
	// Constructors & Destructor (Orthodox Canonical Form) - silent now, no debug messages
	Fixed(void);
	Fixed(const int n);
	Fixed(const float f);
	Fixed(const Fixed& other);
	~Fixed(void);
	// Assignment operator
	Fixed& operator=(const Fixed& other);
	// Comparison operators (6) - all const, compare raw values directly (preserves ordering)
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;
	// Arithmetic operators (4) - all const, return new Fixed by value (local result)
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;	// No division-by-zero protection!
	// Increment/Decrement operators (4) - increment by 1 raw unit = 1/256 actual value
	Fixed& operator++(void);      // Pre-increment ++a: increment first, return by reference
	Fixed  operator++(int);       // Post-increment a++: save old, increment, return old by value (int is dummy)
	Fixed& operator--(void);      // Pre-decrement --a
	Fixed  operator--(int);       // Post-decrement a-- (int dummy distinguishes from prefix)
	// Conversions
	float	toFloat(void) const;
	int		toInt(void) const;
	// Getters/Setters
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	// Static member functions (4) - don't need object to call, compare two equal objects
	// Function overloading: const vs non-const versions for const-correctness
	static Fixed& min(Fixed& a, Fixed& b);				// Returns modifiable reference
	static const Fixed& min(const Fixed& a, const Fixed& b);	// Returns const reference
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
};

// Stream insertion operator
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
