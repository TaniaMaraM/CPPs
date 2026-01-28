/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:00:00 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/27 15:39:19 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Vazio: std::string já inicializa vazio automaticamente
// Quando crias Contact c: 5 strings chamam std::string() → ""
Contact::Contact() {
}

// Vazio: std::string limpa sua própria memória (não precisa free)
Contact::~Contact() {
}

// Setters: acesso controlado a dados privados (encapsulation)
// firstName é private → não podes fazer c.firstName = "John" directamente
void Contact::setFirstName(std::string name) {
	firstName = name;
}

void Contact::setLastName(std::string name) {
	lastName = name;
}

void Contact::setNickname(std::string nick) {
	nickname = nick;
}

void Contact::setPhoneNumber(std::string phone) {
	phoneNumber = phone;
}

void Contact::setDarkestSecret(std::string secret) {
	darkestSecret = secret;
}

// Getters: retornam dados privados (read-only)
// const no fim: promete não modificar o objecto (compilador verifica!)
std::string Contact::getFirstName() const {
	return firstName;
}

std::string Contact::getLastName() const {
	return lastName;
}

std::string Contact::getNickname() const {
	return nickname;
}

std::string Contact::getPhoneNumber() const {
	return phoneNumber;
}

std::string Contact::getDarkestSecret() const {
	return darkestSecret;
}

// Verifica se contacto foi preenchido (usado por PhoneBook)
// Se firstName vazio → contacto não foi adicionado ainda
bool Contact::isEmpty() const {
	return firstName.empty();  // .empty() retorna true se string == ""
}

// Mostra TODOS os campos (usado no SEARCH após escolher índice)
// Contact sabe como se mostrar (responsabilidade da classe)
void Contact::displayFull() const {
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}