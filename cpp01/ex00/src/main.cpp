/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:28:48 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/05 13:12:19 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int main() {
	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	randomChump("StackZombie");
	delete heapZombie;
	return (0);
}
