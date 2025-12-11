#include <stdio.h>
#include <string.h>
#include "utils.h"

void limparEnter(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
