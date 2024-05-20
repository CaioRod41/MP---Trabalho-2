#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "romanos.hpp"

TEST_CASE("Numeros romanos - algarismos únicos", "[romanos]") {
    REQUIRE(romano_para_decimal("I") == 1);
    REQUIRE(romano_para_decimal("V") == 5);
    REQUIRE(romano_para_decimal("X") == 10);
    REQUIRE(romano_para_decimal("L") == 50);
    REQUIRE(romano_para_decimal("C") == 100);
    REQUIRE(romano_para_decimal("D") == 500);
    REQUIRE(romano_para_decimal("M") == 1000);
}

TEST_CASE("Romano seguido por um romano menor", "[romanos]") {
    REQUIRE(romano_para_decimal("III") == 3);
    REQUIRE(romano_para_decimal("DLXXVIII") == 578);
    REQUIRE(romano_para_decimal("XI") == 11);
    REQUIRE(romano_para_decimal("XXIII") == 23);
    REQUIRE(romano_para_decimal("CCCVII") == 307);
    REQUIRE(romano_para_decimal("MMCCXXVI") == 2226);
}

TEST_CASE("Romano seguido por dois romanos menores", "[romanos]") {
    REQUIRE(romano_para_decimal("VI") == 6);
    REQUIRE(romano_para_decimal("LXII") == 62);
    REQUIRE(romano_para_decimal("XCV") == 95);
    REQUIRE(romano_para_decimal("CCXL") == 240);
    REQUIRE(romano_para_decimal("MDX") == 1510);
}

TEST_CASE("Romano seguido por três romanos menores", "[romanos]") {
    REQUIRE(romano_para_decimal("VII") == 7);
    REQUIRE(romano_para_decimal("XXXIX") == 39);
    REQUIRE(romano_para_decimal("CCL") == 250);
    REQUIRE(romano_para_decimal("MDCCC") == 1800);
}



TEST_CASE("Romano seguido por um romano maior", "[romanos]") {
    REQUIRE(romano_para_decimal("IV") == 4);
    REQUIRE(romano_para_decimal("DLXXIX") == 579);
    REQUIRE(romano_para_decimal("XIX") == 19);
    REQUIRE(romano_para_decimal("XL") == 40);
    REQUIRE(romano_para_decimal("CDLIV") == 454);
    REQUIRE(romano_para_decimal("CMXLII") == 942);
}

TEST_CASE("Romano seguido por dois romanos maiores", "[romanos]") {
    REQUIRE(romano_para_decimal("IX") == 9);
    REQUIRE(romano_para_decimal("LXXIV") == 74);
    REQUIRE(romano_para_decimal("XC") == 90);
    REQUIRE(romano_para_decimal("CDXC") == 490);
    REQUIRE(romano_para_decimal("CMXC") == 990);
}


TEST_CASE("Romano seguido por três romanos maiores", "[romanos]") {
    REQUIRE(romano_para_decimal("XIV") == 14);
    REQUIRE(romano_para_decimal("LXXXVIII") == 88);
    REQUIRE(romano_para_decimal("DCCC") == 800);
    REQUIRE(romano_para_decimal("MMCM") == 2900);
}

TEST_CASE("Entradas invalidas", "[romanos]") {
    REQUIRE(romano_para_decimal(".") == -1);
    REQUIRE(romano_para_decimal("12") == -1);
    REQUIRE(romano_para_decimal("") == -1);
    REQUIRE(romano_para_decimal("XLC") == -1);
    REQUIRE(romano_para_decimal("@") == -1);
    REQUIRE(romano_para_decimal("PQ") == -1);
    REQUIRE(romano_para_decimal("VIX") == -1); 
    REQUIRE(romano_para_decimal("IX?") == -1); 
    REQUIRE(romano_para_decimal("V@II") == -1); 
    REQUIRE(romano_para_decimal("X!II") == -1); 
    REQUIRE(romano_para_decimal("CDIVX") == -1); 
}

TEST_CASE("Romano com repetições inválidas", "[romanos]") {
    REQUIRE(romano_para_decimal("VV") == -1); 
    REQUIRE(romano_para_decimal("CCCC") == -1); 
    REQUIRE(romano_para_decimal("IIII") == -1);
    REQUIRE(romano_para_decimal("MDDDC") == -1);
    REQUIRE(romano_para_decimal("XXXX") == -1);
}


