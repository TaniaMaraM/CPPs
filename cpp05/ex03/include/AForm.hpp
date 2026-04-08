/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 22:03:30 by tmarcos           #+#    #+#             */
/*   Updated: 2026/04/08 10:32:40 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        const int           _gradeSign;
        const int           _gradeExecute;
        bool                _signed;
        
    //AForm + all classes can use (Shrubbery, Robotomy, Pardon)
    protected:
        void checkExecution(Bureaucrat const &executor) const;

    public:
        AForm();
        AForm(const std::string &name, int gradeSign, int gradeExecute);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();  // virtual — subclasses have their own destructor

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
        class NotSignedException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        const std::string   getName() const;
        int                 getGradeSign() const;
        int                 getGradeExecute() const;
        bool                getSigned() const;

        void    beSigned(Bureaucrat const &b);

        // pure virtual — each concrete form implements its own action
        virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif

/*
virtual ~AForm() — o destrutor precisa de ser virtual quando há 
herança (caso contrário deletar uma subclasse via ponteiro de base vai fazer memory leak)
NotSignedException — nova: quando tentam executar um form não assinado
virtual void execute(...) const = 0 — pure virtual, 
obriga cada filha a implementar
*/
