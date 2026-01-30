/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:40:10 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/30 18:55:55 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "\n========================================" << std::endl;
	std::cout << "     CREATING ROBOTS" << std::endl;
	std::cout << "========================================" << std::endl;
	ClapTrap clap("R2D2");
	ScavTrap scav("T-800");
	FragTrap frag("Optimus");

	std::cout << "\n========================================" << std::endl;
	std::cout << "     TEST 1: COMPARING ATTACKS" << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "ClapTrap (AD:0):" << std::endl;
	clap.attack("Target");
	std::cout << "\nScavTrap (AD:20):" << std::endl;
	scav.attack("Target");
	std::cout << "\nFragTrap (AD:30):" << std::endl;
	frag.attack("Target");

	std::cout << "\n========================================" << std::endl;
	std::cout << "     TEST 2: COMPARING STATS" << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "ClapTrap damage test (HP:10):" << std::endl;
	clap.takeDamage(15);
	std::cout << "\nScavTrap damage test (HP:100):" << std::endl;
	scav.takeDamage(50);
	std::cout << "\nFragTrap damage test (HP:100):" << std::endl;
	frag.takeDamage(50);

	std::cout << "\n========================================" << std::endl;
	std::cout << "     TEST 3: REPAIRING" << std::endl;
	std::cout << "========================================" << std::endl;
	scav.beRepaired(20);
	frag.beRepaired(30);

	std::cout << "\n========================================" << std::endl;
	std::cout << "     TEST 4: SPECIAL ABILITIES" << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "ScavTrap special:" << std::endl;
	scav.guardGate();
	std::cout << "\nFragTrap special:" << std::endl;
	frag.highFivesGuys();

	std::cout << "\n========================================" << std::endl;
	std::cout << "     TEST 5: ENERGY COMPARISON" << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "ScavTrap (EP:50) attacks 10 times:" << std::endl;
	for (int i = 0; i < 10; i++)
		scav.attack("Dummy");

	std::cout << "\nFragTrap (EP:100) attacks 10 times:" << std::endl;
	for (int i = 0; i < 10; i++)
		frag.attack("Dummy");

	std::cout << "\n========================================" << std::endl;
	std::cout << "     TEST 6: COPY CONSTRUCTOR" << std::endl;
	std::cout << "========================================" << std::endl;
	FragTrap fragCopy(frag);
	fragCopy.highFivesGuys();

	std::cout << "\n========================================" << std::endl;
	std::cout << "     TEST 7: FINAL ABILITIES" << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "Can ClapTrap still act? (Dead)" << std::endl;
	clap.attack("Test");
	std::cout << "\nScavTrap still functional:" << std::endl;
	scav.guardGate();
	std::cout << "\nFragTrap still functional:" << std::endl;
	frag.highFivesGuys();

	std::cout << "\n========================================" << std::endl;
	std::cout << "     DESTRUCTORS" << std::endl;
	std::cout << "========================================" << std::endl;
	return 0;
}
