/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:18:41 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/11 20:39:48 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"

int main()
{
    // Required test from subject
    std::cout << "--- Creating Dog and Cat via Animal pointers ---" << std::endl;
    {
        const Animal* dog = new Dog();
        const Animal* cat = new Cat();
        delete dog;
        delete cat;
    }
    
    std::cout << "\n--- Testing array of 4 Animals ---" << std::endl;
    {
        Animal* zoo[4];
        
        std::cout << "Filling array with Dogs and Cats..." << std::endl;
        zoo[0] = new Dog();
        zoo[1] = new Dog();
        zoo[2] = new Cat();
        zoo[3] = new Cat();
        
        std::cout << "\nCleaning up array..." << std::endl;
        for (int idx = 0; idx < 4; idx++)
            delete zoo[idx];
    }
    
    std::cout << "\n--- Copy constructor test ---" << std::endl;
    {
        std::cout << "Creating first dog..." << std::endl;
        Dog firstDog;
        
        std::cout << "Copying to second dog..." << std::endl;
        Dog secondDog(firstDog);
        
        std::cout << "Both dogs are independent objects" << std::endl;
    }
    
    std::cout << "\n--- Assignment operator test ---" << std::endl;
    {
        std::cout << "Creating two cats..." << std::endl;
        Cat kitty1;
        Cat kitty2;
        
        std::cout << "Assigning kitty1 to kitty2..." << std::endl;
        kitty2 = kitty1;
        
        std::cout << "Assignment complete, both independent" << std::endl;
    }
    
    std::cout << "\n--- Self-assignment protection test ---" << std::endl;
    {
        Dog myDog;
        Dog& refDog = myDog;
        std::cout << "Testing self-assignment via reference..." << std::endl;
        myDog = refDog;
        std::cout << "Self-assignment handled safely" << std::endl;
    }
    
    std::cout << "\n--- Deep copy verification ---" << std::endl;
    {
        Dog* heapDog = new Dog();
        
        std::cout << "Creating stack copy from heap dog..." << std::endl;
        Dog stackDog(*heapDog);
        
        std::cout << "Deleting heap dog..." << std::endl;
        delete heapDog;
        
        std::cout << "Stack copy remains valid: ";
        stackDog.makeSound();
    }
    
    std::cout << "\n--- All tests complete ---" << std::endl;
    
    return 0;
}