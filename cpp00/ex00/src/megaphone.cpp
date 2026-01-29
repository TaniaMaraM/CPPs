/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:56:24 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/29 14:22:19 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

/**
 * @brief Main function that converts all arguments to uppercase
 *
 * If no arguments are provided, prints "* LOUD AND UNBEARABLE FEEDBACK NOISE *".
 * Otherwise, converts each character of each argument to uppercase and prints
 * them all concatenated.
 *
 * @param argc Number of command line arguments
 * @param argv Array of command line argument strings
 * @return int Exit status (0 for success)
 */
int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
			std::cout << (char)std::toupper(argv[i][j]);
	}
	std::cout << std::endl;
	return (0);
}
