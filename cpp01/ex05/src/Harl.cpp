/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:06:46 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/28 19:14:41 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug() {
    std::cout << "I love having extra bacon for my burger. I really do!" << std::endl;
}

void Harl::info() {
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
}

void Harl::warning() {
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
}

void Harl::error() {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
    // Array de nomes dos níveis
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    // Array de pointers para member functions
    void (Harl::*functions[])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    
    // Procura o nível e chama a função correspondente
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            (this->*functions[i])();  // chama a função!
            return;
        }
    }
    
    std::cout << "Unknown level: " << level << std::endl;
}