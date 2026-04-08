/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 21:08:27 by tmarcos           #+#    #+#             */
/*   Updated: 2026/04/08 21:48:33 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"

class Serializer {
private:
    // Orthodox Canonical Form - all private (non-instantiable)
    Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
    ~Serializer();
    
public:
    // Converts pointer to unsigned integer
    static uintptr_t serialize(Data* ptr);
    
    // Converts unsigned integer back to pointer
    static Data* deserialize(uintptr_t raw);
};

#endif
