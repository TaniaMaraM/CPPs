/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:23:08 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/05 12:57:13 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(){
	std::string str = "HI THIS IS BRAIN";

	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "Address of str:    " << &str << std::endl;
	std::cout << "Address in PTR:    " << stringPTR << std::endl;
	std::cout << "Address of REF:    " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "Value of str:     " << str << std::endl;
	std::cout << "Value via PTR:    " << *stringPTR << std::endl;
	std::cout << "Value via REF:    " << stringREF << std::endl;

	return 0;

}
