/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 18:35:44 by tmarcos           #+#    #+#             */
/*   Updated: 2026/04/03 18:58:29 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

int main()
{
    std::cout << "\n===== TEST 1: construction =====\n";
    try
    {
        Form f("Tax Form", 50, 25);
        std::cout << f << std::endl;
    }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }

    std::cout << "\n===== TEST 2: Grade too high (0) =====\n";
    try
    {
        Form f("Bad Form", 0, 25);
        std::cout << f << std::endl;
    }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }

    std::cout << "\n===== TEST 3: Grade too low (151) =====\n";
    try
    {
        Form f("Bad Form", 50, 151);
        std::cout << f << std::endl;
    }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }

    std::cout << "\n===== TEST 4: Bureaucrat signs successfully =====\n";
    try
    {
        Form f("Tax Form", 50, 25);
        Bureaucrat boss("Boss", 30);     // grade 30 <= 50, can sign
        std::cout << f << std::endl;
        boss.signForm(f);
        std::cout << f << std::endl;     // signed: yes
    }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }

    std::cout << "\n===== TEST 5: Bureaucrat grade too low to sign =====\n";
    try
    {
        Form f("Tax Form", 50, 25);
        Bureaucrat intern("Intern", 100); // grade 100 > 50, cannot sign
        intern.signForm(f);
    }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }

    std::cout << "\n===== TEST 6: Getters =====\n";
    try
    {
        Form f("Budget Form", 75, 40);
        std::cout << "Name: "      << f.getName() << std::endl;
        std::cout << "GradeSign: " << f.getGradeSign() << std::endl;
        std::cout << "GradeExec: " << f.getGradeExecute() << std::endl;
        std::cout << "Signed: "    << (f.getSigned() ? "yes" : "no") << std::endl;
    }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }

    std::cout << "\n===== TEST 7: Copy constructor =====\n";
    try
    {
        Form original("Original Form", 50, 25);
        Form copy(original);
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy:     " << copy << std::endl;
    }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }

    std::cout << "\n===== TEST 8: Assignment operator (only _signed copies) =====\n";
    try
    {
        Form a("Form A", 50, 25);
        Form b("Form B", 100, 80);
        Bureaucrat boss("Boss", 1);
        boss.signForm(a);
        b = a;
        std::cout << "a: " << a << std::endl;
        std::cout << "b: " << b << std::endl;  // name/grades stay b's, signed copies from a
    }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }

    std::cout << "\n===== END OF TESTS =====\n";
    return 0;
}
