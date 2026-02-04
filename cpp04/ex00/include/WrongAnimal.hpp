/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:35:23 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/04 20:47:43 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
protected:
    std::string type;
    
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    ~WrongAnimal();
    
    void makeSound() const;
    std::string getType() const;
};

#endif

/*
The difference: NO virtual keyword on destructor or makeSound().
WrongCat inherits from WrongAnimal exactly like Cat inherits from Animal.
Result: When you do WrongAnimal* cat = new WrongCat(), 
calling cat->makeSound() gives you WrongAnimal's sound, 
not WrongCat's - demonstrating the problem
*/