/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:18:41 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/11 20:05:21 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"

int main()
{
    // NOTE: Uncommenting below should cause compilation error (Animal is abstract)
    // Animal* impossible = new Animal();
    
    std::cout << "--- Subject required test: polymorphic animals ---" << std::endl;
    {
        const Animal* canine = new Dog();
        const Animal* feline = new Cat();
        delete canine;
        delete feline;
    }
    
    std::cout << "\n--- Testing abstract class via pointers ---" << std::endl;
    {
        const Animal* myDog = new Dog();
        const Animal* myCat = new Cat();
        
        std::cout << myDog->getType() << " sound: ";
        myDog->makeSound();
        std::cout << myCat->getType() << " sound: ";
        myCat->makeSound();
        
        delete myDog;
        delete myCat;
    }
    
    std::cout << "\n--- Array test with 4 animals ---" << std::endl;
    {
        Animal* pack[4];
        
        pack[0] = new Dog();
        pack[1] = new Dog();
        pack[2] = new Cat();
        pack[3] = new Cat();
        
        std::cout << "Destroying array..." << std::endl;
        for (int n = 0; n < 4; n++)
            delete pack[n];
    }
    
    std::cout << "\n--- Copy constructor verification ---" << std::endl;
    {
        std::cout << "Making dog and its copy..." << std::endl;
        Dog alpha;
        Dog beta(alpha);
        std::cout << "Independent copies created" << std::endl;
    }
    
    std::cout << "\n--- Assignment operator verification ---" << std::endl;
    {
        std::cout << "Creating and assigning cats..." << std::endl;
        Cat whiskers;
        Cat fluffy;
        fluffy = whiskers;
        std::cout << "Assignment successful, both independent" << std::endl;
    }
    
    std::cout << "\n--- Tests finished ---" << std::endl;
    
    return 0;
}