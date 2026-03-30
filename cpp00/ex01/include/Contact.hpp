/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:00:00 by tmarcos           #+#    #+#             */
/*   Updated: 2026/03/30 15:09:59 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	Contact();
	~Contact();

	// Setters
	void setFirstName(std::string name);
	void setLastName(std::string name);      ///< Set last name
	void setNickname(std::string nick);
	void setPhoneNumber(std::string phone);
	void setDarkestSecret(std::string secret); 

	// Getters
	std::string getFirstName() const;
	std::string getLastName() const;        ///< Get last name
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

	// Helpers
	bool isEmpty() const;
	void displayFull() const;
};

#endif
