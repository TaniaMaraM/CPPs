/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:23:00 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/16 23:00:18 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

// CONSTRUCTOR CHAINING: ClapTrap(name) called first
// ScavTrap stats: 100 HP, 50 Energy, 20 Damage
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;     // Override ClapTrap's 10
	this->energyPoints = 50;   // Override ClapTrap's 10
	this->attackDamage = 20;   // Override ClapTrap's 0
	std::cout << "ScavTrap " << this->name << " has been created!" << std::endl;
}

// Copy constructor: calls ClapTrap's copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

// Assignment: delegates to base class operator=
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

// Destructor: runs FIRST, then ClapTrap destructor runs automatically
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " has been destroyed!" << std::endl;
}

// OVERRIDES ClapTrap::attack() - same logic, different message with "fiercely"
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

// ScavTrap-only ability
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode!" << std::endl;
}

/*
Stats: FragTrap tem 100 energy (dobro do ScavTrap) e 
30 damage (mais que ScavTrap)
Behaviour: FragTrap NÃO faz override de attack() - 
vê no output que imprime 'ClapTrap OPTIMUS attacks' em vez de 'FragTrap'
Special ability: highFivesGuys() em vez de guardGate()
Ambos são irmãos - herdam de ClapTrap mas não um do outro. 
Demonstra que herança permite MÚLTIPLAS derivadas com 
comportamentos diferentes da MESMA base."

*/