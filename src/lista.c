#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "utils.h"

Insumo* lista = NULL;

void adicionarInsumo() {
    Insumo* novo = (Insumo*)malloc(sizeof(Insumo));

    limparBuffer();

    printf("\nNome do insumo: ");
    fgets(novo->nome, sizeof(novo->nome), stdin);
    limparEnter(novo->nome);

    printf("Quantidade: ");
    scanf("%d", &novo->quantidade);
    limparBuffer();

    novo->prox = NULL;

    if (lista == NULL) {
        lista = novo;
    } else {
        Insumo* aux = lista;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }

    printf("Insumo adicionado!\n");
}

void removerInsumo() {
    if (lista == NULL) {
        printf("\nLista vazia.\n");
        return;
    }

    // Mostrar a lista numerada antes de remover
    printf("\n--- INSUMOS (com posições) ---\n");
    Insumo* auxList = lista;
    int index = 1;

    while (auxList != NULL) {
        printf("%d) Nome: %s | Quantidade: %d\n",
               index, auxList->nome, auxList->quantidade);
        auxList = auxList->prox;
        index++;
    }

    int pos;
    printf("\nDigite a posição a remover: ");
    scanf("%d", &pos);
    limparBuffer();

    if (pos == 1) {
        Insumo* temp = lista;
        lista = lista->prox;
        free(temp);
        printf("Insumo removido!\n");
        return;
    }

    Insumo* aux = lista;
    for (int i = 1; i < pos - 1 && aux->prox != NULL; i++) {
        aux = aux->prox;
    }

    if (aux->prox == NULL) {
        printf("Posição inválida!\n");
        return;
    }

    Insumo* temp = aux->prox;
    aux->prox = temp->prox;
    free(temp);

    printf("Insumo removido!\n");
}


void listarInsumos() {
    if (lista == NULL) {
        printf("\nNenhum insumo.\n");
        return;
    }

    printf("\n--- LISTA DE INSUMOS ---\n");
    Insumo* aux = lista;

    while (aux != NULL) {
        printf("Nome: %s | Quantidade: %d\n",
               aux->nome, aux->quantidade);
        aux = aux->prox;
    }
}
