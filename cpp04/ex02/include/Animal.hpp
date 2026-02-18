/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:18:35 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/18 22:58:05 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();
    
    virtual void makeSound() const = 0;  // pure virtual: Animal is abstract - Dog/Cat must override
    std::string getType() const;
};

#endif


/*
-> Virtual means: this function has a default implementation in the base class,
but derived classes may override it if they want to. 
-> Pure virtual means: there is no implementation at all in the base class 
— derived classes must provide one, 
or they also become abstract and can't be instantiated.
*/