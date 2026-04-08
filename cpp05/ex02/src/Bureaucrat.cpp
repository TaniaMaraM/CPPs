/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 11:51:25 by tmarcos           #+#    #+#             */
/*   Updated: 2026/04/08 10:39:39 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

// These return the error message when the exception is caught
// what() is a virtual function from std::exception that we override

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high! (minimum is 1)";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low! (maximum is 150)";
}

// Constructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

// Parametric constructor: sets name and grade, validates grade range
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade){}

// Assignment operator: only copies grade (name is const, can't change)
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;
	return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

const std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

// subject requirement -> prints: "<name>, bureaucrat grade <grade>."
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}

// calls beSigned() - form decides if the grade is sufficient
// catches the exception
void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << *this << " signed " << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << *this << " couldn't sign " << form
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) const
{
    try
    {
        form.execute(*this);
        std::cout << *this << " executed " << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << *this << " couldn't execute " << form
                  << " because " << e.what() << std::endl;
    }
}
