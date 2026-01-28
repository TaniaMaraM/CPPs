/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:44:02 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/28 18:16:41 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {
    // weapon começa NULL (sem arma)
}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;  // guarda ENDEREÇO da arma
}

void HumanB::attack() const {
    if (weapon)  // verifica se tem arma!
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon!" << std::endl;
}