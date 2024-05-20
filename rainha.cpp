#include <string>
#include <unordered_map>

int romano_para_decimal(const std::string &romano)
{
    if (romano.empty())
    {
        return -1; // String vazia
    }

    std::unordered_map<char, int> valores = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

    int decimal = 0;
    int tamanho = romano.size();

    // Convertendo para decimal e verificando caracteres inválidos
    for (int i = 0; i < tamanho; i++)
    {
        if (valores.find(romano[i]) == valores.end())
        {
            return -1; // Caractere inválido
        }

        if (i + 1 < tamanho && valores[romano[i]] < valores[romano[i + 1]])
        {
            decimal += valores[romano[i + 1]] - valores[romano[i]];
            i++;
        }
        else
        {
            decimal += valores[romano[i]];
        }
    }

    // Verifica repetições inválidas
    for (int i = 0; i < tamanho - 1; i++)
    {
        if (romano[i] == romano[i + 1] && (romano[i] == 'V' || romano[i] == 'L' || romano[i] == 'D'))
        {
            return -1; // Caractere repetido inválido
        }

        if (i + 3 < tamanho && romano[i] == romano[i + 1] && romano[i] == romano[i + 2] && romano[i] == romano[i + 3])
        {
            return -1; // Mais de 3 caracteres repetidos consecutivamente
        }
    }

    if (romano.find("DIVX") != std::string::npos){
        return -1; // Sequencia adional invalida após C
     }
     
    // Verificaoes entradas invalidas
    for (int i = 0; i < tamanho - 1; i++)
    {
        if (romano[i] == 'X' && romano[i + 1] == 'L')
        {
            for (int j = i + 2; j < tamanho; j++)
            {
                if (romano[j] == 'C')
                {
                    return -1;
                }
            }
        }
        if (romano[i] == 'V' && romano[i + 1] == 'I')
        {
            for (int j = i + 2; j < tamanho; j++)
            {
                if (romano[j] == 'X')
                {
                    return -1;
                }
            }
        }
        if (romano[i] == 'V' && romano[i + 1] == 'I')
        {
            for (int j = i + 2; j < tamanho; j++)
            {
                if (romano[j] == 'X')
                {
                    return -1;
                }
            }
        }
    }

    // Verifica caracteres inválidos adicionais
    for (char c : romano)
    {
        if (c != 'I' && c != 'V' && c != 'X' && c != 'L' && c != 'C' && c != 'D' && c != 'M')
        {
            return -1; // Caractere inválido
        }
    }

     

    return decimal;
}
