/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:14:41 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/05 12:50:48 by tmarcos          ###   ########.fr       */
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
        Zombie(std::string name);
        ~Zombie();

        void announce(void);

};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif
