#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "conta_palavras.h"

#define MAX_WORDS 1000 // Limite de palavras únicas
int main() {
    // Teste: Abrir arquivo válido
    char *content = read_file("teste.txt");
    WordCount words[MAX_WORDS];

    assert(content != NULL);
    printf("Teste de leitura do arquivo: OK\n");

    //Teste arquivo vazio
    assert(strlen(content) != 0);
    printf("Teste de arquivo vazio: OK\n");

    //Teste para verificar se há mais de um espaçamento
    assert(contains_extra_spaces(content) == 0);
    printf("Teste de espaçamento: OK\n");

    // Testa a contagem de palavras no conteúdo lido
    int num_words = count_unique_words(content, words);

    assert(num_words == 7);
    printf("Teste de contagem de palavras no arquivo: OK\n");

    // Teste: Texto vazio
    assert(num_words != 0);
    printf("Texto texto em branco: OK\n");

    //Testa a ordenação das palavras
    sort_words(words, num_words);
    assert(strcmp(words[0].word, "é") == 0); 
    assert(strcmp(words[1].word, "Este") == 0);
    assert(strcmp(words[2].word, "o") == 0);
    assert(strcmp(words[3].word, "que") == 0);
    assert(strcmp(words[4].word, "será") == 0);
    assert(strcmp(words[5].word, "texto") == 0);
    assert(strcmp(words[6].word, "utilizado") == 0);
    printf("Teste da ordenacao das palavras: OK\n");

    // Testa a impressão (saída manual)
    printf("Resultado esperado para print_word_counts:\n");
    print_word_counts(words, num_words); 

    return 0;
}
