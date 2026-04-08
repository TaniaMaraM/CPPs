/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 13:53:13 by tmarcos           #+#    #+#             */
/*   Updated: 2026/04/08 15:45:40 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>   // atof
#include <limits>    // numeric_limits
#include <cmath>     // isnan, isinf
#include <iomanip>   // setprecision
#include <cctype>    // isdigit, isprint

//constructor
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

//helper
bool ScalarConverter::isChar(const std::string& str)
{
    // Single non-digit character (without quotes)
    return (str.length() == 1 && !std::isdigit(str[0]));
}

// display functions
void ScalarConverter::printChar(double value)
{
    std::cout << "char: ";
    
    // Check if conversion is impossible
    if (std::isnan(value) || std::isinf(value))
        std::cout << "impossible";
    else if (value < 0 || value > 127)  // outside ASCII range
        std::cout << "impossible";
    else if (value < 32 || value == 127)  // non-displayable
        std::cout << "Non displayable";
    else
        std::cout << "'" << static_cast<char>(value) << "'";
    
    std::cout << std::endl;
}

void ScalarConverter::printInt(double value)
{
    std::cout << "int: ";
    
    // Check if conversion is impossible
    if (std::isnan(value) || std::isinf(value))
        std::cout << "impossible";
    else if (value < std::numeric_limits<int>::min() || 
             value > std::numeric_limits<int>::max())
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(value);
    
    std::cout << std::endl;
}

void ScalarConverter::printFloat(double value)
{
    float f = static_cast<float>(value);
    
    std::cout << "float: ";
    
    // Check for special values
    if (std::isnan(f))
        std::cout << "nanf";
    else if (std::isinf(f))
        std::cout << (f > 0 ? "+inff" : "-inff");
    else
        std::cout << std::fixed << std::setprecision(1) << f << "f";
    
    std::cout << std::endl;
}

void ScalarConverter::printDouble(double value)
{
    std::cout << "double: ";
    
    // Check for special values
    if (std::isnan(value))
        std::cout << "nan";
    else if (std::isinf(value))
        std::cout << (value > 0 ? "+inf" : "-inf");
    else
        std::cout << std::fixed << std::setprecision(1) << value;
    
    std::cout << std::endl;
}

//converter
void ScalarConverter::convert(const std::string& literal)
{
    double value;
    
    // Special case: single char
    if (isChar(literal))
    {
        value = static_cast<double>(literal[0]);  // get the char
    }
    // All other cases: parse as double using atof
    else
    {
        value = std::atof(literal.c_str());
    }
    
    // Print all four types
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}
