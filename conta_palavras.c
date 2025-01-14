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
    char no_accents_i[50], no_accents_j[50];
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            // Remove os acentos das palavras antes de comparar
            remove_accents(words[i].word, no_accents_i);
            remove_accents(words[j].word, no_accents_j);
            if (strcmp(no_accents_i, no_accents_j) > 0) {
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

int contains_extra_spaces(const char *text) {
    if (text == NULL) return 0; 

    int has_extra_spaces = 0;
    int in_space_sequence = 0; 
    size_t length = strlen(text);

    for (size_t i = 0; i < length; i++) {
        if (text[i] == ' ') {
            if (in_space_sequence) {
                has_extra_spaces = 1; 
                break;
            }
            in_space_sequence = 1; 
        } else if (text[i] == '\n') {
            if (i > 0 && text[i - 1] == ' ') {
                has_extra_spaces = 1; 
                break;
            }
            in_space_sequence = 0; 
        } else {
            in_space_sequence = 0; 
        }
    }

    // Verifica se o texto termina com espaço
    if (length > 0 && text[length - 1] == ' ') {
        has_extra_spaces = 1;
    }

    return has_extra_spaces;
}

// Função para remover acentos de uma palavra
void remove_accents(const char* input, char* output) {
    int i = 0, j = 0;
    while (input[i] != '\0') {
        unsigned char c = input[i];
        if (c >= 192 && c <= 255) { // Acentos comuns em caracteres UTF-8
            if (c == 192 || c == 193 || c == 194 || c == 195 || c == 196 || c == 197 || c == 198) c = 'A';
            else if (c == 199) c = 'C';
            else if (c == 200 || c == 201 || c == 202 || c == 203) c = 'E';
            else if (c == 204 || c == 205 || c == 206 || c == 207) c = 'I';
            else if (c == 208) c = 'D';
            else if (c == 209) c = 'N';
            else if (c == 210 || c == 211 || c == 212 || c == 213 || c == 214 || c == 216) c = 'O';
            else if (c == 217 || c == 218 || c == 219 || c == 220) c = 'U';
            else if (c == 221 || c == 222) c = 'Y';
            else if (c == 223) c = 's';
            else if (c == 224 || c == 225 || c == 226 || c == 227 || c == 228 || c == 229 || c == 230) c = 'a';
            else if (c == 231) c = 'c';
            else if (c == 232 || c == 233 || c == 234 || c == 235) c = 'e';
            else if (c == 236 || c == 237 || c == 238 || c == 239) c = 'i';
            else if (c == 240) c = 'd';
            else if (c == 241) c = 'n';
            else if (c == 242 || c == 243 || c == 244 || c == 245 || c == 246 || c == 248) c = 'o';
            else if (c == 249 || c == 250 || c == 251 || c == 252) c = 'u';
            else if (c == 253 || c == 255) c = 'y';
        }
        output[j++] = c;
        i++;
    }
    output[j] = '\0';
}