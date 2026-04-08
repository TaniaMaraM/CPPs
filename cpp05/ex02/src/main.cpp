/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 22:03:44 by tmarcos           #+#    #+#             */
/*   Updated: 2026/04/08 10:44:54 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(0));

    std::cout << "\n===== TEST 1: ShrubberyCreationForm =====\n";
    try
    {
        ShrubberyCreationForm f("garden");
        Bureaucrat worker("Worker", 137);
        worker.signForm(f);
        worker.executeForm(f);   // creates garden_shrubbery file
    }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }

    std::cout << "\n===== TEST 2: RobotomyRequestForm =====\n";
    try
    {
        RobotomyRequestForm f("Bender");
        Bureaucrat surgeon("Surgeon", 45);
        surgeon.signForm(f);
        surgeon.executeForm(f);  // 50% success
        surgeon.executeForm(f);  // run twice to see randomness
    }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }

    std::cout << "\n===== TEST 3: PresidentialPardonForm =====\n";
    try
    {
        PresidentialPardonForm f("Arthur Dent");
        Bureaucrat president("President", 5);
        president.signForm(f);
        president.executeForm(f);
    }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }

    std::cout << "\n===== TEST 4: Execute without signing =====\n";
    try
    {
        PresidentialPardonForm f("Arthur Dent");
        Bureaucrat president("President", 5);
        president.executeForm(f);  // not signed — should fail
    }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }

    std::cout << "\n===== TEST 5: Grade too low to execute =====\n";
    try
    {
        ShrubberyCreationForm f("park");
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);
        boss.signForm(f);          // boss can sign (1 <= 145)
        intern.executeForm(f);     // intern can't execute (150 > 137)
    }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }

    std::cout << "\n===== TEST 6: Grade too low to SIGN =====\n";
    try
    {
        ShrubberyCreationForm f("forest");
        Bureaucrat lowrank("LowRank", 150);  // needs <= 145 to sign
        lowrank.signForm(f);                 // fails — 150 > 145
        lowrank.executeForm(f);              // never reached
    }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }

    std::cout << "\n===== TEST 7: Polymorphism via AForm pointer =====\n";
    try
    {
        AForm *forms[3];
        forms[0] = new ShrubberyCreationForm("poly_garden");
        forms[1] = new RobotomyRequestForm("Marvin");
        forms[2] = new PresidentialPardonForm("Ford Prefect");

        Bureaucrat god("God", 1);  // grade 1 — can do everything
        for (int i = 0; i < 3; i++)
        {
            god.signForm(*forms[i]);
            god.executeForm(*forms[i]);
        }
        for (int i = 0; i < 3; i++)
            delete forms[i];       // virtual destructor — correct cleanup
    }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }

    std::cout << "\n===== TEST 8: Copy constructor + execute on copy =====\n";
    try
    {
        RobotomyRequestForm original("Zoidberg");
        RobotomyRequestForm copy(original);
        Bureaucrat surgeon("Surgeon", 45);
        surgeon.signForm(original);
        copy = original;                  // _signed copies to copy
        surgeon.executeForm(copy);        // copy is now signed — should work
    }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }
    std::cout << "\n===== END OF TESTS =====\n";
    return 0;
}