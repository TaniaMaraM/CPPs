/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:29:50 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/05 13:12:39 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {
	std::cout << name << " created" << std::endl;
}
Zombie::~Zombie(){
	std::cout << name << " destroyed" << std::endl;
}
void Zombie::announce(void){
	std::cout << name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
