/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:18:41 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/04 20:54:29 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Testing correct polymorphism ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "\n--- Testing getType() ---" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    std::cout << "\n--- Testing makeSound() ---" << std::endl;
    i->makeSound(); // Will output cat sound (virtual works!)
    j->makeSound(); // Will output dog sound (virtual works!)
    meta->makeSound(); // Generic animal sound
    
    std::cout << "\n--- Deleting animals ---" << std::endl;
    delete i;
    delete j;
    delete meta;
    
    std::cout << "\n\n=== Testing WRONG polymorphism ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << "\n--- Wrong makeSound() ---" << std::endl;
    wrongCat->makeSound(); // Will output WrongAnimal sound (no virtual!)
    wrongMeta->makeSound();
    
    std::cout << "\n--- Deleting wrong animals ---" << std::endl;
    delete wrongCat;
    delete wrongMeta;
    
    return 0;
}