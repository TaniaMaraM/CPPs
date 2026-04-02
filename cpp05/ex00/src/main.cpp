/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 11:51:23 by tmarcos           #+#    #+#             */
/*   Updated: 2026/04/02 17:22:31 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main()
{
	std::cout << "\n===== TEST 1: Constructor =====" << std::endl;
	try
	{
		Bureaucrat tania("tania", 50);
		std::cout << tania << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 2: Grade too high (0) =====" << std::endl;
	try
	{
		Bureaucrat tooHigh("TooHigh", 0);  //throw exception
		std::cout << tooHigh << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 3: Grade too low (151) =====" << std::endl;
	try
	{
		Bureaucrat tooLow("TooLow", 151); //throw exception
		std::cout << tooLow << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 4: Valid limits (1 and 150) =====" << std::endl;
	try
	{
		Bureaucrat best("Best", 1);    // Highest grade (best)
		Bureaucrat worst("Worst", 150); // Lowest grade (worst)
		std::cout << best << std::endl;
		std::cout << worst << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 5: Increment (promote) =====" << std::endl;
	try
	{
		Bureaucrat worker("Worker", 5);
		std::cout << "Before: " << worker << std::endl;
		worker.incrementGrade();  // 5 -> 4
		std::cout << "After:  " << worker << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 6: Decrement (demote) =====" << std::endl;
	try
	{
		Bureaucrat worker("Worker", 5);
		std::cout << "Before: " << worker << std::endl;
		worker.decrementGrade();  // 5 -> 6
		std::cout << "After:  " << worker << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 7: Increment at limit (grade 1) =====" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		std::cout << boss << std::endl;
		boss.incrementGrade();  // 1 -> 0? EXCEPTION!
		std::cout << "This should not appear!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 8: Decrement at limit (grade 150) =====" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 150);
		std::cout << intern << std::endl;
		intern.decrementGrade();  // 150 -> 151? EXCEPTION!
		std::cout << "This should not appear!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 9: Copy constructor =====" << std::endl;
	try
	{
		Bureaucrat original("Original", 42);
		Bureaucrat copy(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy:     " << copy << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 10: Assignment operator =====" << std::endl;
	try
	{
		Bureaucrat a("PersonA", 10);
		Bureaucrat b("PersonB", 100);
		std::cout << "Before:" << std::endl;
		std::cout << "  a: " << a << std::endl;
		std::cout << "  b: " << b << std::endl;
		b = a;  // Only copies grade (name is const)
		std::cout << "After (b = a):" << std::endl;
		std::cout << "  a: " << a << std::endl;
		std::cout << "  b: " << b << std::endl;  // Name stays "PersonB", grade becomes 10
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== END OF TESTS =====" << std::endl;
	return 0;
}
