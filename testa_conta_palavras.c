#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "conta_palavras.h"

#define MAX_WORDS 1000 // Limite de palavras únicas
int main() {
    // Teste: Abrir arquivo válido
    char *content = read_file("teste.txt");
    assert(content != NULL);

    printf("Teste de leitura do arquivo: OK\n");

    // Testa a contagem de palavras no conteúdo lido
    WordCount words[MAX_WORDS];
    int num_words = count_unique_words(content, words);
    assert(num_words == 7);

    printf("Teste de contagem de palavras no arquivo: OK\n");

    // Testa a ordenação das palavras
    printf(words);
    sort_words(words, num_words);
    assert(strcmp(words[0].word, "é") == 0); 
    assert(strcmp(words[1].word, "este") == 0);
    printf("Teste da ordenacao das palavras: OK\n");

    return 0;
}
