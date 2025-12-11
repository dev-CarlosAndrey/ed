#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "utils.h" 

Prato* topo = NULL;

void receberPrato() {
    Prato* novo = (Prato*)malloc(sizeof(Prato));

    printf("\nID do tipo do prato: ");
    scanf("%d", &novo->id_tipo);
    limparBuffer();

    printf("Cor do prato: ");
    fgets(novo->cor, sizeof(novo->cor), stdin);
    limparEnter(novo->cor);

    novo->prox = topo;
    topo = novo;

    printf("Prato sujo adicionado ao topo.\n");
}

void lavarPrato() {
    if (topo == NULL) {
        printf("\nNenhum prato para lavar.\n");
        return;
    }

    Prato* temp = topo;

    printf("\nLavando prato %d (%s)\n", temp->id_tipo, temp->cor);

    topo = topo->prox;
    free(temp);
}

void verTopo() {
    if (topo == NULL) {
        printf("\nPilha vazia.\n");
        return;
    }

    printf("\nTopo -> Tipo: %d | Cor: %s\n",
           topo->id_tipo, topo->cor);
}
