/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:39:13 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/30 18:40:23 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

// PUBLIC inheritance from ClapTrap (sibling of ScavTrap)
// Stats: 100 HP, 100 Energy, 30 Damage
// KEY: Does NOT override attack() - uses ClapTrap's message
class FragTrap : public ClapTrap {
public:
	// Orthodox Canonical Form
	FragTrap(std::string name);
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& other);
	~FragTrap();

	// FragTrap unique ability
	void highFivesGuys();
	
	// NOTE: attack() NOT declared here - inherited from ClapTrap without override
};

#endif
