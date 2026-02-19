/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:15:23 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/17 17:21:47 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int main()
{
	std::cout << "     \nCREATING CLAPTRAPS" << std::endl;
	// Stack allocation: constructor called, destructors automatic at end of scope
	ClapTrap robot1("R2D2");
	ClapTrap robot2("C3PO");
	ClapTrap robot3("BB8");

	// TEST 1: Basic functionality - prove actions work when conditions are met
	std::cout << "     \nTEST 1: ATTACK & TAKE DAMAGE" << std::endl;
	robot1.attack("C3PO");
	robot2.takeDamage(0);
	robot2.attack("R2D2");
	robot1.takeDamage(0);

	// TEST 2: HP tracking - different damage amounts to verify state changes
	std::cout << "     \nTEST 2: TAKING REAL DAMAGE" << std::endl;
	robot1.takeDamage(5);  // 10 - 5 = 5 HP
	robot2.takeDamage(8);  // 10 - 8 = 2 HP
	robot3.takeDamage(3);  // 10 - 3 = 7 HP

	// TEST 3: Repair mechanic - costs energy, increases HP
	std::cout << "     \nTEST 3: REPAIRING" << std::endl;
	robot1.beRepaired(3);  // 5+3=8 HP
	robot2.beRepaired(5);  // 2+5=7 HP
	robot3.beRepaired(2);  // 7+2=9 HP

	// TEST 4: Energy exhaustion - CRITICAL TEST for guard clauses
	std::cout << "     \nTEST 4: ENERGY EXHAUSTION" << std::endl;
	std::cout << "R2D2 will attack until energy is depleted..." << std::endl;
	for (int i = 0; i < 9; i++)  // robot1 has 8 energy: 8 succeed, 1 fails
		robot1.attack("Training Dummy");

	std::cout << "\n--- Energy should be exhausted now ---" << std::endl;
	robot1.attack("Enemy");     // MUST fail= no energy left
	robot1.beRepaired(1);       // MUST fail= no energy left

	// TEST 5: Death state - robot with 0 HP cannot perform actions
	std::cout << "     \nTEST 5: HIT POINTS EXHAUSTION" << std::endl;
	std::cout << "C3PO takes massive damage..." << std::endl;
	robot2.takeDamage(15);      // 7 - 15 = -8, clamped to 0
	std::cout << "\n--- HP should be 0 now ---" << std::endl;
	robot2.attack("Enemy");
	robot2.beRepaired(5);

	// TEST 6: Sanity check - healthy robot still functional (guards don't break valid robots)
	std::cout << "     \nTEST 6: LAST ROBOT STANDING" << std::endl;
	robot3.attack("Victory Target");
	robot3.beRepaired(10);

	// Destructors called
	std::cout << "     \nDESTRUCTORS" << std::endl;
	return 0;
}
