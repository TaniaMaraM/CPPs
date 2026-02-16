/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:22:37 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/30 18:26:52 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

// PUBLIC inheritance from ClapTrap
// Stats: 100 HP, 50 Energy, 20 Damage
class ScavTrap : public ClapTrap {
public:
	// Orthodox Canonical Form
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& other);
	~ScavTrap();

	// OVERRIDES ClapTrap::attack() with "fiercely" message
	void attack(const std::string& target);
	// ScavTrap unique ability
	void guardGate();
};

#endif
