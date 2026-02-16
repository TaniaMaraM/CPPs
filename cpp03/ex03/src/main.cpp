/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:00:22 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/16 23:02:59 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

int main()
{
	// TEST 1: Constructor chaining with DIAMOND INHERITANCE
	std::cout << "     \nTEST 1: DIAMONDTRAP CONSTRUCTOR CHAINING" << std::endl;
	{
		DiamondTrap isolated("NEXUS");
		std::cout << "--- DiamondTrap alive in this scope ---" << std::endl;
	}
	std::cout << "--- Scope ended, observe destruction order ---\n" << std::endl;
	// Diamond inheritance: ClapTrap→ScavTrap→FragTrap→DiamondTrap (virtual!)

	// Creating all four types for comparison
	std::cout << "     \nCREATING ALL FOUR TYPES" << std::endl;
	ClapTrap clap("R2D2");
	ScavTrap scav("T-800");
	FragTrap frag("OPTIMUS");
	DiamondTrap diamond("MEGATRON");

	// TEST 2: DiamondTrap identity - has TWO names!
	std::cout << "     \nTEST 2: DIAMONDTRAP DUAL IDENTITY" << std::endl;
	std::cout << "DiamondTrap has its own name + ClapTrap name:" << std::endl;
	diamond.whoAmI();   // Shows both: "MEGATRON" and "MEGATRON_clap_name"

	// TEST 3: Attack comparison - DiamondTrap uses ScavTrap's attack
	std::cout << "     \nTEST 3: ATTACK MESSAGES COMPARISON" << std::endl;
	std::cout << "ClapTrap (0 damage, base message):" << std::endl;
	clap.attack("Enemy");
	std::cout << "\nScavTrap (20 damage, overridden with 'fiercely'):" << std::endl;
	scav.attack("Enemy");
	std::cout << "\nFragTrap (30 damage, inherited ClapTrap message):" << std::endl;
	frag.attack("Enemy");
	std::cout << "\nDiamondTrap (30 damage, uses ScavTrap::attack):" << std::endl;
	diamond.attack("Enemy");    // Uses ScavTrap's "fiercely" version

	// TEST 4: DiamondTrap mixed stats (HP from Frag, Energy from Scav, Damage from Frag)
	std::cout << "     \nTEST 4: DIAMONDTRAP MIXED STATS" << std::endl;
	std::cout << "HP: 100 (FragTrap) | Energy: 50 (ScavTrap) | Damage: 30 (FragTrap)" << std::endl;
	diamond.takeDamage(50);     // 100 - 50 = 50 HP
	diamond.beRepaired(20);     // 50 + 20 = 70 HP, 49 energy left

	// TEST 5: DiamondTrap inherits ALL parent abilities
	std::cout << "     \nTEST 5: MULTIPLE INHERITANCE - ALL ABILITIES" << std::endl;
	std::cout << "From ScavTrap:" << std::endl;
	diamond.guardGate();
	std::cout << "\nFrom FragTrap:" << std::endl;
	diamond.highFivesGuys();
	std::cout << "\nOwn ability:" << std::endl;
	diamond.whoAmI();

	// TEST 6: Comparing stats of all types
	std::cout << "     \nTEST 6: STATS COMPARISON TABLE" << std::endl;
	std::cout << "ClapTrap:    HP=10  | EP=10  | AD=0  | Base class" << std::endl;
	std::cout << "ScavTrap:    HP=100 | EP=50  | AD=20 | Inherits ClapTrap" << std::endl;
	std::cout << "FragTrap:    HP=100 | EP=100 | AD=30 | Inherits ClapTrap" << std::endl;
	std::cout << "DiamondTrap: HP=100 | EP=50  | AD=30 | Mix of Scav + Frag!" << std::endl;

	// TEST 7: Energy test - DiamondTrap has ScavTrap's 50 energy
	std::cout << "     \nTEST 7: ENERGY CAPACITY" << std::endl;
	std::cout << "DiamondTrap has 50 energy (from ScavTrap), 5 attacks:" << std::endl;
	for (int i = 0; i < 5; i++)
		diamond.attack("Drain");

	// TEST 8: Copy constructor
	std::cout << "     \nTEST 8: COPY CONSTRUCTOR" << std::endl;
	std::cout << "Creating DiamondTrap copy..." << std::endl;
	DiamondTrap clone(diamond);
	std::cout << "\nClone identity:" << std::endl;
	clone.whoAmI();
	std::cout << "\nClone attacks:" << std::endl;
	clone.attack("CloneTarget");

	// TEST 9: Assignment operator
	std::cout << "     \nTEST 9: ASSIGNMENT OPERATOR" << std::endl;
	DiamondTrap alpha("ALPHA");
	DiamondTrap beta("BETA");
	std::cout << "\nBETA before assignment:" << std::endl;
	beta.whoAmI();
	std::cout << "\nAssigning ALPHA to BETA..." << std::endl;
	beta = alpha;
	std::cout << "\nBETA after assignment:" << std::endl;
	beta.whoAmI();

	// Destructors - observe diamond destruction order
	std::cout << "     \nDESTRUCTORS" << std::endl;
	return 0;
}
