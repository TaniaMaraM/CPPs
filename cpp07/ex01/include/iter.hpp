/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:14:21 by tmarcos           #+#    #+#             */
/*   Updated: 2026/04/13 20:28:17 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename F>
void iter (T *array, const size_t len, F func)
{
    for (size_t i = 0; i < len; i++)
        func(array[i]);
    
}

#endif

/*
typename T
o tipo dos elementos do array
typename F
o tipo da função a chamar em cada elemento
*/