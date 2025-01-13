#include <stdio.h>
#include "conta_palavras.h"

char* read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL; // Retorna NULL se o arquivo não puder ser aberto
    }

    static char content[1024]; // Buffer fixo para armazenar o conteúdo
    size_t n = fread(content, 1, sizeof(content) - 1, file); // Lê o arquivo
    content[n] = '\0'; // Adiciona o terminador de string

    fclose(file);
    return content; // Retorna o conteúdo lido
}

// Conta o número de palavras em uma string
int count_words(const char *text) {
    if (text == NULL || strlen(text) == 0) {
        return 0; // Nenhuma palavra
    }

    int count = 0;
    int in_word = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isspace(text[i])) {
            in_word = 0; // Fora de uma palavra
        } else if (!in_word) {
            in_word = 1; // Entrou em uma palavra
            count++;
        }
    }
    return count; // Retorna o número de palavras
}
