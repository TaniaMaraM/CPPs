/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:40:10 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/16 22:57:31 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"
#include "../include/ScavTrap.hpp"

int main()
{
	// TEST 1: Constructor/Destructor chaining - FragTrap inherits from ClapTrap
	std::cout << "     \nTEST 1: FRAGTRAP CONSTRUCTOR/DESTRUCTOR CHAINING" << std::endl;
	{
		FragTrap isolated("NEXUS");
		std::cout << "--- FragTrap alive in this scope ---" << std::endl;
	}
	std::cout << "--- Scope ended, check order above ---\n" << std::endl;
	// Expected: ClapTrap→FragTrap construction, FragTrap→ClapTrap destruction

	// Creating all three types for comparison tests
	std::cout << "     \nCREATING ALL THREE TYPES" << std::endl;
	ClapTrap clappy("CLAPPY");
	ScavTrap rocky("ROCKY");
	FragTrap optimus("OPTIMUS");

	// TEST 2: Attack messages - KEY: FragTrap does NOT override attack()
	std::cout << "     \nTEST 2: ATTACK MESSAGES COMPARISON" << std::endl;
	std::cout << "ClapTrap (0 damage, base message):" << std::endl;
	clappy.attack("Enemy");
	std::cout << "\nScavTrap (20 damage, OVERRIDDEN with 'fiercely'):" << std::endl;
	rocky.attack("Enemy");
	std::cout << "\nFragTrap (30 damage, INHERITED - uses ClapTrap message):" << std::endl;
	optimus.attack("Enemy");    // Prints "ClapTrap OPTIMUS attacks..." NOT "FragTrap"!

	// TEST 3: Inherited functions - all three use ClapTrap's takeDamage/beRepaired
	std::cout << "     \nTEST 3: INHERITED FUNCTIONS" << std::endl;
	std::cout << "All use ClapTrap's takeDamage() and beRepaired():" << std::endl;
	rocky.takeDamage(30);       // 100 - 30 = 70 HP
	optimus.takeDamage(40);     // 100 - 40 = 60 HP
	rocky.beRepaired(10);       // 70 + 10 = 80 HP
	optimus.beRepaired(20);     // 60 + 20 = 80 HP

	// TEST 4: Durability comparison - ClapTrap 10 HP vs ScavTrap/FragTrap 100 HP
	std::cout << "     \nTEST 4: DURABILITY TEST (100 HP)" << std::endl;
	std::cout << "ClapTrap dies from 15 damage (only has 10 HP):" << std::endl;
	clappy.takeDamage(15);
	clappy.attack("Target");    // MUST fail: dead
	clappy.beRepaired(5);       // MUST fail: dead
	
	std::cout << "\nScavTrap and FragTrap survive 95 damage (have 100 HP):" << std::endl;
	ScavTrap tank("TANK");
	FragTrap fortress("FORTRESS");
	tank.takeDamage(95);        // 100 - 95 = 5 HP
	fortress.takeDamage(95);    // 100 - 95 = 5 HP
	tank.attack("Survivor");
	fortress.attack("Survivor");

	// TEST 5: Special abilities - unique to each derived class
	std::cout << "     \nTEST 5: UNIQUE SPECIAL ABILITIES" << std::endl;
	std::cout << "ScavTrap only:" << std::endl;
	rocky.guardGate();
	std::cout << "\nFragTrap only:" << std::endl;
	optimus.highFivesGuys();

	// TEST 6: Energy comparison - KEY DIFFERENCE between ScavTrap and FragTrap
	std::cout << "     \nTEST 6: ENERGY CAPACITY (KEY DIFFERENCE)" << std::endl;
	std::cout << "ScavTrap has 50 energy (5 attacks shown):" << std::endl;
	for (int i = 0; i < 5; i++)
		rocky.attack("Drain");
	
	std::cout << "\nFragTrap has 100 energy (5 attacks shown, plenty left!):" << std::endl;
	for (int i = 0; i < 5; i++)
		optimus.attack("Drain");
	std::cout << "(FragTrap has DOUBLE the energy capacity of ScavTrap!)" << std::endl;

	// TEST 7: Copy constructor
	std::cout << "     \nTEST 7: COPY CONSTRUCTOR" << std::endl;
	std::cout << "Creating FragTrap copy..." << std::endl;
	FragTrap clone(optimus);
	std::cout << "\nClone performs actions:" << std::endl;
	clone.attack("CloneTarget");
	clone.highFivesGuys();

	// TEST 8: Copy assignment operator
	std::cout << "     \nTEST 8: ASSIGNMENT OPERATOR" << std::endl;
	FragTrap alpha("ALPHA");
	FragTrap beta("BETA");
	alpha.takeDamage(40);   // 100 - 40 = 60 HP
	std::cout << "\nAssigning ALPHA to BETA..." << std::endl;
	beta = alpha;
	std::cout << "\nBETA now has ALPHA's state:" << std::endl;
	beta.attack("PostAssignment");

	// Destructors called automatically - reverse order of creation
	std::cout << "     \nDESTRUCTORS" << std::endl;
	return 0;
}
