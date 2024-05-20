#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "rainha.hpp"

TEST_CASE("Verifica o tamanho da matriz", "[rainha]") {
    SECTION("Arquivo inválido, não é 8x8") {
        REQUIRE(answer("testes/jogadateste.txt") == -1);
        REQUIRE(answer("testes/jogadatesteerro.txt") == -1);
    }

}
