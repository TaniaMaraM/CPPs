/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:20:44 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/05 12:54:34 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	int N = 10;
	Zombie* horde = zombieHorde(N, "Horde Zombie");
	for (int i = 0; i < N; i++){
		horde[i].announce();
	}
	delete[] horde;
	return 0;
}
