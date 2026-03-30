/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 21:03:41 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/17 12:27:27 by tmarcos          ###   ########.fr       */
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
	// Constructors & Destructor (Orthodox Canonical Form)
	Fixed(void);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	
	// Getters/Setters
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
