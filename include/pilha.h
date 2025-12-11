#ifndef PILHA_H
#define PILHA_H

typedef struct Prato {
    int id_tipo;
    char cor[20];
    struct Prato *prox;
} Prato;

void receberPrato();
void lavarPrato();
void verTopo();

#endif
