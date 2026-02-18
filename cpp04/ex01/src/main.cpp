/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:18:41 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/18 22:21:01 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"

int main()
{
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
    
    // Proves deep copy: secondDog has its own Brain
    std::cout << "\n--- Copy constructor test ---" << std::endl;
    {
        std::cout << "Creating first dog..." << std::endl;
        Dog firstDog;
        
        std::cout << "Copying to second dog..." << std::endl;
        Dog secondDog(firstDog);  // deep copy: new Brain created
        
        std::cout << "Both dogs are independent objects" << std::endl;
    }  // both destructors run, each deletes its own Brain
    
    // Proves op= does deep copy: kitty2 gets new Brain, old one freed
    std::cout << "\n--- Assignment operator test ---" << std::endl;
    {
        std::cout << "Creating two cats..." << std::endl;
        Cat kitty1;
        Cat kitty2;
        
        std::cout << "Assigning kitty1 to kitty2..." << std::endl;
        kitty2 = kitty1;  // deletes kitty2's old brain, deep copies kitty1's
        
        std::cout << "Assignment complete, both independent" << std::endl;
    }
    
    //proves self-assignment guard works - if (this != &other)
    std::cout << "\n--- Self-assignment protection test ---" << std::endl;
    {
        Dog myDog;
        Dog& refDog = myDog;
        std::cout << "Testing self-assignment via reference..." << std::endl;
        myDog = refDog;  // guard prevents delete then use of same brain
        std::cout << "Self-assignment handled safely" << std::endl;
    }
    
    // Proves deep copy: after deleting original, copy still works
    std::cout << "\n--- Deep copy verification ---" << std::endl;
    {
        Dog* heapDog = new Dog();
        
        std::cout << "Creating stack copy from heap dog..." << std::endl;
        Dog stackDog(*heapDog);  // deep copy
        
        std::cout << "Deleting heap dog..." << std::endl;
        delete heapDog;  // frees heapDog Brain - it proves that is not a shallow copy
        
        std::cout << "Stack copy remains valid: ";
        stackDog.makeSound();  // still works - dog woof - and has its own Brain
    }
    
    std::cout << "\n--- All tests complete ---" << std::endl;
    
    return 0;
}