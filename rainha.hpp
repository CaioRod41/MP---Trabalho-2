#include <string>
#include <vector>

/**
 * @brief Verifica se um caractere é um dígito binário ('0' ou '1').
 */
bool isValidBinaryChar(char c);

/**
 * @brief Verifica se uma linha de texto é uma linha binária válida de 8 caracteres.
 */
bool isValidBinaryLine(const std::string& line);

/**
 * @brief Verifica se um arquivo contém uma matriz binária 8x8 válida e identifica posições de ataques entre rainhas.
 */
int isBinary8x8(const std::string& filename, std::vector<std::string>& attacks);

/**
 * @brief Função principal para verificar se um arquivo contém uma solução válida para o problema das 8 rainhas.
 */
int answer(const std::string& filename);


