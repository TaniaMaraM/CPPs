/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:45:50 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/18 22:45:51 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    this->brain = new Brain();  // allocate on heap (must delete in dtor)
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {  // copy base part (type)
    this->brain = new Brain(*other.brain);  // deep copy new Brain
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {  // self-assignment guard
        Animal::operator=(other);  // copy base part
        delete this->brain;  // free old brain
        this->brain = new Brain(*other.brain);  // deep copy new Brain
    }
    return *this;
}

Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {  // override of pure virtual - required or won't compile
    std::cout << "Meow! Meow!" << std::endl;
}

