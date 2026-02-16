/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:39:22 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/16 22:57:03 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

// CONSTRUCTOR CHAINING: ClapTrap(name) called first
// FragTrap stats: 100 HP, 100 Energy (DOUBLE ScavTrap!), 30 Damage
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;      // Same as ScavTrap
	this->energyPoints = 100;   // DIFFERENT: 100 vs ScavTrap's 50
	this->attackDamage = 30;    // DIFFERENT: 30 vs ScavTrap's 20
	std::cout << "FragTrap " << this->name << " has been created!" << std::endl;
}

// Copy constructor: calls ClapTrap's copy constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->name << " has been created as a copy!" << std::endl;
}

// Assignment: delegates to base class operator=
FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

// Destructor: runs FIRST, then ClapTrap destructor runs automatically
FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " has been destroyed!" << std::endl;
}

// FragTrap-only ability - unique special function
void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->name << " requests a positive high five! ✋" << std::endl;
}

// NOTE: attack() is NOT implemented here - FragTrap uses ClapTrap's version
// This is different from ScavTrap which OVERRIDES attack() with "fiercely"
