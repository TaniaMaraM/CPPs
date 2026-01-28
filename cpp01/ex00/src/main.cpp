/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:28:48 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/28 15:59:20 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    //HEAP persiste ate delete
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    //stack - morre apos funcao
    randomChump("StackZombie");
    delete heapZombie;
    return (0);
}