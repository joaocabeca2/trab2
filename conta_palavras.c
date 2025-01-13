#include <stdio.h>
#include "conta_palavras.h"


// Estrutura para armazenar palavras e suas ocorrências
typedef struct {
    char word[50]; 
    int count;   
} WordCount;

char* read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL; // Retorna NULL se o arquivo não puder ser aberto
    }

    static char content[1024]; // Buffer fixo para armazenar o conteúdo
    size_t n = fread(content, 1, sizeof(content) - 1, file);
    content[n] = '\0'; // Adiciona o terminador de string

    fclose(file);
    return content; 
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
            in_word = 0; 
        } else if (!in_word) {
            in_word = 1; 
            count++;
        }
    }
    return count; 
}

// Função para ordenar palavras em ordem alfabética
void sort_words(WordCount words[], int num_words) {
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(words[i].word, words[j].word) > 0) {
                WordCount temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}
