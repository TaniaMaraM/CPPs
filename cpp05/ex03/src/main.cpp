/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 22:03:44 by tmarcos           #+#    #+#             */
/*   Updated: 2026/04/08 11:09:55 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/intern.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(0));
    Intern someIntern;
    Bureaucrat god("God", 1);
    AForm *form;

    std::cout << "\n===== TEST 1: shrubbery creation =====\n";
    form = someIntern.makeForm("shrubbery creation", "garden");
    if (form)
    {
        god.signForm(*form);
        god.executeForm(*form);
        delete form;
    }

    std::cout << "\n===== TEST 2: robotomy request =====\n";
    form = someIntern.makeForm("robotomy request", "Bender");
    if (form)
    {
        god.signForm(*form);
        god.executeForm(*form);
        delete form;
    }

    std::cout << "\n===== TEST 3: presidential pardon =====\n";
    form = someIntern.makeForm("presidential pardon", "Arthur Dent");
    if (form)
    {
        god.signForm(*form);
        god.executeForm(*form);
        delete form;
    }

    std::cout << "\n===== TEST 4: unknown form =====\n";
    form = someIntern.makeForm("coffee request", "Marvin");
    if (!form)
        std::cout << "No form returned — handled correctly\n";

    
    std::cout << "\n===== TEST 5: Intern OCF =====\n";
    Intern intern2(someIntern);      // copy ctor
    Intern intern3;
    intern3 = someIntern;            // assignment
    form = intern2.makeForm("presidential pardon", "Trillian");
     if (form)
        {
            god.signForm(*form);
            god.executeForm(*form);
            delete form;
        }       
          
    std::cout << "\n===== END OF TESTS =====\n";
    return 0;
}