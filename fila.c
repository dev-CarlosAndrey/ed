#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

Pedido* inicioFila = NULL;
Pedido* fimFila = NULL;

void adicionarPedido() {
    Pedido* novo = (Pedido*)malloc(sizeof(Pedido));

    printf("\nID do Pedido: ");
    scanf("%d", &novo->id);

    printf("Nome do prato: ");
    scanf(" %[^\n]", novo->prato);

    printf("Mesa: ");
    scanf("%d", &novo->mesa);

    novo->prox = NULL;

    if (inicioFila == NULL) {
        inicioFila = fimFila = novo;
    } else {
        fimFila->prox = novo;
        fimFila = novo;
    }

    printf("Pedido adicionado!\n");
}

void entregarPedido() {
    if (inicioFila == NULL) {
        printf("\nNenhum pedido na fila.\n");
        return;
    }

    Pedido* temp = inicioFila;
    printf("\nPedido entregue: ID %d - %s (Mesa %d)\n",
           temp->id, temp->prato, temp->mesa);

    inicioFila = inicioFila->prox;
    free(temp);

    if (inicioFila == NULL)
        fimFila = NULL;
}

void listarPedidos() {
    if (inicioFila == NULL) {
        printf("\nFila vazia.\n");
        return;
    }

    printf("\n--- FILA DE PEDIDOS ---\n");
    Pedido* aux = inicioFila;

    while (aux != NULL) {
        printf("ID: %d | Prato: %s | Mesa: %d\n",
               aux->id, aux->prato, aux->mesa);
        aux = aux->prox;
    }
}
