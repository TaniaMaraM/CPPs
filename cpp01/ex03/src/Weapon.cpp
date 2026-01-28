/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:44:08 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/28 18:15:06 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) { //Quando eu criar um Weapon, inicialize o atributo type
//usando o parâmetro type que eu recebi.
}

const std::string& Weapon::getType() const {
    return type;  // retorna referência (não copia string!)
}

void Weapon::setType(std::string type) {
    this->type = type;
}