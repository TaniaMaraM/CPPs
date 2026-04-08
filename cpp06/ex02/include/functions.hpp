/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 22:00:00 by tmarcos           #+#    #+#             */
/*   Updated: 2026/04/08 22:00:00 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "Base.hpp"

// Randomly instantiates A, B, or C and returns as Base*
Base* generate(void);

// Identifies type using pointer
void identify(Base* p);

// Identifies type using reference (no pointers allowed inside!)
void identify(Base& p);

#endif
