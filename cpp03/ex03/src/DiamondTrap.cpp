/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:59:45 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/16 23:02:39 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

// DIAMOND INHERITANCE CONSTRUCTOR CHAIN:
// 1. ClapTrap(name + "_clap_name") - virtual base called FIRST and ONCE
// 2. ScavTrap(name) - but its ClapTrap call is ignored (virtual!)
// 3. FragTrap(name) - but its ClapTrap call is ignored (virtual!)
// 4. DiamondTrap body - mix stats from both parents
//
// DiamondTrap has TWO names:
// - this->name (DiamondTrap's own): "MEGATRON"
// - ClapTrap::name (inherited): "MEGATRON_clap_name"
//
// Mixed stats: HP=100 (Frag), Energy=50 (Scav), Damage=30 (Frag)
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
	this->hitPoints = FragTrap::hitPoints;      // 100 from FragTrap
	this->energyPoints = ScavTrap::energyPoints; // 50 from ScavTrap
	this->attackDamage = FragTrap::attackDamage; // 30 from FragTrap
	std::cout << "DiamondTrap " << this->name << " has been created!" << std::endl;
}

// Copy constructor: calls all parent copy constructors in order
DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	this->name = other.name;
	std::cout << "DiamondTrap " << this->name << " has been created as a copy!" << std::endl;
}

// Assignment: delegates to base class and copies own name
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->name = other.name;
	}
	return *this;
}

// Destructor: runs FIRST, then FragTrap, ScavTrap, finally ClapTrap (once!)
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << " has been destroyed!" << std::endl;
}

// DiamondTrap unique ability: reveals dual identity
// Shows both DiamondTrap::name and ClapTrap::name
void DiamondTrap::whoAmI()
{
	std::cout << "I am DiamondTrap " << this->name
			  << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}

// NOTE: attack() comes from "using ScavTrap::attack;" in header
// DiamondTrap uses ScavTrap's "fiercely" version, not ClapTrap's base version

