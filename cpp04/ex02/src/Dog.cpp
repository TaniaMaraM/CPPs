/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:44:15 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/18 22:45:58 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    this->brain = new Brain();  // allocate on heap (must delete in dtor)
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {  // copy base
    this->brain = new Brain(*other.brain);  // deep copy new Brain
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {  // self-assignment guard
        Animal::operator=(other);  // copy base part
        delete this->brain;  // free old brain
        this->brain = new Brain(*other.brain); // deep copy new Brain
    }
    return *this;
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {  // override of pure virtual - required or won't compile
    std::cout << "Woof! Woof!" << std::endl;
}