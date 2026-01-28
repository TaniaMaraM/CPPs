/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:00:00 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/28 13:44:33 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

/**
 * @class Contact
 * @brief Represents a phonebook contact with personal information
 * 
 * This class stores contact information (first name, last name, nickname,
 * phone number, and darkest secret). All data is private and accessed
 * through setters/getters (encapsulation).
 * 
 * @note Strings are empty by default (no need to initialize in constructor)
 */
class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	/**
	 * @brief Default constructor
	 * 
	 * Creates an empty contact. All std::string members are automatically
	 * initialized to empty strings by their own constructors.
	 * 
	 * @note No dynamic allocation needed - std::string manages its own memory
	 */
	Contact();
	
	/**
	 * @brief Destructor
	 * 
	 * Cleans up the contact. Body is empty because std::string members
	 * automatically clean themselves up (no manual free needed).
	 */
	~Contact();

	// Setters
	/**
	 * @brief Set the first name (setter)
	 * @param name New first name
	 * @note Setters provide controlled access to private data (encapsulation)
	 */
	void setFirstName(std::string name);
	void setLastName(std::string name);      ///< Set last name
	void setNickname(std::string nick);
	void setPhoneNumber(std::string phone);
	void setDarkestSecret(std::string secret); 

	// Getters
	/**
	 * @brief Get the first name (getter)
	 * @return Contact's first name
	 * @note const means this method doesn't modify the object (read-only)
	 */
	std::string getFirstName() const;
	std::string getLastName() const;        ///< Get last name
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

	// Helpers
	/**
	 * @brief Check if contact is empty
	 * @return true if firstName is empty (contact not filled)
	 * @note Used by PhoneBook to know which slots are occupied
	 */
	bool isEmpty() const;
	
	/**
	 * @brief Display all contact information
	 * @note Prints all fields to stdout (Contact knows how to display itself)
	 */
	void displayFull() const;
};

#endif
