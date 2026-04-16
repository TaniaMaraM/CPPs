/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 13:53:13 by tmarcos           #+#    #+#             */
/*   Updated: 2026/04/16 19:08:13 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>   // strtod
#include <limits>    // numeric_limits
#include <cmath>     // isnan, isinf
#include <iomanip>   // setprecision, fixed
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

bool ScalarConverter::isChar(const std::string& str)
{
    // Single non-digit printable character
    // e.g. 'a', '+', '-', '!'
    return (str.length() == 1 && !std::isdigit(str[0]));
}
// Validation + parsing
bool ScalarConverter::isValidInput(const std::string& str, double& outValue)
{
    char* endptr;
    // strtod tries to parse as double
    // It also handles: nan, +inf, -inf, nanf, +inff, -inff
    outValue = std::strtod(str.c_str(), &endptr);

    // Skip optional 'f' suffix (float literals like 42.0f)
    if (*endptr == 'f')
        endptr++;

    // Valid if:
    // - endptr != str.c_str() → at least one character was parsed
    // - *endptr == '\0'       → the whole string was consumed
    return (endptr != str.c_str() && *endptr == '\0');
}
//display functions
void ScalarConverter::printChar(double value)
{
    std::cout << "char: ";

    if (std::isnan(value) || std::isinf(value))
        std::cout << "impossible";
    else if (value < 0 || value > 127) // outside ASCII range
        std::cout << "impossible";
    else if (value < 32 || value == 127) // non-printable control chars
        std::cout << "Non displayable";
    else
        std::cout << "'" << static_cast<char>(value) << "'";

    std::cout << std::endl;
}

void ScalarConverter::printInt(double value)
{
    std::cout << "int: ";

    if (std::isnan(value) || std::isinf(value))
        std::cout << "impossible";
    else if (value < std::numeric_limits<int>::min() ||
             value > std::numeric_limits<int>::max())  // overflow
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(value);

    std::cout << std::endl;
}

void ScalarConverter::printFloat(double value)
{
    float f = static_cast<float>(value);

    std::cout << "float: ";

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

    if (std::isnan(value))
        std::cout << "nan";
    else if (std::isinf(value))
        std::cout << (value > 0 ? "+inf" : "-inf");
    else
        std::cout << std::fixed << std::setprecision(1) << value;

    std::cout << std::endl;
}

//main converter

void ScalarConverter::convert(const std::string& literal)
{
    double value;

    // Case 1: single non-digit character → treat as char
    if (isChar(literal))
    {
        value = static_cast<double>(literal[0]);
        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
        return;
    }

    // Case 2: try to parse as number
    // strtod handles: integers, floats, doubles, nan, inf (with/without 'f')
    if (!isValidInput(literal, value))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    // Case 3: valid number → display all types
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}
