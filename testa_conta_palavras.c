#include <stdio.h>
#include <assert.h>
#include "conta_palavras.h"

int main() {
    // Teste: Abrir arquivo válido
    assert(read_file("teste.txt") != NULL);

    printf("Teste de leitura do arquivo: OK\n");
    return 0;
}
