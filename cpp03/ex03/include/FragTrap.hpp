/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:39:13 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/30 19:10:49 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

// VIRTUAL inheritance from ClapTrap - solves Diamond Problem!
// When DiamondTrap inherits from both ScavTrap and FragTrap,
// only ONE ClapTrap subobject exists (not two)
// Stats: 100 HP, 100 Energy, 30 Damage
class FragTrap : virtual public ClapTrap {
public:
	// Orthodox Canonical Form
	FragTrap(std::string name);
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& other);
	~FragTrap();

	// FragTrap unique ability
	void highFivesGuys();
	
	// NOTE: Does NOT override attack() - uses ClapTrap's version
};

#endif
