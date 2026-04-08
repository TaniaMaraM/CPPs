/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 13:53:20 by tmarcos           #+#    #+#             */
/*   Updated: 2026/04/08 15:42:15 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
    
    ScalarConverter::convert(argv[1]);
    
    return 0;
}
