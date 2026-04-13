/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:14:27 by tmarcos           #+#    #+#             */
/*   Updated: 2026/04/13 20:45:38 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"
#include <iostream>
#include <string>

// function template - just read - const
template <typename T>
void print(T const &x)
{
    std::cout << x << std::endl;
}

// modifies each element — tests non-const reference
template <typename T>
void increment(T &x)
{
    x += 1;
}

int main( void )
{
    // --- int array ---
    std::cout << "=== int array ===" << std::endl;
    int intArr[] = {1, 2, 3, 4, 5};
    iter(intArr, 5, print<int>);

    // --- string array ---
    std::cout << "=== string array ===" << std::endl;
    std::string strArr[] = {"hello", "world", "42"};
    iter(strArr, 3, print<std::string>);

    // --- float array ---
    std::cout << "=== float array ===" << std::endl;
    float floatArr[] = {1.1f, 2.2f, 3.3f};
    iter(floatArr, 3, print<float>);

    // --- non-const: increment each int ---
    std::cout << "=== increment ints ===" << std::endl;
    iter(intArr, 5, increment<int>);
    iter(intArr, 5, print<int>);   // prints 2 3 4 5 6

    // --- const array: function must accept const ref ---
    std::cout << "=== const int array ===" << std::endl;
    const int constArr[] = {10, 20, 30};
    iter(constArr, 3, print<int>);

    return 0;
}
