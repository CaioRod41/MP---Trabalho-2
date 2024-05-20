#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "rainha.hpp"

TEST_CASE("Verifica o tamanho da matriz") {
    SECTION("Arquivo válido, porém não é a solução") {
        REQUIRE(answer("testes/jogadateste.txt") == 0);
    }
    SECTION("Arquivo inválido, não é 8x8") {
        REQUIRE(answer("testes/jogadatesteerro.txt") == -1);
    }

    SECTION("Arquivo inválido, não contém apenas 0 e 1") {
        REQUIRE(answer("testes/jogadateste2.txt") == -1);
    }

    SECTION("Arquivo inválido, todos os números são 0") {
        REQUIRE(answer("testes/todos_zeros.txt") == -1);
    }

    SECTION("Arquivo inválido, todos os números são 1") {
        REQUIRE(answer("testes/todos_uns.txt") == -1);
    }

    SECTION("Arquivo inválido, o numero de rainhas deve ser 8") {
        REQUIRE(answer("testes/testeqtde1.txt") == -1);
        REQUIRE(answer("testes/testeqtde2.txt") == -1);
        REQUIRE(answer("testes/testeqtde3.txt") == -1);
    }

    SECTION("Numero de rainhas = 8, mas nao é a solução") {
        REQUIRE(answer("testes/testeatk1.txt") == 0);
        REQUIRE(answer("testes/testeatk2.txt") == 0);
        REQUIRE(answer("testes/testeatk3.txt") == 0);
        REQUIRE(answer("testes/testeatk4.txt") == 0);
        REQUIRE(answer("testes/testeatk5.txt") == 0);
        REQUIRE(answer("testes/testeatk6.txt") == 0);
    }

    SECTION("Arquivos válios"){
        
        REQUIRE(answer("testes/solucao1.txt") == 1);
    }

     SECTION("Arquivo vazio") {
        REQUIRE(answer("testes/arquivo_vazio.txt") == -1);
    }

}




