/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:00:00 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/28 13:59:37 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
	// Create PhoneBook object (constructor runs: array initialized, counters = 0)
	PhoneBook phoneBook;
	std::string command;

	// Welcome message
	std::cout << "Welcome to PhoneBook!" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;

	// Main loop: runs until EXIT or EOF (Ctrl+D)
	while (true) {
		std::cout << "> ";
		std::getline(std::cin, command);  // Read full line (allows spaces)

		// Detect EOF (Ctrl+D): exit gracefully
		if (std::cin.eof()) {
			std::cout << std::endl << "Goodbye!" << std::endl;
			break;  // Exit loop
		}

		// Route command to appropriate method (delegation pattern)
		if (command == "ADD") {
			phoneBook.addContact();  // Read 5 fields, store in array
		}
		else if (command == "SEARCH") {
			phoneBook.searchContact();  // Show table, get index, display details
		}
		else if (command == "EXIT") {
			std::cout << "Goodbye!" << std::endl;
			break;  // Exit loop
		}
		else {
			// Subject: "Any other input is ignored" - show error message
			std::cout << "Error: Invalid command! Use: ADD, SEARCH, EXIT" << std::endl;
		}
	}  // End of loop

	// When function ends: phoneBook goes out of scope → destructor runs
	// Array cleans itself: each Contact destructor → each std::string destructor
	return 0;
}

/*
1. main() começa
   ↓
2. PhoneBook phoneBook; (constructor corre)
   ↓
3. Mensagem de boas-vindas
   ↓
4. Loop infinito: while (true)
   ↓
5. Lê comando do user
   ↓
6. Comando == "ADD"?
   ├─ Sim → phoneBook.addContact()
   │         ├─ Lê 5 campos
   │         ├─ Valida (não vazio)
   │         ├─ Guarda no array
   │         └─ Volta ao loop
   │
   ├─ "SEARCH"?
   │  ├─ Sim → phoneBook.searchContact()
   │  │        ├─ Mostra tabela
   │  │        ├─ Lê índice
   │  │        ├─ Valida
   │  │        ├─ Mostra detalhes
   │  │        └─ Volta ao loop
   │  │
   │  ├─ "EXIT"?
   │  │  └─ break (sai do loop)
   │  │
   │  └─ Outro comando?
   │     ├─ Mensagem de erro
   │     └─ Volta ao loop
   │
7. Sai do loop (break)
   ↓
8. return 0
   ↓
9. phoneBook destructor corre (limpa tudo)
   ↓
10. Programa termina
*/