#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

// Protótipos das funções do funcoes.c
void inicializarEstruturas();
void criarEstruturaAuxiliar(int posicao, int tamanho);
void inserirElemento(int posicao, int valor);
void listarEstruturas();
void excluirElemento(int posicao, int valor);

int main() {
    int opcao, posicao, tamanho, valor;

    inicializarEstruturas();

    do {
        printf("\nMenu:\n");
        printf("1. Criar estrutura auxiliar\n");
        printf("2. Inserir elemento\n");
        printf("3. Listar estruturas\n");
        printf("4. Excluir elemento\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Informe a posicao (1 a 10): ");
                scanf("%d", &posicao);
                printf("Informe o tamanho da estrutura auxiliar: ");
                scanf("%d", &tamanho);
                criarEstruturaAuxiliar(posicao, tamanho);
                break;

            case 2:
                printf("Informe a posicao (1 a 10): ");
                scanf("%d", &posicao);
                printf("Informe o valor a inserir: ");
                scanf("%d", &valor);
                inserirElemento(posicao, valor);
                break;

            case 3:
                listarEstruturas();
                break;

            case 4:
                printf("Informe a posicao (1 a 10): ");
                scanf("%d", &posicao);
                printf("Informe o valor a excluir: ");
                scanf("%d", &valor);
                excluirElemento(posicao, valor);
                break;

            case 5:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}
