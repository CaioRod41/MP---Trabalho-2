#include "rainha.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using std::string;
using std::vector;


struct Position {
    int row;
    int col;
};

/**
 * @brief Verifica se um caractere é '0' ou '1'.
 * 
 * @param c O caractere a ser verificado.
 * @return true se o caractere é '0' ou '1', false caso contrário.
 */
bool isValidBinaryChar(char c) {
    return c == '0' || c == '1';
}

/**
 * @brief Verifica se uma linha de texto é uma linha binária válida de 8 caracteres.
 * 
 * @param line A linha de texto a ser verificada.
 * @return true se a linha contém exatamente 8 caracteres e todos são '0' ou '1', false caso contrário.
 */
bool isValidBinaryLine(const string& line) {
    return line.size() == 8 && std::all_of(line.begin(), line.end(), isValidBinaryChar);
}

/**
 * @brief Cria um arquivo de ataque para uma entrada e salva as coordenadas.
 * 
 * @param baseFilename O nome base do arquivo de entrada.
 * @param attacks As coordenadas das rainhas que se atacam.
 */
void saveAttacksToFile(const string& baseFilename, const vector<string>& attacks) {
    size_t lastSlash = baseFilename.find_last_of("/\\");
    string shortFilename = (lastSlash == string::npos) ? baseFilename : baseFilename.substr(lastSlash + 1);
    string outputFilename = "ataques_testes/ataque_" + shortFilename;

    std::ofstream file(outputFilename);
    if (!file) {
        cout << "Erro ao criar o arquivo de ataques: " << outputFilename << endl;
        return;
    }

    for (const string& attack : attacks) {
        file << attack << endl;
    }
}

/**
 * @brief Implementação para verificar se o tabuleiro é uma solução válida para o problema das 8 rainhas.
 * 
 * @param filename O nome do arquivo a ser verificado.
 * @param attacks Um vetor para armazenar as posições das rainhas que se atacam (se houver).
 * @return 1 se o arquivo contém uma matriz binária 8x8 válida sem ataques entre rainhas,
 *         0 se contém uma matriz válida mas com ataques,
 *         -1 se o arquivo é inválido (não é 8x8 ou contém caracteres inválidos).
 */
int isBinary8x8(const string& filename, vector<string>& attacks) {
    std::ifstream file(filename);
    if (!file) {
        cout << "Erro ao abrir o arquivo: " << filename << endl;
        return -1;
    }

    string line;
    int validLines = 0;
    int totalQueens = 0;
    vector<Position> queenPositions;

    while (getline(file, line)) {
        if (!isValidBinaryLine(line)) {
            return -1;
        }
        for (size_t i = 0; i < line.size(); ++i) {
            if (line[i] == '1') {
                queenPositions.push_back({validLines, static_cast<int>(i)});
                totalQueens++;
            }
        }
        validLines++;
    }

    if (validLines != 8 || totalQueens != 8) {
        return -1;
    }

    bool hasAttacks = false;
    for (size_t i = 0; i < queenPositions.size(); ++i) {
        for (size_t j = i + 1; j < queenPositions.size(); ++j) {
            int rowDiff = abs(queenPositions[i].row - queenPositions[j].row);
            int colDiff = abs(queenPositions[i].col - queenPositions[j].col);
            if (rowDiff == colDiff || rowDiff == 0 || colDiff == 0) {
                hasAttacks = true;
                attacks.push_back(std::to_string(queenPositions[i].row + 1) + "," +
                                  std::to_string(queenPositions[i].col + 1) + " " +
                                  std::to_string(queenPositions[j].row + 1) + "," +
                                  std::to_string(queenPositions[j].col + 1));
            }
        }
    }

    if (hasAttacks) {
        saveAttacksToFile(filename, attacks);
        return 0;
    }

    return 1;
}

/**
 * @brief Função principal para verificar se um arquivo contém uma solução válida para o problema das 8 rainhas.
 * 
 * @param filename O nome do arquivo a ser verificado.
 * @return 1 se o arquivo contém uma solução válida para o problema das 8 rainhas,
 *         0 se contém uma matriz válida mas não é uma solução,
 *         -1 se o arquivo é inválido.
 */
int answer(const string& filename) {
    vector<string> attacks;
    return isBinary8x8(filename, attacks);
}
