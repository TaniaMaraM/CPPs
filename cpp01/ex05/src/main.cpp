/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:06:48 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/28 19:15:30 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
    Harl harl;
    
    std::cout << "=== DEBUG ===" << std::endl;
    harl.complain("DEBUG");
    
    std::cout << "\n=== INFO ===" << std::endl;
    harl.complain("INFO");
    
    std::cout << "\n=== WARNING ===" << std::endl;
    harl.complain("WARNING");
    
    std::cout << "\n=== ERROR ===" << std::endl;
    harl.complain("ERROR");
    
    std::cout << "\n=== INVALID ===" << std::endl;
    harl.complain("INVALID");
    
    return 0;
}