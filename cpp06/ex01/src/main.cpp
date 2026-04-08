/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 21:08:22 by tmarcos           #+#    #+#             */
/*   Updated: 2026/04/08 21:49:45 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"
#include "../include/Data.hpp"
#include <iostream>

int main()
{
    // Create a Data object
    Data original;
    original.value = 42;
    
    std::cout << "=== SERIALIZATION TEST ===" << std::endl;
    std::cout << std::endl;
    
    // Show original data
    std::cout << "Original Data:" << std::endl;
    std::cout << "  Address: " << &original << std::endl;
    std::cout << "  Value:   " << original.value << std::endl;
    std::cout << std::endl;
    
    // Serialize: pointer -> number
    uintptr_t serialized = Serializer::serialize(&original);
    std::cout << "Serialized to: " << serialized << std::endl;
    std::cout << std::endl;
    
    // Deserialize: number -> pointer
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized back to:" << std::endl;
    std::cout << "  Address: " << deserialized << std::endl;
    std::cout << "  Value:   " << deserialized->value << std::endl;
    std::cout << std::endl;
    
    // Verify pointers are equal
    if (deserialized == &original)
        std::cout << "✅ SUCCESS: Pointers match!" << std::endl;
    else
        std::cout << "❌ FAIL: Pointers don't match!" << std::endl;
    
    return 0;
}
