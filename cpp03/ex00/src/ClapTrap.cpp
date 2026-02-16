/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:15:26 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/16 21:34:14 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

// Initializer list: efficient way to initialize members (C++98 best practice)
// Default values per subject: HP=10, energy=10, damage=0
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << this->name << " has been created!" << std::endl;
}

// Copy constructor: delegates to assignment operator to avoid code duplication
ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment: self-assignment check prevents copying to itself
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other)  // protect against self-assignment (a = a)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;  // return reference to allow chaining (a = b = c)
}

// Destructor: called automatically when object goes out of scope
// Will need to be virtual in ex01/ex02 for proper inheritance cleanup
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " has been destroyed!" << std::endl;
}

// Attack: active action, requires energy AND HP to execute
// const reference parameter avoids string copy (efficient)
void ClapTrap::attack(const std::string& target)
{
	// Guard clauses: validate state before action
	if (this->energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy points left to attack!" << std::endl;
		return;
	}
	if (this->hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " has no hit points left to attack!" << std::endl;
		return;
	}
	this->energyPoints--;  // cost: 1 energy per attack
	std::cout << "ClapTrap " << this->name << " attacks " << target
			  << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

// TakeDamage: passive action, no requirements (can be hit even if dead/exhausted)
// Unsigned parameter: damage is always positive (type-level validation)
void ClapTrap::takeDamage(unsigned int amount)
{
	this->hitPoints -= amount;
	if (this->hitPoints < 0)  // clamp to 0 if goes negative
		this->hitPoints = 0;
	std::cout << "ClapTrap " << this->name << " takes " << amount
			  << " points of damage! Hit points: " << this->hitPoints << std::endl;
}

// BeRepaired: active action, requires energy AND HP (same rules as attack)
// Dead robots cannot self-repair (no resurrection mechanic)
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy points left to repair!" << std::endl;
		return;
	}
	if (this->hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " has no hit points left to repair!" << std::endl;
		return;
	}
	this->energyPoints--;  // cost: 1 energy per repair
	this->hitPoints += amount;
	std::cout << "ClapTrap " << this->name << " repairs itself for " << amount
			  << " points! Hit points: " << this->hitPoints << std::endl;
}
