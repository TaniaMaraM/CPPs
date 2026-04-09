/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 10:55:22 by tmarcos           #+#    #+#             */
/*   Updated: 2026/04/09 11:47:58 by tmarcos          ###   ########.fr       */
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

// lookup table maps form names to creator functions
AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    // function pointer type: takes a target string, returns a new AForm*
    typedef AForm *(*Creator)(const std::string &);

    // each entry pairs a form name with its creator function
    struct Entry {
        std::string name;
        Creator     creator;
    };

    // lookup table — just data
    Entry table[] = {
        {"shrubbery creation",  createShrubbery},
        {"robotomy request",    createRobotomy},
        {"presidential pardon", createPardon}
    };

    // search for matching name, call the associated creator
    for (int i = 0; i < 3; i++)
    {
        if (table[i].name == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return table[i].creator(target); // allocates on heap — caller must delete
        }
    }

    // no match found
    std::cout << "Intern: unknown form name '" << formName << "'" << std::endl;
    return NULL;
}

/*
makeForm() — factory function that creates AForm objects by name.

How it works:
  1. Defines a function pointer type (Creator) that points to functions
     returning AForm* given a target string.
  2. Builds a lookup table (array of structs) pairing each form name
     with its creator function — no if/else chain.
  3. Loops through the table comparing formName to each entry.
  4. On match: calls the creator, which allocates the form on the heap
     and returns the pointer. Caller is responsible for delete.
  5. No match: prints an error and returns NULL.

Why this design:
  Adding a new form only requires adding one line to the table —
  the loop logic never changes.
*/