/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 21:17:17 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/11 20:29:02 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
private:
    std::string ideas[100];
public:
    // Orthodox Canonical Form
    Brain();
    Brain(const Brain& other); 
    Brain& operator=(const Brain& other);
    ~Brain();
    
    // Métodos para testar deep copy
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif

/*
SHALLOW COPY
 dog1 → brain (ponteiro) → [Brain object na memória]
                            ↑
dog2 → brain (ponteiro) ----┘
       (copia o endereço)

Problema: ambos apontam para o MESMO Brain!
Se dog1 mudar uma ideia, dog2 vê a mudança também!
Se dog1 for destruído, delete brain → dog2 fica com ponteiro inválido (CRASH!)

DEEP COPY
dog1 → brain → [Brain object #1 na memória]

dog2 → brain → [Brain object #2 na memória] (NOVA cópia)

Solução: cada um tem o SEU próprio Brain!
Independentes, seguros, sem problemas!
*/