/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:18:35 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/11 20:18:55 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_CPP
#define ANIMAL_CPP

#include <string>
#include <iostream>

class Animal {
protected:
    std::string type; //accesible by Animal and its children (dog and cat)
public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal(); //virtual pra apagar o animal que esta apontado para o dog por ex. deleta tudo
    
    virtual void makeSound() const = 0; // Pure virtual - Animal is now ABSTRACT!
    std::string getType() const;
};

#endif

/*
An abstract class contains at least one pure virtual function (marked with = 0). Key properties:
Cannot be instantiated - you cannot create objects of an abstract class
Forces derived classes to implement the pure virtual function
Serves as an interface - defines what derived classes must do

Uma classe abstracta é uma classe que não pode ser instanciada directamente 
- só existe para ser herdada. É como um "conceito" ou "template" que define o que as classes derivadas devem implementar.
*/