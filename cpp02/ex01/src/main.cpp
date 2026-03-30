/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:08:22 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/17 12:48:04 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Fixed.hpp"

int main(void) {

	Fixed a;

	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	// EXTRA TESTS
	std::cout << "\n=== TEST 1: Fixed-Point Precision ===" << std::endl;
	Fixed test1(0.5f);
	std::cout << "0.5f -> Fixed -> toFloat(): " << test1.toFloat() << std::endl;
	std::cout << "0.5f -> Fixed -> toInt(): " << test1.toInt() << std::endl;
	std::cout << "getRawBits(): " << test1.getRawBits() << " (0.5 × 256 = 128)" << std::endl;

	std::cout << "\n=== TEST 2: Negative Numbers ===" << std::endl;
	Fixed test2(-42);
	Fixed test3(-42.42f);
	std::cout << "Fixed(-42) = " << test2 << " (int: " << test2.toInt() << ")" << std::endl;
	std::cout << "Fixed(-42.42f) = " << test3 << " (int: " << test3.toInt() << ")" << std::endl;

	std::cout << "\n=== TEST 3: Precision Loss ===" << std::endl;
	Fixed test4(42.999f);
	std::cout << "42.999f -> Fixed: " << test4 << std::endl;
	std::cout << "Integer part: " << test4.toInt() << std::endl;
	std::cout << "Explanation: Fixed stores ~42.998 (limited precision)" << std::endl;

	std::cout << "\n=== TEST 4: Small Fractions ===" << std::endl;
	Fixed test5(0.00390625f);  // 1/256 (smallest representable fraction)
	Fixed test6(0.001f);       // Smaller than 1/256
	std::cout << "1/256 (0.00390625f): " << test5 << std::endl;
	std::cout << "0.001f: " << test6 << " (loses precision!)" << std::endl;

	std::cout << "\n=== TEST 5: Zero ===" << std::endl;
	Fixed test9;
	Fixed test10(0);
	Fixed test11(0.0f);
	std::cout << "Default: " << test9 << " (rawBits: " << test9.getRawBits() << ")" << std::endl;
	std::cout << "Fixed(0): " << test10 << " (rawBits: " << test10.getRawBits() << ")" << std::endl;
	std::cout << "Fixed(0.0f): " << test11 << " (rawBits: " << test11.getRawBits() << ")" << std::endl;

	return 0;
}
