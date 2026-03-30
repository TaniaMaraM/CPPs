/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:23:00 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/17 17:43:11 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

// virtual inheritance: when used in DiamondTrap, ClapTrap constructor
// ScavTrap stats: 100 HP, 50 Energy, 20 Damage
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " has been created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " has been destroyed!" << std::endl;
}

// overrides ClapTrap::attack() - same logic, different message
// DiamondTrap uses this version via "using ScavTrap::attack;"
void ScavTrap::attack(const std::string& target)
{
	if (this->energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->name << " has no energy points left to attack!" << std::endl;
		return;
	}
	if (this->hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->name << " has no hit points left to attack!" << std::endl;
		return;
	}
	this->energyPoints--;
	std::cout << "ScavTrap " << this->name << " attacks " << target
			  << " fiercely, causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode!" << std::endl;
}

