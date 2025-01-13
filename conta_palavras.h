#ifndef CONTA_PALAVRAS_H
#define CONTA_PALAVRAS_H

// Definição da estrutura WordCount
typedef struct {
    char word[50]; 
    int count;     
} WordCount;

char* read_file(const char *filename);

// Conta o número de palavras em uma string
int count_words(const char *text);

void sort_words(WordCount words[], int num_words);

void print_word_counts(WordCount words[], int num_words);

#endif
