/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:29:50 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/29 14:23:23 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//constructor guarda o nome
Zombie::Zombie(std::string name) : name(name) {
	std::cout << name << " created" << std::endl;
}
//destructor debug
Zombie::~Zombie(){
	std::cout << name << " destroyed" << std::endl;
}
//announce
void Zombie::announce(void){
	std::cout << name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

/*
Breakdown:
Zombie::Zombie → método da classe Zombie
std::string name → parâmetro (nome recebido)
: name(name) → initialization list (inicializa membro name com parâmetro name)
17|     std::cout << name << " created" << std::endl;
std::cout → output (como printf)
<< → operador de inserção (concatena)
std::endl → newline + flush buffer (como \n)
*/
