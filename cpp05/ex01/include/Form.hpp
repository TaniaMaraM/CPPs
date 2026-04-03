/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 16:53:41 by tmarcos           #+#    #+#             */
/*   Updated: 2026/04/03 18:10:57 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
    private:
        const std::string  _name;
        const int          _gradeSign;
        const int          _gradeExecute;
        bool               _signed;

    public:
        Form();
        Form(const std::string &name, int gradeSign, int gradeExecute);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();

        class GradeTooHighException : public std::exception
        {
            public:
                    virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                    virtual const char *what() const throw();
        };
        
        const std::string   getName()const;
        int                 getGradeSign()const;
        int                 getGradeExecute()const;
        bool                getSigned() const;

        void    beSigned(Bureaucrat const &b);
        
};

std::ostream &operator<<(std::ostream &out, const Form &form);


#endif