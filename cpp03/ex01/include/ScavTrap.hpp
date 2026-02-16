/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:22:37 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/16 22:54:04 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

// PUBLIC inheritance: "is-a" relationship (ScavTrap IS A ClapTrap)
// Inherits all public/protected members from ClapTrap
class ScavTrap : public ClapTrap {
public:
	// Orthodox Canonical Form - must call base class equivalents
	ScavTrap(std::string name);              // Calls ClapTrap(name) first
	ScavTrap(const ScavTrap& other);         // Calls ClapTrap(other) first
	ScavTrap& operator=(const ScavTrap& other);
	~ScavTrap();                             // Base destructor called after

	// OVERRIDES ClapTrap::attack() with different message
	void attack(const std::string& target); //attacks fiercely
	// NEW ability - only ScavTrap has this
	void guardGate();

	// NOTE: takeDamage() and beRepaired() are INHERITED (not declared here)
};

#endif
