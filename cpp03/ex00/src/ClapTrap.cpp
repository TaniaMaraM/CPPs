/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:15:26 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/17 17:16:15 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

// Constructor initializer list
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << this->name << " has been created!" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment
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

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " has been destroyed!" << std::endl;
}

// Attack: active action, requires energy AND HP to execute
void ClapTrap::attack(const std::string& target)
{
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
	this->energyPoints--;  // cost 1 energy per attack
	std::cout << "ClapTrap " << this->name << " attacks " << target
			  << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

// TakeDamage passive action
void ClapTrap::takeDamage(unsigned int amount)
{
	this->hitPoints -= amount;
	if (this->hitPoints < 0)  // clamp to 0 if goes negative
		this->hitPoints = 0;
	std::cout << "ClapTrap " << this->name << " takes " << amount
			  << " points of damage! Hit points: " << this->hitPoints << std::endl;
}

// BeRepaired: active action, requires energy AND HP
// Dead robots cannot self-repair
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
