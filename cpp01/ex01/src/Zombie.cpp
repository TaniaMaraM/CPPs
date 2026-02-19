/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:29:50 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/05 12:55:42 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){
	std::cout << "Zombie created" << std::endl;
}
Zombie::Zombie(std::string name) : name(name) {
	std::cout << name << " created" << std::endl;
}
Zombie::~Zombie(){
	std::cout << name << " destroyed" << std::endl;
}
void Zombie::setName(std::string name){
	this->name = name;
}
void Zombie::announce(void){
	std::cout << name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
