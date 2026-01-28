/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:14:41 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/28 16:11:11 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie{
    private:
        std::string name;
    
    public:
        Zombie(std::string name); //constructor recebe o nome
        ~Zombie(); //destructor debuga a msg
        
        void announce(void); //pra imprimir name qqr um pode chamar zombie.announce()
};

//funcoes normais
Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif