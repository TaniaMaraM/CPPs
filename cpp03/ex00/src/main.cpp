/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:15:23 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/30 18:15:04 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::cout << "     \nCREATING CLAPTRAPS" << std::endl;
	ClapTrap robot1("R2D2");
	ClapTrap robot2("C3PO");
	ClapTrap robot3("BB8");

	std::cout << "     \nTEST 1: ATTACK & TAKE DAMAGE" << std::endl;
	robot1.attack("C3PO");
	robot2.takeDamage(0);
	robot2.attack("R2D2");
	robot1.takeDamage(0);

	std::cout << "     \nTEST 2: TAKING REAL DAMAGE" << std::endl;
	robot1.takeDamage(5);
	robot2.takeDamage(8);
	robot3.takeDamage(3);

	std::cout << "     \nTEST 3: REPAIRING" << std::endl;
	robot1.beRepaired(3);
	robot2.beRepaired(5);
	robot3.beRepaired(2);

	std::cout << "     \nTEST 4: ENERGY EXHAUSTION" << std::endl;
	std::cout << "R2D2 will attack until energy is depleted..." << std::endl;
	for (int i = 0; i < 9; i++)
		robot1.attack("Training Dummy");

	std::cout << "\n--- Energy should be exhausted now ---" << std::endl;
	robot1.attack("Enemy");
	robot1.beRepaired(1);

	std::cout << "     \nTEST 5: HIT POINTS EXHAUSTION" << std::endl;
	std::cout << "C3PO takes massive damage..." << std::endl;
	robot2.takeDamage(15);
	std::cout << "\n--- HP should be 0 now ---" << std::endl;
	robot2.attack("Enemy");
	robot2.beRepaired(5);

	std::cout << "     \nTEST 6: LAST ROBOT STANDING" << std::endl;
	robot3.attack("Victory Target");
	robot3.beRepaired(10);

	std::cout << "     \nDESTRUCTORS" << std::endl;
	return 0;
}
