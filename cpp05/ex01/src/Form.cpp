/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 16:53:44 by tmarcos           #+#    #+#             */
/*   Updated: 2026/04/03 18:29:52 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
	return "form grade too high (minimum is 1)";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "grade too low (maximum is 150)";
}
//constructors
Form::Form() : _name("Default"), _gradeSign(150), _gradeExecute(150), _signed(false) {}

// parametric: validates both grades before accepting them
Form::Form(const std::string &name, int gradeSign, int gradeExecute)
    : _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute), _signed(false)
{
    if (gradeSign < 1 || gradeExecute < 1)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExecute > 150)
        throw GradeTooLowException();
}

// copy constructor
Form::Form(const Form &other)
    : _name(other._name), _gradeSign(other._gradeSign),
      _gradeExecute(other._gradeExecute), _signed(other._signed) {}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        _signed = other._signed;
    return *this;
}

Form::~Form() {}

//getters
const std::string   Form::getName() const       { return _name; }
int                 Form::getGradeSign() const  { return _gradeSign; }
int                 Form::getGradeExecute() const { return _gradeExecute; }
bool                Form::getSigned() const     { return _signed; }

// --- beSigned ---
// bureaucrat's grade must be <= _gradeSign to sign
// remember: lower number = higher rank (grade 1 beats grade 2)
void Form::beSigned(Bureaucrat const &b)
{
    if (b.getGrade() > _gradeSign)
        throw GradeTooLowException();
    _signed = true;
}

// --- operator<< ---
std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form: "     << form.getName()
        << " | sign: "  << form.getGradeSign()
        << " | exec: "  << form.getGradeExecute()
        << " | signed: "<< (form.getSigned() ? "yes" : "no");
    return out;
}

