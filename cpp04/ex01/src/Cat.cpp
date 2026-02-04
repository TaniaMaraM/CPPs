/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:45:50 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/04 21:43:36 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructor: ALOCA memória para Brain
Cat::Cat() {
    this->type = "Cat";
    this->brain = new Brain();  // Aloca Brain na heap
    std::cout << "Cat default constructor called" << std::endl;
}
// Copy constructor: cria NOVO Brain e copia conteúdo (DEEP COPY!)
Cat::Cat(const Cat& other) : Animal(other) {
    this->brain = new Brain(*other.brain);  // Cria NOVO Brain copiando o do other
    std::cout << "Cat copy constructor called" << std::endl;
}
// Assignment operator: deleta Brain antigo, cria novo, copia (DEEP COPY!)
Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete this->brain;                  // Liberta Brain antigo
        this->brain = new Brain(*other.brain);  // Cria novo e copia
    }
    return *this;
}
// Destructor: LIBERTA memória do Brain
Cat::~Cat() {
    delete this->brain;  // Liberta Brain da heap
    std::cout << "Cat destructor called" << std::endl;
}
void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea) {
    this->brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    return this->brain->getIdea(index);
}
