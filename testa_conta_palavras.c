#include <stdio.h>
#include <assert.h>
#include "conta_palavras.h"

int main() {
    // Teste: Abrir arquivo válido
    assert(read_file("teste.txt") != NULL);

    printf("Teste de leitura do arquivo: OK\n");

    // Testa a contagem de palavras no conteúdo lido
    assert(count_words(read_file("teste.txt")) == 8);

    printf("Teste de contagem de palavras no arquivo: OK\n");
    return 0;
}
