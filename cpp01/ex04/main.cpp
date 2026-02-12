#include <iostream>   // std::cout, std::cerr, std::endl
#include <fstream>    // std::ifstream, std::ofstream
#include <string>     // std::string

// Função que substitui TODAS ocorrências de s1 por s2
std::string replaceAll(const std::string& str, const std::string& s1, const std::string& s2) {
    std::string result;      // string vazia onde vamos construir o resultado
    size_t pos = 0;          // posição atual na string original
    size_t found;            // posição onde encontramos s1

    while ((found = str.find(s1, pos)) != std::string::npos) {
        result.append(str, pos, found - pos); //str coppying from. Pos position na str. found is where 
        result.append(s2);
        pos = found + s1.length(); //sum to go to the next search 
    }
    result.append(str, pos, str.length() - pos); //copy whatever is left in the original string.
    return result;
}

int main(int argc, char **argv) {
    // 1. Validar: precisa de exactamente 4 argumentos
    if (argc != 4) {
        std::cerr << "Usage: ./replace <file> <s1> <s2>" << std::endl;
        return 1;  // erro
    }

    // 2. Guardar argumentos em variáveis
    std::string filename = argv[1];  // nome do ficheiro
    std::string s1 = argv[2];        // string a procurar
    std::string s2 = argv[3];        // string de substituição

    // 3. s1 não pode ser vazio (causaria loop infinito!)
    if (s1.empty()) {
        std::cerr << "Error: s1 cannot be empty" << std::endl;
        return 1;
    }

    // 4. Abrir ficheiro de entrada
    std::ifstream inFile(filename.c_str());  // .c_str() converte para char* (C++98)
    if (!inFile) {  // se falhou a abrir
        std::cerr << "Error: cannot open " << filename << std::endl;
        return 1;
    }

    // 5. Ler ficheiro INTEIRO para uma string
    std::string content;  // vai guardar todo o conteúdo
    std::string line;     // linha temporária

    while (std::getline(inFile, line)) {  // lê linha por linha
        content += line;                   // adiciona linha
        if (!inFile.eof())                 // se NÃO é última linha
            content += '\n';               // adiciona newline
    }
    inFile.close();  // fecha ficheiro

    // 6. Criar ficheiro de saída
    std::ofstream outFile((filename + ".replace").c_str());
    if (!outFile) {
        std::cerr << "Error: cannot create output file" << std::endl;
        return 1;
    }

    //  I call replaceAll and write the result directly to outFile
    outFile << replaceAll(content, s1, s2);
    outFile.close();

    return 0;  // sucesso!
}

/*
 s1

não pode ser vazio porque o algoritmo usa
find(s1, pos) em loop.
Se s1 == "", o find sempre encontra na mesma
posição e o loop nunca avança → loop infinito.

Já s2 pode ser vazio, porque isso só significa
 apagar o que foi encontrado.
*/
