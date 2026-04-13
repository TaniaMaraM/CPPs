/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 22:00:00 by tmarcos           #+#    #+#             */
/*   Updated: 2026/04/12 18:12:07 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/functions.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include <cstdlib>   // rand, srand
#include <ctime>     // time
#include <iostream>
#include <exception>
#include "../include/Base.hpp"

Base::~Base() {}

// Randomly generates A, B, or C
Base* generate(void)
{
    // Seed random (only once)
    static bool seeded = false;
    if (!seeded)
    {
        std::srand(std::time(NULL));
        seeded = true;
    }
    
    // Random number 0, 1, or 2
    int random = std::rand() % 3;
    
    switch (random)
    {
        case 0:
            std::cout << "Generated: A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated: B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated: C" << std::endl;
            return new C();
        default:
            return NULL;
    }
}

// Identify using pointer
void identify(Base* p)
{
    // Try to cast to A*
    if (dynamic_cast<A*>(p))
    {
        std::cout << "A" << std::endl;
        return;
    }
    
    // Try to cast to B*
    if (dynamic_cast<B*>(p))
    {
        std::cout << "B" << std::endl;
        return;
    }
    
    // Try to cast to C*
    if (dynamic_cast<C*>(p))
    {
        std::cout << "C" << std::endl;
        return;
    }
    
    std::cout << "Unknown type" << std::endl;
}

// Identify using reference (no pointers allowed!)
void identify(Base& p)
{
    // Try to cast to A&
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::exception&) {}
    
    // Try to cast to B&
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::exception&) {}
    
    // Try to cast to C&
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (std::exception&) {}
    
    std::cout << "Unknown type" << std::endl;
}
