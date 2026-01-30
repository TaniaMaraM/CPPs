/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:00:00 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/30 08:41:19 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// Initialization list: inicializa ints ANTES de entrar no corpo (mais eficiente)
// Array contacts[8] é inicializado automaticamente (cada Contact chama seu constructor)
PhoneBook::PhoneBook() : totalContacts(0), nextIndex(0) {
}

// Vazio: array limpa-se sozinho (cada Contact chama seu destructor)
PhoneBook::~PhoneBook() {
}

// Lê um campo com validação: não aceita vazio/whitespace, detecta EOF
std::string PhoneBook::readField(std::string fieldName) {
	std::string input;

	while (true) {
		std::cout << fieldName << ": ";
		std::getline(std::cin, input);

		if (std::cin.eof()) {
			std::cout << std::endl << "Input cancelled." << std::endl;
			return "";
		}

		if (input.empty() || input.find_first_of(" \t") != std::string::npos) {
			std::cout << "Error: Field cannot be empty" << std::endl;
			continue;
		}

		return input;
	}
}

// Lê 5 campos do user e adiciona ao array (substitui mais antigo se cheio)
void PhoneBook::addContact() {
	// Lê cada campo; se EOF (empty), cancela toda operação
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

	// Guardar no slot nextIndex (pode sobrescrever contacto antigo)
	contacts[nextIndex].setFirstName(firstName);
	contacts[nextIndex].setLastName(lastName);
	contacts[nextIndex].setNickname(nickname);
	contacts[nextIndex].setPhoneNumber(phoneNumber);
	contacts[nextIndex].setDarkestSecret(darkestSecret);

	std::cout << "Contact added successfully!" << std::endl;

	// % 8 faz índice circular: 0,1,2...7,0,1... (substitui mais antigo)
	nextIndex = (nextIndex + 1) % 8;
	if (totalContacts < 8)
		totalContacts++;  // Incrementa até 8, depois fica em 8
}

// Subject: colunas têm 10 chars, strings longas truncadas com '.'
// Ex: "Christopher" (11) → "Christoph." (10)
std::string PhoneBook::truncate(std::string str) const {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";  // 9 chars + ponto = 10 total
	return str;  // ≤10 chars: mantém original
}

// Mostra uma linha da tabela: setw(10) força 10 chars por coluna
void PhoneBook::displayRow(int index) const {
	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << truncate(contacts[index].getFirstName()) << "|";
	std::cout << std::setw(10) << truncate(contacts[index].getLastName()) << "|";
	std::cout << std::setw(10) << truncate(contacts[index].getNickname()) << std::endl;
}

// Mostra cabeçalho + todas as linhas (só contactos adicionados)
void PhoneBook::displayTable() const {
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	for (int i = 0; i < totalContacts; i++) {  // Só slots ocupados
		displayRow(i);
	}
}

// Mostra tabela, pede índice, mostra detalhes completos do contacto
void PhoneBook::searchContact() const {
	if (totalContacts == 0) {
		std::cout << "Error: PhoneBook is empty!" << std::endl;
		return;
	}
	displayTable();
	std::cout << "Enter index: ";
	int index;
	std::cin >> index;  // Lê número directamente

	// Detecta se user digitou letra (ex: "abc")
	if (std::cin.fail()) {
		std::cin.clear();  // Limpa flag de erro
		std::cin.ignore(10000, '\n');  // Limpa buffer (10000 = suficiente para qualquer input)
		std::cout << "Error: Invalid input!" << std::endl;
		return;
	}
	// cin >> deixa \n no buffer; ignore remove para não afetar próximo getline
	std::cin.ignore(10000, '\n');

	// Valida range: índice deve estar entre 0 e totalContacts-1
	if (index < 0 || index >= totalContacts) {
		std::cout << "Error: Index out of range!" << std::endl;
		return;
	}
	std::cout << std::endl;
	contacts[index].displayFull();  // Contact mostra-se a si próprio
}
