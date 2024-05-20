#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "rainha.hpp"

/**
 * @brief Casos de testes para soluções inválidas cuja estrutura está incorreta.
 */
TEST_CASE("Soluções inválidas -1") {

    /**
     * @brief Teste para verificar se o arquivo não é 8x8.
     */
    SECTION("Arquivo inválido, não é 8x8") {
        REQUIRE(answer("testes/jogadatesteerro.txt") == -1);
    }

    /**
     * @brief Testes para verificar se o arquivo contém caracteres diferentes de 0 e 1.
     */
    SECTION("Arquivo inválido, não contém apenas 0 e 1") {
        REQUIRE(answer("testes/jogadateste2.txt") == -1);
        REQUIRE(answer("testes/testescaracter.txt") == -1);
    }

    /**
     * @brief Teste para verificar se o arquivo contém apenas 0.
     */
    SECTION("Arquivo inválido, todos os números são 0") {
        REQUIRE(answer("testes/todos_zeros.txt") == -1);
    }

    /**
     * @brief Teste para verificar se o arquivo contém apenas 1.
     */
    SECTION("Arquivo inválido, todos os números são 1") {
        REQUIRE(answer("testes/todos_uns.txt") == -1);
    }

    /**
     * @brief Testes para verificar se o número de rainhas não é 8.
     */
    SECTION("Arquivo inválido, o número de rainhas deve ser 8") {
        REQUIRE(answer("testes/testeqtde1.txt") == -1);
        REQUIRE(answer("testes/testeqtde2.txt") == -1);
        REQUIRE(answer("testes/testeqtde3.txt") == -1);
    }

    /**
     * @brief Teste para verificar se o arquivo está vazio.
     */
    SECTION("Arquivo vazio") {
        REQUIRE(answer("testes/arquivo_vazio.txt") == -1);
    }
}

/**
 * @brief Casos de testes para soluções inválidas cuja estrutura está correta.
 */
TEST_CASE("Soluções inválidas - 0") {

    /**
     * @brief Testes para verificar se há 8 rainhas, mas não é uma solução válida.
     */
    SECTION("Número de rainhas = 8, mas não é a solução") {
        REQUIRE(answer("testes/testeatk1.txt") == 0);
        REQUIRE(answer("testes/testeatk2.txt") == 0);
        REQUIRE(answer("testes/testeatk3.txt") == 0);
        REQUIRE(answer("testes/testeatk4.txt") == 0);
        REQUIRE(answer("testes/testeatk5.txt") == 0);
        REQUIRE(answer("testes/testeatk6.txt") == 0);
        REQUIRE(answer("testes/testeatk7.txt") == 0);
    }

    /**
     * @brief Teste para verificar se o arquivo é válido, mas não é uma solução.
     */
    SECTION("Arquivo válido, porém não é a solução") {
        REQUIRE(answer("testes/jogadateste.txt") == 0);
    }
}

/**
 * @brief Casos de testes para soluções válidas.
 */
TEST_CASE("Soluções válidas") {

    /**
     * @brief Teste para verificar se o arquivo é uma solução válida.
     */
    SECTION("Arquivos válidos") {
        REQUIRE(answer("testes/solucao1.txt") == 1);
    }
}
