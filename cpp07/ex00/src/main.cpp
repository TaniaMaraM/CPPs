/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:25:48 by tmarcos           #+#    #+#             */
/*   Updated: 2026/04/13 20:13:14 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/whatever.hpp"
#include <iostream>
#include <string>

int main( void ) {
    std::cout << "=== Subject tests ===" << std::endl;
    //int tests
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    //string tests
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
    }

// int main () {
//     std::cout << "=== Test 1: equal values: min/max ===" << std::endl;
//     //must return the second one
//     int e = 5;
//     int f = 5;
//     std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl; // returns f (second)
//     std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl; // returns f (second)
//     std::cout << "=== Test 2: equal strings: ===" << std::endl;
//     //must return the second one ---
//     std::string s1 = "hello";
//     std::string s2 = "hello";
//     std::cout << "min( s1, s2 ) = " << ::min( s1, s2 ) << std::endl; // returns s2
//     std::cout << "max( s1, s2 ) = " << ::max( s1, s2 ) << std::endl; // returns s2
//     std::cout << "=== Test 3: Float ===" << std::endl;
//     float g = 1.5f;
//     float h = 2.7f;
//     ::swap( g, h );
//     std::cout << "g = " << g << ", h = " << h << std::endl;      // g=2.7, h=1.5
//     std::cout << "min( g, h ) = " << ::min( g, h ) << std::endl; // returns 1.5
//     std::cout << "max( g, h ) = " << ::max( g, h ) << std::endl; // returns 2.7
//     std::cout << "=== Test 4: Chars: ===" << std::endl;    char x = 'a';
//     char y = 'z';
//     ::swap( x, y );
//     std::cout << "x = " << x << ", y = " << y << std::endl;      // x=z, y=a
//     std::cout << "min( x, y ) = " << ::min( x, y ) << std::endl; // returns 'a'
//     std::cout << "max( x, y ) = " << ::max( x, y ) << std::endl; // returns 'z'
// }

