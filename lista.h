#ifndef LISTA_H
#define LISTA_H

typedef struct Insumo {
    char nome[50];
    int quantidade;
    struct Insumo *prox;
} Insumo;

void adicionarInsumo();
void removerInsumo();
void listarInsumos();

#endif
