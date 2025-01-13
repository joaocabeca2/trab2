#ifndef CONTA_PALAVRAS_H
#define CONTA_PALAVRAS_H

// Estrutura para armazenar palavras e suas ocorrências
typedef struct {
    char word[50]; 
    int count;    
} WordCount;

// Funções declaradas
char* read_file(const char *filename);
int count_unique_words(const char *text,  WordCount words[]);
void sort_words(WordCount words[], int num_words);
void print_word_counts(WordCount words[], int num_words);

#endif