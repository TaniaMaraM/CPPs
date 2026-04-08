/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 13:53:02 by tmarcos           #+#    #+#             */
/*   Updated: 2026/04/08 15:44:56 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
private:
    // Orthodox Canonical Form - all private (non-instantiable)
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();
    
    // Helper: check if string is a char literal
    static bool isChar(const std::string& str);
    
    // Display functions - print each type directly
    static void printChar(double value);
    static void printInt(double value);
    static void printFloat(double value);
    static void printDouble(double value);
    
public:
    // Main method - converts and displays the literal
    static void convert(const std::string& literal);
};

#endif
