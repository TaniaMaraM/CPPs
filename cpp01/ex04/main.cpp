#include <iostream>   // std::cout, std::cerr, std::endl
#include <fstream>    // std::ifstream, std::ofstream
#include <string>     // std::string

std::string replaceAll(const std::string& str, const std::string& s1, const std::string& s2) {
    std::string result;
    size_t pos = 0;
    size_t found;

    while ((found = str.find(s1, pos)) != std::string::npos) {
        result.append(str, pos, found - pos);
        result.append(s2);
        pos = found + s1.length();
    }

    result.append(str, pos, str.length() - pos);

    return result;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: ./replace <file> <s1> <s2>" << std::endl;
        return 1;  // erro
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty()) {
        std::cerr << "Error: s1 cannot be empty" << std::endl;
        return 1;
    }

    std::ifstream inFile(filename.c_str());
    if (!inFile) {
        std::cerr << "Error: cannot open " << filename << std::endl;
        return 1;
    }

    std::string content;
    std::string line;

    while (std::getline(inFile, line)) {
        content += line;
        if (!inFile.eof())
            content += '\n';
    }
    inFile.close();

    std::ofstream outFile((filename + ".replace").c_str());
    if (!outFile) {
        std::cerr << "Error: cannot create output file" << std::endl;
        return 1;
    }

    outFile << replaceAll(content, s1, s2);
    outFile.close();

    return 0;
}
