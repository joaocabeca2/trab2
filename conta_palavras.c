#include <stdio.h>
#include "conta_palavras.h"

int read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }
    fclose(file);
    return 0;
}
