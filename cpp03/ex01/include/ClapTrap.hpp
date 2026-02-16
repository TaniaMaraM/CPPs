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
	// PROTECTED (not private): allows derived classes to access these
	// Changed from ex00 to enable inheritance
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

	// Actions - inherited by derived classes
	void attack(const std::string& target);  // Can be overridden
	void takeDamage(unsigned int amount);    // Inherited as-is
	void beRepaired(unsigned int amount);    // Inherited as-is
};

#endif
