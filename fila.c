#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

static Pedido* inicioFila = NULL;
static Pedido* fimFila = NULL;

static int proximoID = 1;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void adicionarPedido() {
    Pedido* novo = (Pedido*)malloc(sizeof(Pedido));
    if (!novo) {
        printf("Erro: memória insuficiente.\n");
        return;
    }

    novo->id = proximoID++;
    printf("\nID: %d\n", novo->id);

    // Leitura do nome do prato com fgets  
    limparBuffer(); // evita pular a leitura
    printf("Nome do prato: ");
    fgets(novo->prato, sizeof(novo->prato), stdin);

    // Remove o \n do final da string
    novo->prato[strcspn(novo->prato, "\n")] = '\0';

    // Ler número da mesa
    printf("Mesa: ");
    scanf("%d", &novo->mesa);

    novo->prox = NULL;

    // Inserir na fila
    if (inicioFila == NULL) {
        inicioFila = fimFila = novo;
    } else {
        fimFila->prox = novo;
        fimFila = novo;
    }

    printf("Pedido adicionado com sucesso!\n");
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
