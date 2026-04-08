/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 10:55:22 by tmarcos           #+#    #+#             */
/*   Updated: 2026/04/08 10:58:17 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/intern.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

//ocf
Intern::Intern() {}
Intern::Intern(const Intern &other) { (void)other; }
Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }
Intern::~Intern() {}

// Factory helpers (file-scope, not part of the class)
static AForm *createShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

static AForm *createRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

static AForm *createPardon(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

//makeForm
// lookup table maps form names to creator functions
AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    typedef AForm *(*Creator)(const std::string &);

    struct Entry {
        std::string name;
        Creator     creator;
    };

    Entry table[] = {
        {"shrubbery creation",  createShrubbery},
        {"robotomy request",    createRobotomy},
        {"presidential pardon", createPardon}
    };

    for (int i = 0; i < 3; i++)
    {
        if (table[i].name == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return table[i].creator(target);
        }
    }

    std::cout << "Intern: unknown form name '" << formName << "'" << std::endl;
    return NULL;
}