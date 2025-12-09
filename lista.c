#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

Insumo* lista = NULL;

void adicionarInsumo() {
    Insumo* novo = (Insumo*)malloc(sizeof(Insumo));

    printf("\nNome do insumo: ");
    scanf(" %[^\n]", novo->nome);

    printf("Quantidade: ");
    scanf("%d", &novo->quantidade);

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

    int pos;
    printf("\nPosição a remover: ");
    scanf("%d", &pos);

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
