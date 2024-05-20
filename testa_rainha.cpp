#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "rainha.hpp"

TEST_CASE("Verifica o tamanho da matriz") {
    SECTION("Arquivo inválido, não é 8x8") {
        REQUIRE(answer("testes/jogadateste.txt") == 1);
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
        REQUIRE(answer("testes/testeqtd/testeqtde1.txt") == -1);
        REQUIRE(answer("testes/testeqtd/testeqtde2.txt") == -1);
        REQUIRE(answer("testes/testeqtd/testeqtde3.txt") == -1);
    }

  
}
