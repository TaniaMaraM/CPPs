/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:42:41 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/28 18:12:02 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
private:
    std::string type;
    
public:
    Weapon(std::string type);  // constructor com tipo
    
    const std::string& getType() const;  // ← retorna REFERENCE (não copia!)
    void setType(std::string type);      // muda o tipo
};

#endif