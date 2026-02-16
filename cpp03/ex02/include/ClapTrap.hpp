/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:15:29 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/30 18:26:51 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
protected:
	// PROTECTED: allows derived classes (ScavTrap, FragTrap) to access
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;

public:
	// Orthodox Canonical Form
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap &other);
	~ClapTrap();  // Should be virtual for polymorphic deletion

	// Actions - can be inherited or overridden by derived classes
	void attack(const std::string& target);  // FragTrap inherits, ScavTrap overrides
	void takeDamage(unsigned int amount);    // Both inherit as-is
	void beRepaired(unsigned int amount);    // Both inherit as-is
};

#endif
