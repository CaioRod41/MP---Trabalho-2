#include "rainha.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm> // Para usar a função count
#include <cmath> // Para usar a função abs

using std::cout;
using std::endl;
using std::string;
using std::vector;

struct Position {
    int row;
    int col;
};

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

void saveAttacksToFile(const string& filename, const vector<string>& attacks) {
    std::ofstream file(filename);
    if (!file) {
        cout << "Erro ao criar o arquivo de ataques: " << filename << endl;
        return;
    }

    for (const string& attack : attacks) {
        file << attack << endl;
    }

    file.close();
}

int isBinary8x8(const string& filename, vector<string>& attacks) {
    std::ifstream file(filename);
    if (!file) {
        cout << "Erro ao abrir o arquivo: " << filename << endl;
        return -1;
    }

    string line;
    int validLines = 0;
    int totalQueens = 0;
    vector<Position> queenPositions; // Armazena as posições das rainhas

    // Leitura do arquivo e verificação das linhas
    while (getline(file, line)) {
        if (!isValidBinaryLine(line)) {
            cout << "Linha inválida no arquivo: " << filename << endl;
            return -1;
        }
        validLines++;

        // Conta o número de rainhas na linha e armazena suas posições
        for (size_t i = 0; i < line.size(); ++i) {
            if (line[i] == '1') {
                totalQueens++;
                queenPositions.push_back({validLines - 1, static_cast<int>(i)});
            }
        }
    }

    file.close();

    if (validLines != 8 || totalQueens != 8) {
        cout << "Tabuleiro inválido: não possui 8 linhas válidas ou 8 rainhas" << endl;
        return -1;
    }

    // Verifica se há ataques entre as rainhas
    for (size_t i = 0; i < queenPositions.size(); ++i) {
        for (size_t j = i + 1; j < queenPositions.size(); ++j) {
            int rowDiff = abs(queenPositions[i].row - queenPositions[j].row);
            int colDiff = abs(queenPositions[i].col - queenPositions[j].col);
            if (rowDiff == colDiff || rowDiff == 0 || colDiff == 0) {
                // As rainhas se atacam
                attacks.push_back("Rainha na posição " + std::to_string(queenPositions[i].row + 1) +
                                  "," + std::to_string(queenPositions[i].col + 1) + " ataca rainha na posição " +
                                  std::to_string(queenPositions[j].row + 1) + "," + std::to_string(queenPositions[j].col + 1));
            }
        }
    }

    if (!attacks.empty()) {
        saveAttacksToFile("ataques.txt", attacks);
        return 0;
    }

    return 1;
}

int answer(const string& filename) {
    vector<string> attacks;
    return isBinary8x8(filename, attacks);
}
