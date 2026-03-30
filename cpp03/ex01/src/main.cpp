/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:22:42 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/17 17:29:49 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

int main()
{
	// TEST 1: Constructor chaining - ClapTrap first, then ScavTrap
	std::cout << "     \nTEST 1: CONSTRUCTOR/DESTRUCTOR CHAINING" << std::endl;
	{
		ScavTrap isolated("NEXUS");
		std::cout << "--- ScavTrap alive in this scope ---" << std::endl;
	}
	std::cout << "--- Scope ended, check order above ---\n" << std::endl;

	// Creating robots for remaining tests
	std::cout << "     \nCREATING ROBOTS" << std::endl;
	ClapTrap clappy("CLAPPY");
	ScavTrap rocky("ROCKY");

	// TEST 2: Different attack messages - ScavTrap overrides ClapTrap::attack()
	std::cout << "     \nTEST 2: ATTACK MESSAGES (MUST BE DIFFERENT)" << std::endl;
	std::cout << "ClapTrap attack (0 damage):" << std::endl;
	clappy.attack("Enemy");
	std::cout << "\nScavTrap attack (20 damage, different message):" << std::endl;
	rocky.attack("Enemy");

	// TEST 3: Inherited functions - takeDamage and beRepaired from ClapTrap
	std::cout << "     \nTEST 3: INHERITED FUNCTIONS" << std::endl;
	std::cout << "ScavTrap uses ClapTrap's takeDamage() and beRepaired():" << std::endl;
	rocky.takeDamage(40);   // 100 - 40 = 60 HP
	rocky.beRepaired(20);   // 60 + 20 = 80 HP, 49 energy left

	// TEST 4: ScavTrap unique ability - guardGate()
	std::cout << "     \nTEST 4: SPECIAL ABILITY - GUARDGATE" << std::endl;
	rocky.guardGate();

	// TEST 5: ScavTrap stats - 100 HP, 50 Energy, 20 Damage
	std::cout << "     \nTEST 5: SCAVTRAP DURABILITY (100 HP)" << std::endl;
	std::cout << "ClapTrap dies from 15 damage (only has 10 HP):" << std::endl;
	clappy.takeDamage(15);
	clappy.attack("Target");    //fail: dead
	clappy.beRepaired(5);       //fail: dead

	std::cout << "\nScavTrap survives 95 damage (has 100 HP):" << std::endl;
	ScavTrap tank("TANK");
	tank.takeDamage(95);        // 100 - 95 = 5 HP
	tank.attack("Survivor");    // still alive

	// TEST 6: Energy limit - ScavTrap has 50 energy (vs ClapTrap's 10)
	std::cout << "     \nTEST 6: ENERGY EXHAUSTION" << std::endl;
	std::cout << "ROCKY attacks 5 times (has 50 energy, plenty left):" << std::endl;
	for (int i = 0; i < 5; i++)
		rocky.attack("Drain");
	std::cout << "\nROCKY still has energy - can repair:" << std::endl;
	rocky.beRepaired(5);
	std::cout << "(ScavTrap has 50 energy vs ClapTrap's 10 - more durable)" << std::endl;

	// TEST 7: Copy constructor
	std::cout << "     \nTEST 7: COPY CONSTRUCTOR" << std::endl;
	ScavTrap original("PRIME");
	original.takeDamage(30);    // 100 - 30 = 70 HP
	std::cout << "\nCopying PRIME..." << std::endl;
	ScavTrap clone(original);
	std::cout << "\nClone attacks (should have same state as PRIME):" << std::endl;
	clone.attack("CloneTarget");
	clone.guardGate();

	// TEST 8: Copy assignment operator
	std::cout << "     \nTEST 8: ASSIGNMENT OPERATOR" << std::endl;
	ScavTrap alpha("ALPHA");
	ScavTrap beta("BETA");
	alpha.takeDamage(50);   // 100 - 50 = 50 HP
	std::cout << "\nAssigning ALPHA to BETA..." << std::endl;
	beta = alpha;
	std::cout << "\nBETA now has ALPHA's state:" << std::endl;
	beta.attack("PostAssignment");

	// Destructors called automatically
	std::cout << "     \nDESTRUCTORS" << std::endl;
	return 0;
}
