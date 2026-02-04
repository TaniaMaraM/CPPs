/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 21:17:27 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/04 21:48:16 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructor: inicializa o array vazio (strings já são vazias por default)
Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
}

// Copy constructor: copia TODAS as 100 ideias
Brain::Brain(const Brain& other) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = other.ideas[i];  // Copia cada string
    }
}

// Assignment operator: copia TODAS as 100 ideias
Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &other) {  // Verifica self-assignment
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

// Destructor: não precisa fazer nada (std::string limpa-se automaticamente)
Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}
// Define uma ideia no índice específico
void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {  // Validação de limites
        ideas[index] = idea;
    }
}
// Obtém uma ideia do índice específico
std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return ideas[index];
    }
    return "";  // Retorna vazio se índice inválido
}