#include <stdio.h>
#include <assert.h>
#include "conta_palavras.h"

int main() {
    // Teste: Abrir arquivo válido
    assert(read_file("teste.txt") == 0);

    // Teste: Abrir arquivo inexistente
    assert(read_file("inexistente.txt") == -1);

    printf("Teste de leitura do arquivo: OK\n");
    return 0;
}
