/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 22:00:00 by tmarcos           #+#    #+#             */
/*   Updated: 2026/04/08 22:09:27 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/functions.hpp"
#include <iostream>

int main()
{
    std::cout << "=== TYPE IDENTIFICATION TEST ===" << std::endl;
    std::cout << std::endl;
    
    // Generate 5 random objects
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Test " << i + 1 << ":" << std::endl;
        
        Base* ptr = generate();
        
        std::cout << "  identify(ptr):  ";
        identify(ptr);
        
        std::cout << "  identify(*ptr): ";
        identify(*ptr);
        
        delete ptr;
        std::cout << std::endl;
    }
    
    return 0;
}
