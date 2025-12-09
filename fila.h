#ifndef FILA_H
#define FILA_H

typedef struct Pedido {
    int id;
    char prato[50];
    int mesa;
    struct Pedido *prox;
} Pedido;

void adicionarPedido();
void entregarPedido();
void listarPedidos();

#endif
