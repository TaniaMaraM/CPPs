/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:23:08 by tmarcos           #+#    #+#             */
/*   Updated: 2026/01/29 14:24:04 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(){
	std::string str = "HI THIS IS BRAIN";

	std::string* stringPTR = &str; //pointer guarda o end
	std::string& stringREF = str; //reference eh alias de str
	//print addresses
	std::cout << "Address of str:    " << &str << std::endl;
	std::cout << "Address in PTR:    " << stringPTR << std::endl;
	std::cout << "Address of REF:    " << &stringREF << std::endl;

	std::cout << std::endl;

	//print values
	std::cout << "Value of str:     " << str << std::endl;
	std::cout << "Value via PTR:    " << *stringPTR << std::endl;
	std::cout << "Value via REF:    " << stringREF << std::endl;

	return 0;

}


/*
Declaração	int* ptr	int& ref
Inicialização	Pode ser NULL	Nunca NULL (obrigatória na criação)
Reatribuição	Pode mudar alvo	Nunca muda alvo
Acesso	*ptr (dereference)	ref (directo)
Sintaxe	ptr->method()	ref.method()

int x = 42;

POINTER:   "ptr guarda o ENDEREÇO da casa onde mora o 42"
		   → tens um papel com a morada

REFERENCE: "ref É OUTRO NOME para x"
		   → é como alcunha: "António" = "Tó" (mesma pessoa!)


	🧠 O que é uma reference?

Uma reference é um apelido (alias) para uma variável que já existe.

Ela não guarda endereço.
Ela não é um objeto separado.
Ela é o mesmo objeto com outro nome.
🍽️ Analogia definitiva

Pointer → “talvez eu tenha um copo”

Reference → “eu estou segurando um copo AGORA”

🔑 Regra de ouro (decora essa)

Use reference quando a relação é obrigatória
Use pointer quando a relação é opcional
*/
