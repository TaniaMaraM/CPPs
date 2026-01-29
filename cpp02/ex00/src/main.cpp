/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 21:04:48 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/29 15:05:29 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}


/*
Chama a.getRawBits()
Imprime "getRawBits member function called"
Retorna a.fixedPointValue que é 0
std::cout imprime 0
std::endl adiciona quebra de linha

main() termina
Destructors são chamados na ORDEM INVERSA de criação!
Objetos criados: a → b → c
Destruídos: c → b → a (último criado, primeiro destruído - LIFO)
*/
