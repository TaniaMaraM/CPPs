/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 10:34:27 by tmarcos           #+#    #+#             */
/*   Updated: 2026/04/08 10:34:29 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);   // copies _signed from base
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

// creates <target>_shrubbery file with ASCII trees
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    checkExecution(executor);   // validates signed + executor grade

    std::ofstream file((_target + "_shrubbery").c_str());
    file << "       *       \n"
         << "      ***      \n"
         << "     *****     \n"
         << "    *******    \n"
         << "   *********   \n"
         << "      ***      \n"
         << "      ***      \n";
    file.close();
}