/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:20:32 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/29 14:23:02 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	//aloca array de N zombies (chama default destructor N vezes)
	Zombie* horde = new Zombie[N];  // ← heap allocation!
	//dar nome a cada zombie
	for(int i = 0; i < N; i++){
		horde[i].setName(name);
	}
	return horde; //retorna um ponteiro pro primeiro zombie horde[0]
}

/*
Zombie* horde = new Zombie[5];
// Equivalente a:
Zombie zombie0();  // chama Zombie::Zombie() ← default!
Zombie zombie1();
Zombie zombie2();
Zombie zombie3();
Zombie zombie4();
C++ chama SEMPRE o default constructor ao alocar arrays! Não há forma de passar parâmetros directamente.
Por isso precisamos de 2 passos:
Criar array (default constructor)
Inicializar cada zombie (setName
*/
