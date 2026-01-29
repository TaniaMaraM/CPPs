/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:12:59 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/29 16:53:34 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Fixed.hpp"

int main(void) {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	// my own tests for learning purporse
	std::cout << "\n=== TEST 1: COMPARISON OPERATORS ===" << std::endl;
	Fixed x(10);
	Fixed y(20);
	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "x > y: " << (x > y) << " (false = 0)" << std::endl;
	std::cout << "x < y: " << (x < y) << " (true = 1)" << std::endl;
	std::cout << "x == Fixed(10): " << (x == Fixed(10)) << " (true)" << std::endl;
	std::cout << "x != y: " << (x != y) << " (true)" << std::endl;

	std::cout << "\n=== TEST 2: ARITHMETIC OPERATORS ===" << std::endl;
	Fixed n1(10);
	Fixed n2(3);
	std::cout << "n1 = " << n1 << ", n2 = " << n2 << std::endl;
	std::cout << "n1 + n2 = " << (n1 + n2) << std::endl;
	std::cout << "n1 - n2 = " << (n1 - n2) << std::endl;
	std::cout << "n1 * n2 = " << (n1 * n2) << std::endl;
	std::cout << "n1 / n2 = " << (n1 / n2) << std::endl;

	std::cout << "\n=== TEST 3: PRE vs POST INCREMENT ===" << std::endl;
	Fixed pre(5);
	Fixed post(5);
	std::cout << "Initial: pre = " << pre << ", post = " << post << std::endl;
	std::cout << "++pre returns: " << ++pre << " (incremented BEFORE)" << std::endl;
	std::cout << "After ++pre: " << pre << std::endl;
	std::cout << "post++ returns: " << post++ << " (returns OLD value)" << std::endl;
	std::cout << "After post++: " << post << " (NOW incremented)" << std::endl;

	std::cout << "\n=== TEST 4: WHAT IS THE INCREMENT VALUE? ===" << std::endl;
	Fixed tiny(0);
	std::cout << "Start: " << tiny << " (rawBits: " << tiny.getRawBits() << ")" << std::endl;
	++tiny;
	std::cout << "After ++: " << tiny << " (rawBits: " << tiny.getRawBits() << ")" << std::endl;
	std::cout << "Increment = 1/256 = " << (1.0f/256.0f) << std::endl;

	std::cout << "\n=== TEST 5: MIN & MAX ===" << std::endl;
	Fixed m1(42.5f);
	Fixed m2(10.2f);
	std::cout << "m1 = " << m1 << ", m2 = " << m2 << std::endl;
	std::cout << "Fixed::min(m1, m2) = " << Fixed::min(m1, m2) << std::endl;
	std::cout << "Fixed::max(m1, m2) = " << Fixed::max(m1, m2) << std::endl;

	std::cout << "\n=== TEST 6: DIVISION BY ZERO (CAREFUL!) ===" << std::endl;
	Fixed div1(10);
	Fixed div2(0);
	std::cout << "10 / 0 = " << (div1 / div2) << " (undefined!)" << std::endl;

	return 0;
}
