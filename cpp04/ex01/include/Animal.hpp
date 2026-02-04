/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:18:35 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/04 20:50:48 by tmarcos          ###   ########.fr       */
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
    
    virtual void makeSound() const;
    std::string getType() const;
};

#endif