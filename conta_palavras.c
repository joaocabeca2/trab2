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
