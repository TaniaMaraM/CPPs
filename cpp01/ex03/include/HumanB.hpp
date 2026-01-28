/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:43:56 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/28 18:16:21 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
private:
    std::string name;
    Weapon* weapon;  // ← POINTER! Pode ser NULL (sem arma)
    
public:
    HumanB(std::string name);  // NÃO recebe arma (pode começar desarmado)
    void setWeapon(Weapon& weapon);  // dá arma depois
    void attack() const;
};

#endif