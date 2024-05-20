#include "rainha.hpp"
#include <fstream> 
#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool isValidBinaryChar(char c) {
    return c == '0' || c == '1';
}

bool isValidBinaryLine(const string& line) {
    if (line.size() != 8) {
        return false;
    }
    for (char c : line) {
        if (!isValidBinaryChar(c)) {
            return false;
        }
    }
    return true;
}

int isBinary8x8(const string& filename) {
    std::ifstream file(filename);
    if (!file) {
        cout << "Erro ao abrir o arquivo: " << filename << endl;
        return -1;
    }

    string line;
    int lineCount = 0;
    int validLines = 0;

    while (getline(file, line)) {
        if (!isValidBinaryLine(line)) {
            cout << "Linha inválida no arquivo: " << filename << endl;
            return -1;
        }
        ++lineCount;
        if (lineCount == 8) {
            validLines++;
            lineCount = 0; // Reinicia o contador para a próxima matriz
        }
    }

    file.close();
    return (validLines == 8) ? 1 : -1;
}


int answer(const string& filename) {
    return isBinary8x8(filename);
}
