/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:44:06 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/29 14:24:12 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// IMPORTANTE: reference DEVE ser inicializada na initialization list!
HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {
}

void HumanA::attack() const {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
