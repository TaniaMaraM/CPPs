/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:59:45 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/17 17:41:02 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

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

// Destructor
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
