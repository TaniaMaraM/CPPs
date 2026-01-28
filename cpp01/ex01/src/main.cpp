/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:20:44 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/28 17:17:07 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    int N = 10;
    Zombie* horde = zombieHorde(N, "Horde Zombie"); //criar horda
    //todos anunciam
    for (int i = 0; i < N; i++){
        horde[i].announce();
    }
    // Apagar TODOS de uma vez (delete[] chama destructor para cada um!)
    delete[] horde;
    return 0;
}