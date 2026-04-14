/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:49:16 by tmarcos           #+#    #+#             */
/*   Updated: 2026/04/14 17:51:52 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"
#include <iostream>
#include <string>

int main(void)
{
    // --- constructors ---
    std::cout << "=== empty array ===" << std::endl;
    Array<int> empty;
    std::cout << "size: " << empty.size() << std::endl;  // 0

    std::cout << "=== array of 5 ints (default init) ===" << std::endl;
    Array<int> ints(5);
    std::cout << "size: " << ints.size() << std::endl;   // 5
    for (unsigned int i = 0; i < ints.size(); i++)
        std::cout << "ints[" << i << "] = " << ints[i] << std::endl;  // all 0

    std::cout << "=== write and read ===" << std::endl;
    for (unsigned int i = 0; i < ints.size(); i++)
        ints[i] = i * 10;
    for (unsigned int i = 0; i < ints.size(); i++)
        std::cout << "ints[" << i << "] = " << ints[i] << std::endl;  // 0 10 20 30 40

    std::cout << "=== const array (read only) ===" << std::endl;
    const Array<int> consts(3);
    std::cout << "consts[0] = " << consts[0] << std::endl;  // 0

    std::cout << "=== string array ===" << std::endl;
    Array<std::string> strs(3);
    strs[0] = "hello";
    strs[1] = "world";
    strs[2] = "42";
    for (unsigned int i = 0; i < strs.size(); i++)
        std::cout << "strs[" << i << "] = " << strs[i] << std::endl;

    std::cout << "=== copy independence ===" << std::endl;
    Array<int> a(3);
    a[0] = 1; a[1] = 2; a[2] = 3;
    Array<int> b = a;
    b[0] = 99;
    std::cout << "a[0] = " << a[0] << std::endl;  // still 1, not 99
    std::cout << "b[0] = " << b[0] << std::endl;  // 99

    std::cout << "=== out of bounds ===" << std::endl;
    try {
        std::cout << ints[99] << std::endl;
    } catch (std::exception& e) {
        std::cout << "exception caught: " << e.what() << std::endl;
    }

    return 0;
}

