#include "rainha.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm> // Para usar a função count

using std::cout;
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
    int validLines = 0;
    int totalQueens = 0;

    while (getline(file, line)) {
        if (!isValidBinaryLine(line)) {
            cout << "Linha inválida no arquivo: " << filename << endl;
            return -1;
        }
        validLines++;

        // Conta o número de rainhas na linha
        totalQueens += std::count(line.begin(), line.end(), '1');
    }

    file.close();

    if (validLines != 8 || totalQueens != 8) {
        cout << "Tabuleiro inválido: não possui 8 linhas válidas ou 8 rainhas" << endl;
        return -1;
    }

    return 1;
}


int answer(const string& filename) {
    return isBinary8x8(filename);
}