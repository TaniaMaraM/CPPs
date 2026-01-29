/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:14:41 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/29 14:22:48 by tmarcos          ###   ########.fr       */
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
		Zombie(); //construtor
		Zombie(std::string name); // parametrized constructor? pq?
		~Zombie();

		void setName(std::string name); //setter
		void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif
