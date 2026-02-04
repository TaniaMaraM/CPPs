/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:18:41 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/04 21:47:10 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "=== Test 1: Subject required test ===" << std::endl;
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;  // should not create a leak
        delete i;
    }
    
    std::cout << "\n=== Test 2: Basic polymorphic calls ===" << std::endl;
    {
        const Animal* base = new Animal();
        const Animal* dog = new Dog();
        const Animal* cat = new Cat();
        
        std::cout << "Type dog: " << dog->getType() << std::endl;
        std::cout << "Type cat: " << cat->getType() << std::endl;
        std::cout << "Cat says: ";
        cat->makeSound();
        std::cout << "Dog says: ";
        dog->makeSound();
        std::cout << "Generic Animal says: ";
        base->makeSound();
        
        delete base;
        delete dog;
        delete cat;
    }
    
    std::cout << "\n=== Test 3: Array of Animals (half Dog, half Cat) ===" << std::endl;
    {
        const int size = 6;
        Animal* animals[size];
        
        std::cout << "Creating array..." << std::endl;
        for (int i = 0; i < size / 2; i++)
            animals[i] = new Dog();
        for (int i = size / 2; i < size; i++)
            animals[i] = new Cat();
        
        std::cout << "\nTesting each animal:" << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << "Animal[" << i << "] is a " << animals[i]->getType() << " -> ";
            animals[i]->makeSound();
        }
        
        std::cout << "\nDeleting all animals:" << std::endl;
        for (int i = 0; i < size; i++)
            delete animals[i];
    }
    
    std::cout << "\n=== Test 4: Deep copy with copy constructor ===" << std::endl;
    {
        Cat originalCat;
        originalCat.setIdea(0, "catnip");
        originalCat.setIdea(1, "sleep all day");
        
        std::cout << "\nCreating copy using copy constructor..." << std::endl;
        Cat copiedCat(originalCat);
        
        std::cout << "Original cat idea[0]: " << originalCat.getIdea(0) << std::endl;
        std::cout << "Copied cat idea[0]:   " << copiedCat.getIdea(0) << std::endl;
        
        std::cout << "\nChanging individual ideas..." << std::endl;
        originalCat.setIdea(0, "fish");
        copiedCat.setIdea(0, "milk");
        
        std::cout << "After changes:" << std::endl;
        std::cout << "Original cat idea[0]: " << originalCat.getIdea(0) << std::endl;
        std::cout << "Copied cat idea[0]:   " << copiedCat.getIdea(0) << std::endl;
        
        if (originalCat.getIdea(0) != copiedCat.getIdea(0))
            std::cout << "✅ Deep copy confirmed - ideas are independent!" << std::endl;
    }
    
    std::cout << "\n=== Test 5: Deep copy with assignment operator ===" << std::endl;
    {
        Dog originalDog;
        Dog anotherDog;
        
        originalDog.setIdea(1, "chase cats");
        std::cout << "\nAssigning originalDog to anotherDog..." << std::endl;
        anotherDog = originalDog;
        
        std::cout << "Original dog idea[1]: " << originalDog.getIdea(1) << std::endl;
        std::cout << "Another dog idea[1]:  " << anotherDog.getIdea(1) << std::endl;
        
        std::cout << "\nChanging individual ideas..." << std::endl;
        originalDog.setIdea(1, "play fetch");
        anotherDog.setIdea(1, "eat bone");
        
        std::cout << "After changes:" << std::endl;
        std::cout << "Original dog idea[1]: " << originalDog.getIdea(1) << std::endl;
        std::cout << "Another dog idea[1]:  " << anotherDog.getIdea(1) << std::endl;
        
        if (originalDog.getIdea(1) != anotherDog.getIdea(1))
            std::cout << "✅ Deep copy confirmed - ideas are independent!" << std::endl;
    }
    
    std::cout << "\n=== Test 6: Self-assignment ===" << std::endl;
    {
        Dog dog;
        dog.setIdea(0, "original idea");
        Dog& ref = dog;
        
        std::cout << "Self-assigning via reference..." << std::endl;
        dog = ref;
        std::cout << "Idea after self-assignment: " << dog.getIdea(0) << std::endl;
        std::cout << "✅ No crash - self-assignment handled correctly!" << std::endl;
    }
    
    std::cout << "\n=== Test 7: Copy survives original deletion ===" << std::endl;
    {
        Dog* original = new Dog();
        original->setIdea(0, "temporary idea");
        
        std::cout << "Creating copy of heap-allocated Dog..." << std::endl;
        Dog copy(*original);
        
        std::cout << "Copy's idea: " << copy.getIdea(0) << std::endl;
        std::cout << "\nDeleting original..." << std::endl;
        delete original;
        
        std::cout << "Copy still valid - idea: " << copy.getIdea(0) << std::endl;
        std::cout << "Copy can still make sound: ";
        copy.makeSound();
        std::cout << "✅ Copy survived original's deletion!" << std::endl;
    }
    
    std::cout << "\n=== All tests completed ===" << std::endl;
    
    return 0;
}