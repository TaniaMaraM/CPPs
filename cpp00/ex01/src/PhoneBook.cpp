/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:00:00 by tmarcos           #+#    #+#             */
/*   Updated: 2026/02/03 11:41:41 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : totalContacts(0), nextIndex(0) {
}

PhoneBook::~PhoneBook() {
}

std::string PhoneBook::readField(std::string fieldName) {
	std::string input;

	while (true) {
		std::cout << fieldName << ": ";
		std::getline(std::cin, input);

		if (std::cin.eof()) {
			std::cout << std::endl << "Input cancelled." << std::endl;
			return "";
		}

		if (input.empty() || input.find_first_not_of(" \t") == std::string::npos) {
			std::cout << "Error: Field cannot be empty!" << std::endl;
			continue;
		}
		return input;
	}
}
void PhoneBook::addContact() {
	std::string firstName = readField("First Name");
	if (firstName.empty())
		return;

	std::string lastName = readField("Last Name");
	if (lastName.empty())
		return;

	std::string nickname = readField("Nickname");
	if (nickname.empty())
		return;

	std::string phoneNumber = readField("Phone Number");
	if (phoneNumber.empty())
		return;

	std::string darkestSecret = readField("Darkest Secret");
	if (darkestSecret.empty())
		return;

	contacts[nextIndex].setFirstName(firstName);
	contacts[nextIndex].setLastName(lastName);
	contacts[nextIndex].setNickname(nickname);
	contacts[nextIndex].setPhoneNumber(phoneNumber);
	contacts[nextIndex].setDarkestSecret(darkestSecret);

	std::cout << "Contact added successfully!" << std::endl;

	nextIndex = (nextIndex + 1) % 8;
	if (totalContacts < 8)
		totalContacts++;
}

std::string PhoneBook::truncate(std::string str) const {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void PhoneBook::displayRow(int index) const {
	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << truncate(contacts[index].getFirstName()) << "|";
	std::cout << std::setw(10) << truncate(contacts[index].getLastName()) << "|";
	std::cout << std::setw(10) << truncate(contacts[index].getNickname()) << std::endl;
}

void PhoneBook::displayTable() const {
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	for (int i = 0; i < totalContacts; i++) {
		displayRow(i);
	}
}

void PhoneBook::searchContact() const {
	if (totalContacts == 0) {
		std::cout << "Error: PhoneBook is empty!" << std::endl;
		return;
	}
	displayTable();
	std::cout << "Enter index: ";
	int index;
	std::cin >> index;

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Error: Invalid input!" << std::endl;
		return;
	}
	std::cin.ignore(10000, '\n');

	if (index < 0 || index >= totalContacts) {
		std::cout << "Error: Index out of range!" << std::endl;
		return;
	}
	std::cout << std::endl;
	contacts[index].displayFull();
}
