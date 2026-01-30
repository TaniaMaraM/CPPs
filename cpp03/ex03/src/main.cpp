/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:00:22 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/30 19:11:08 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	std::cout << "\n========================================" << std::endl;
	std::cout << "     CREATING ROBOTS" << std::endl;
	std::cout << "========================================" << std::endl;
	ClapTrap clap("R2D2");
	std::cout << std::endl;
	ScavTrap scav("T-800");
	std::cout << std::endl;
	FragTrap frag("Optimus");
	std::cout << std::endl;
	DiamondTrap diamond("Megatron");

	std::cout << "\n========================================" << std::endl;
	std::cout << "     TEST 1: DIAMONDTRAP IDENTITY" << std::endl;
	std::cout << "========================================" << std::endl;
	diamond.whoAmI();

	std::cout << "\n========================================" << std::endl;
	std::cout << "     TEST 2: COMPARING ATTACKS" << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "ClapTrap (AD:0):" << std::endl;
	clap.attack("Target");
	std::cout << "\nScavTrap (AD:20):" << std::endl;
	scav.attack("Target");
	std::cout << "\nFragTrap (AD:30):" << std::endl;
	frag.attack("Target");
	std::cout << "\nDiamondTrap (AD:30, uses ScavTrap attack):" << std::endl;
	diamond.attack("Target");

	std::cout << "\n========================================" << std::endl;
	std::cout << "     TEST 3: DIAMONDTRAP STATS" << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "HP: 100 (FragTrap), EP: 50 (ScavTrap), AD: 30 (FragTrap)" << std::endl;
	diamond.takeDamage(50);
	diamond.beRepaired(20);

	std::cout << "\n========================================" << std::endl;
	std::cout << "     TEST 4: INHERITED ABILITIES" << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "ScavTrap ability:" << std::endl;
	diamond.guardGate();
	std::cout << "\nFragTrap ability:" << std::endl;
	diamond.highFivesGuys();
	std::cout << "\nDiamondTrap ability:" << std::endl;
	diamond.whoAmI();

	std::cout << "\n========================================" << std::endl;
	std::cout << "     TEST 5: ENERGY TEST" << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "DiamondTrap has 50 EP (from ScavTrap)" << std::endl;
	for (int i = 0; i < 10; i++)
		diamond.attack("Dummy");

	std::cout << "\n========================================" << std::endl;
	std::cout << "     TEST 6: COPY CONSTRUCTOR" << std::endl;
	std::cout << "========================================" << std::endl;
	DiamondTrap diamondCopy(diamond);
	diamondCopy.whoAmI();
	diamondCopy.attack("Copy Target");

	std::cout << "\n========================================" << std::endl;
	std::cout << "     TEST 7: COMPARING ALL TYPES" << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "ClapTrap: HP=10, EP=10, AD=0" << std::endl;
	std::cout << "ScavTrap: HP=100, EP=50, AD=20" << std::endl;
	std::cout << "FragTrap: HP=100, EP=100, AD=30" << std::endl;
	std::cout << "DiamondTrap: HP=100(Frag), EP=50(Scav), AD=30(Frag)" << std::endl;

	std::cout << "\n========================================" << std::endl;
	std::cout << "     DESTRUCTORS" << std::endl;
	std::cout << "========================================" << std::endl;
	return 0;
}

