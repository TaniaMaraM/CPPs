/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:00:00 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/27 15:45:09 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip> // std::setw para formatar tabela (colunas alinhadas)

class PhoneBook {
private:
	Contact contacts[8];
	int totalContacts;
	int nextIndex;

	void displayTable() const;
	void displayRow(int index) const;
	std::string truncate(std::string str) const;
	std::string readField(std::string fieldName);

public:
	PhoneBook();
	~PhoneBook();

	void addContact();
	void searchContact() const;
};

#endif
