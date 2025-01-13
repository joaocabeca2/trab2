#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "conta_palavras.h"

// Função para ler o conteúdo de um arquivo
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

// Função para contar palavras únicas no texto
int count_unique_words(const char *text, WordCount words[]) {
    if (text == NULL || strlen(text) == 0) {
        return 0; // Nenhuma palavra
    }

    int num_words = 0;
    char buffer[50]; // Buffer para armazenar palavras temporariamente
    int index = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isspace(text[i])) {
            if (index > 0) {
                buffer[index] = '\0';
                index = 0;

                // Verifica se a palavra já está no array
                int found = 0;
                for (int j = 0; j < num_words; j++) {
                    if (strcmp(words[j].word, buffer) == 0) {
                        words[j].count++;
                        found = 1;
                        break;
                    }
                }

                // Se não foi encontrada, adiciona uma nova entrada
                if (!found) {
                    strcpy(words[num_words].word, buffer);
                    words[num_words].count = 1;
                    num_words++;
                }
            }
        } else {
            buffer[index++] = text[i];
        }
    }

    // Processa a última palavra, se existir
    if (index > 0) {
        buffer[index] = '\0';
        int found = 0;
        for (int j = 0; j < num_words; j++) {
            if (strcmp(words[j].word, buffer) == 0) {
                words[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[num_words].word, buffer);
            words[num_words].count = 1;
            num_words++;
        }
    }

    return num_words;
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

// Função para imprimir palavras e suas contagens
void print_word_counts(WordCount words[], int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}
