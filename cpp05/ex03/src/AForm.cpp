/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 22:03:41 by tmarcos           #+#    #+#             */
/*   Updated: 2026/04/08 10:28:41 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

//Exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
    return "form grade too high (minimum is 1)";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "grade too low (maximum is 150)";
}

const char *AForm::NotSignedException::what() const throw()
{
    return "form is not signed";
}

//Constructors 

AForm::AForm() : _name("Default"), _gradeSign(150), _gradeExecute(150), _signed(false) {}

AForm::AForm(const std::string &name, int gradeSign, int gradeExecute)
    : _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute), _signed(false)
{
    if (gradeSign < 1 || gradeExecute < 1)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : _name(other._name), _gradeSign(other._gradeSign),
      _gradeExecute(other._gradeExecute), _signed(other._signed) {}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        _signed = other._signed;
    return *this;
}

AForm::~AForm() {}

//Getters
const std::string   AForm::getName() const          {return _name;}
int                 AForm::getGradeSign() const     {return _gradeSign;}
int                 AForm::getGradeExecute() const  {return _gradeExecute;}
bool                AForm::getSigned() const        {return _signed;}

//beSigned
void AForm::beSigned(Bureaucrat const &b)
{
    if (b.getGrade() > _gradeSign)
        throw GradeTooLowException();
    _signed = true;
}

// called by concrete classes before executing — validates signed + grade
void AForm::checkExecution(Bureaucrat const &executor) const
{
    if (!_signed)
        throw NotSignedException();
    if (executor.getGrade() > _gradeExecute)
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << "Form: "      << form.getName()
        << " | sign: "   << form.getGradeSign()
        << " | exec: "   << form.getGradeExecute()
        << " | signed: " << (form.getSigned() ? "yes" : "no");
    return out;
}