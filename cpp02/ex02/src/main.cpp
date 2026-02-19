/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:12:59 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/17 13:27:35 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Fixed.hpp"

int main(void) {
	// Subject's required tests
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	// Additional comprehensive tests
	{
		std::cout << "\n=== Testing Arithmetic Operators ===" << std::endl;
		Fixed x(10);
		Fixed y(3);

		std::cout << "x = " << x << std::endl;
		std::cout << "y = " << y << std::endl;
		std::cout << "x + y = " << (x + y) << std::endl;
		std::cout << "x - y = " << (x - y) << std::endl;
		std::cout << "x * y = " << (x * y) << std::endl;
		std::cout << "x / y = " << (x / y) << std::endl;
	}
	{
		std::cout << "\n=== Testing Floating Point Precision ===" << std::endl;
		Fixed p(0.5f);
		Fixed q(0.25f);

		std::cout << "p = " << p << std::endl;
		std::cout << "q = " << q << std::endl;
		std::cout << "p + q = " << (p + q) << std::endl;
		std::cout << "p * q = " << (p * q) << std::endl;
	}
	{
		std::cout << "\n=== Testing Comparison Operators ===" << std::endl;
		Fixed a1(5);
		Fixed a2(5);
		Fixed a3(10);

		std::cout << "a1 = " << a1 << std::endl;
		std::cout << "a2 = " << a2 << std::endl;
		std::cout << "a3 = " << a3 << std::endl;
		std::cout << "a1 == a2: " << (a1 == a2) << std::endl;
		std::cout << "a1 != a3: " << (a1 != a3) << std::endl;
		std::cout << "a1 < a3: " << (a1 < a3) << std::endl;
		std::cout << "a3 > a2: " << (a3 > a2) << std::endl;
		std::cout << "a1 <= a2: " << (a1 <= a2) << std::endl;
		std::cout << "a3 >= a1: " << (a3 >= a1) << std::endl;
	}
	{
		std::cout << "\n=== Testing Increment/Decrement ===" << std::endl;
		Fixed v1(5);
		Fixed v2(5);

		std::cout << "Initial: v1 = " << v1 << ", v2 = " << v2 << std::endl;
		std::cout << "++v1 returns: " << ++v1 << std::endl;
		std::cout << "v1 after ++v1: " << v1 << std::endl;
		std::cout << "v2++ returns: " << v2++ << std::endl;
		std::cout << "v2 after v2++: " << v2 << std::endl;
		std::cout << "--v1 returns: " << --v1 << std::endl;
		std::cout << "v1-- returns: " << v1-- << std::endl;
		std::cout << "v1 after v1--: " << v1 << std::endl;
	}
	{
		std::cout << "\n=== Testing min/max (non-const) ===" << std::endl;
		Fixed b1(15.5f);
		Fixed b2(7.25f);

		std::cout << "b1 = " << b1 << std::endl;
		std::cout << "b2 = " << b2 << std::endl;
		std::cout << "Fixed::min(b1, b2) = " << Fixed::min(b1, b2) << std::endl;
		std::cout << "Fixed::max(b1, b2) = " << Fixed::max(b1, b2) << std::endl;

		Fixed &maxRef = Fixed::max(b1, b2);
		std::cout << "\nModifying max (b1) to 100..." << std::endl;
		maxRef = Fixed(100);
		std::cout << "After modification: b1 = " << b1 << ", b2 = " << b2 << std::endl;
	}
	{
		std::cout << "\n=== Testing min/max (const) ===" << std::endl;
		Fixed const c1(8.5f);
		Fixed const c2(12.75f);

		std::cout << "c1 = " << c1 << std::endl;
		std::cout << "c2 = " << c2 << std::endl;
		std::cout << "Fixed::min(c1, c2) = " << Fixed::min(c1, c2) << std::endl;
		std::cout << "Fixed::max(c1, c2) = " << Fixed::max(c1, c2) << std::endl;
	}
	{
		std::cout << "\n=== Testing Negative Numbers ===" << std::endl;
		Fixed n1(-7.5f);
		Fixed n2(3.25f);
		Fixed n3(-2.5f);

		std::cout << "n1 = " << n1 << std::endl;
		std::cout << "n2 = " << n2 << std::endl;
		std::cout << "n3 = " << n3 << std::endl;
		std::cout << "n1 + n2 = " << (n1 + n2) << std::endl;
		std::cout << "n1 - n2 = " << (n1 - n2) << std::endl;
		std::cout << "n1 * n2 = " << (n1 * n2) << std::endl;
		std::cout << "n1 / n3 = " << (n1 / n3) << std::endl;
		std::cout << "n1 < n2: " << (n1 < n2) << std::endl;
		std::cout << "n3 > n1: " << (n3 > n1) << std::endl;
	}

	return 0;
}
