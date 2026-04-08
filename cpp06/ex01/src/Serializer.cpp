/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 21:08:25 by tmarcos           #+#    #+#             */
/*   Updated: 2026/04/08 21:49:17 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

//Orthodox Canonical Form
Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other) {
    (void)other;
}

Serializer& Serializer::operator=(const Serializer& other) {
    (void)other;
    return *this;
}

Serializer::~Serializer() {}

//serialization methods
uintptr_t Serializer::serialize(Data* ptr)
{
    // Convert pointer to unsigned integer using reinterpret_cast
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    // Convert unsigned integer back to pointer using reinterpret_cast
    return reinterpret_cast<Data*>(raw);
}
