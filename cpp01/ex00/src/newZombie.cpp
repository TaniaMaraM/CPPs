/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:30:13 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/29 14:23:13 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//cria heap persiste
Zombie* newZombie(std::string name) {
	return new Zombie(name); //new = malloc + constructor
}

/*
O que new faz:
Aloca memória no heap (como malloc)
Chama constructor Zombie(name)
Retorna ponteiro
em C seria:
Zombie* newZombie(char *name) {
	Zombie *z = malloc(sizeof(Zombie));
	init_zombie(z, name);  // manual!
	return z;
}
*/
