/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:29:50 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/28 17:10:12 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//default constructor - nome vazio agora
Zombie::Zombie(){
    std::cout << "Zombie created (unnamed)" << std::endl;
}
//constructor com nome
Zombie::Zombie(std::string name) : name(name) {
    std::cout << name << " created" << std::endl;
}
//destructor
Zombie::~Zombie(){
    std::cout << name << " destroyed" << std::endl;
}
//setter para dar nome depois de criar
void Zombie::setName(std::string name){
    this->name = name; //ponteiro para o objeto atual
}
void Zombie::announce(void){
    std::cout << name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}