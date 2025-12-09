#include <stdio.h>
#include <stdlib.h>

#include "fila.h"
#include "pilha.h"
#include "lista.h"

int main() {
    int opcao;

    while (1) {
        printf("\n***********************\n");
        printf("*** RESTAURANTE FPO ***\n");
        printf("***********************\n");

        printf("(1) Adicionar Pedido (Fila)\n");
        printf("(2) Entregar Pedido (Fila)\n");
        printf("(3) Receber Prato Sujo (Pilha)\n");
        printf"(4) Lavar Prato (Pilha)\n");
        printf"(5) Adicionar Insumo (Lista)\n");
        printf"(6) Remover Insumo (Lista)\n");
        printf"(7) Imprimir Pedidos\n");
        printf"(8) Ver Pilha de Pratos\n");
        printf"(9) Imprimir Lista de Ingredientes\n");
        printf"(0) Sair\n");

        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: adicionarPedido(); break;
            case 2: entregarPedido(); break;
            case 3: receberPrato(); break;
            case 4: lavarPrato(); break;
            case 5: adicionarInsumo(); break;
            case 6: removerInsumo(); break;
            case 7: listarPedidos(); break;
            case 8: verTopo(); break;
            case 9: listarInsumos(); break;
            case 0: exit(0);
            default: printf("Opção inválida!\n");
        }
    }

    return 0;
}
