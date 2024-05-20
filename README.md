# O problema das 8 rainhas

Este é o Trabalho 2 da disciplina de Métodos de Programação, um simulador do "problema das 8 rainhas". O projeto está escrito em C++ e é desenvolvido orientado a testes (TDD)

## Requisitos

- Compilador C++ (utilizamos o g++)
- Make/Catch2


## Compilar

- Para rodar os testes, basta digitar no terminal:
    ```bash
       make test

## comandos úteis

- Para limpar os arquivos gerados durante o processo de compilação:
    ```bash
       make clean

- Para rodar o gcov:
    ```bash
       make gcov

- Executar o programa para coletar dados de cobertura:
    ```bash
       ./testa_rainha

- Gerar os reletórios de cobertura de código:
    ```bash
    gcov rainha.cpp testa_rainha.cpp


