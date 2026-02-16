/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:59:56 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/30 19:11:06 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

// MULTIPLE INHERITANCE from ScavTrap AND FragTrap
// Diamond inheritance hierarchy:
//          ClapTrap (virtual base)
//         /        \
//    ScavTrap    FragTrap (both inherit virtually)
//         \        /
//        DiamondTrap
//
// Mixed stats: HP=100 (Frag), Energy=50 (Scav), Damage=30 (Frag)
class DiamondTrap : public ScavTrap, public FragTrap {
private:
	std::string name;  // DiamondTrap's own name (ClapTrap::name is "name_clap_name")

public:
	// Orthodox Canonical Form
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap& operator=(const DiamondTrap& other);
	~DiamondTrap();

	// Uses ScavTrap's attack() (with "fiercely") instead of ClapTrap's
	using ScavTrap::attack;
	// DiamondTrap unique ability - shows both names
	void whoAmI();
};

#endif

