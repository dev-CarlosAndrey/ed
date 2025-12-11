#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "utils.h"

static Pedido* inicioFila = NULL;
static Pedido* fimFila = NULL;
static int proximoID = 1;

void adicionarPedido() {
    Pedido* novo = malloc(sizeof(Pedido));
    if (!novo) {
        printf("Erro: memória insuficiente.\n");
        return;
    }

    novo->id = proximoID++;
    printf("\nID: %d\n", novo->id);

    limparBuffer();

    printf("Nome do prato: ");
    fgets(novo->prato, sizeof(novo->prato), stdin);
    limparEnter(novo->prato);

    printf("Mesa: ");
    scanf("%d", &novo->mesa);

    novo->prox = NULL;

    if (inicioFila == NULL) {
        inicioFila = fimFila = novo;
    } else {
        fimFila->prox = novo;
        fimFila = novo;
    }

    printf("Pedido adicionado com sucesso!\n");
}

void entregarPedido() {
    if (!inicioFila) {
        printf("\nNenhum pedido na fila.\n");
        return;
    }

    Pedido* temp = inicioFila;
    printf("\nPedido entregue: ID %d - %s (Mesa %d)\n",
           temp->id, temp->prato, temp->mesa);

    inicioFila = inicioFila->prox;
    free(temp);

    if (!inicioFila)
        fimFila = NULL;
}

void listarPedidos() {
    if (!inicioFila) {
        printf("\nFila vazia.\n");
        return;
    }

    Pedido* aux = inicioFila;
    printf("\n--- FILA DE PEDIDOS ---\n");

    while (aux != NULL) {
        printf("ID: %d | Prato: %s | Mesa: %d\n",
               aux->id, aux->prato, aux->mesa);
        aux = aux->prox;
    }
}
