/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:22:42 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/30 18:32:53 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	std::cout << "\n========================================" << std::endl;
	std::cout << "     CREATING ROBOTS" << std::endl;
	std::cout << "========================================" << std::endl;
	ClapTrap clap("R2D2");
	ScavTrap scav("T-800");

	std::cout << "\n========================================" << std::endl;
	std::cout << "     TEST 1: COMPARING ATTACKS" << std::endl;
	std::cout << "========================================" << std::endl;
	clap.attack("Enemy");
	scav.attack("Enemy");

	std::cout << "\n========================================" << std::endl;
	std::cout << "     TEST 2: TAKING DAMAGE" << std::endl;
	std::cout << "========================================" << std::endl;
	clap.takeDamage(5);
	scav.takeDamage(30);

	std::cout << "\n========================================" << std::endl;
	std::cout << "     TEST 3: REPAIRING" << std::endl;
	std::cout << "========================================" << std::endl;
	clap.beRepaired(3);
	scav.beRepaired(20);

	std::cout << "\n========================================" << std::endl;
	std::cout << "     TEST 4: COPY CONSTRUCTORS" << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "Creating copies..." << std::endl;
	ClapTrap clapCopy(clap);
	ScavTrap scavCopy(scav);

	std::cout << "\nCopies testing their functions..." << std::endl;
	clapCopy.attack("Copy Target");
	scavCopy.attack("Copy Target");
	scavCopy.guardGate();

	std::cout << "\n========================================" << std::endl;
	std::cout << "     TEST 5: ASSIGNMENT OPERATOR" << std::endl;
	std::cout << "========================================" << std::endl;
	ClapTrap clap2("C3PO");
	std::cout << "Before assignment:" << std::endl;
	clap2.attack("Test");
	std::cout << "\nAssigning R2D2 to C3PO..." << std::endl;
	clap2 = clap;
	std::cout << "After assignment:" << std::endl;
	clap2.attack("Test");

	std::cout << "\n========================================" << std::endl;
	std::cout << "     TEST 6: SCAVTRAP SPECIAL ABILITY" << std::endl;
	std::cout << "========================================" << std::endl;
	scav.guardGate();

	std::cout << "\n========================================" << std::endl;
	std::cout << "     TEST 7: ENERGY STRESS TEST" << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "ScavTrap attacks multiple times..." << std::endl;
	for (int i = 0; i < 5; i++)
		scav.attack("Training Dummy");

	std::cout << "\n========================================" << std::endl;
	std::cout << "     TEST 8: COMPARING DURABILITY" << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "ClapTrap takes fatal damage..." << std::endl;
	clap.takeDamage(20);
	clap.attack("Enemy");

	std::cout << "\nScavTrap takes heavy damage..." << std::endl;
	scav.takeDamage(70);
	scav.attack("Enemy");
	scav.guardGate();

	std::cout << "\n========================================" << std::endl;
	std::cout << "     DESTRUCTORS" << std::endl;
	std::cout << "========================================" << std::endl;
	return 0;
}
