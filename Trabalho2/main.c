#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

EstruturaAuxiliar principal[10];

void inicializarEstruturas();
void criarEstruturaAuxiliar(EstruturaAuxiliar principal[10], int posicao, int tamanho);
void inserirElemento(EstruturaAuxiliar principal[10], int posicao, int valor);
void listarEstruturas(EstruturaAuxiliar principal[10]);
void excluirElemento(EstruturaAuxiliar principal[10], int posicao, int valor);
void aumentarEstruturaAuxiliar(EstruturaAuxiliar principal[10], int posicao, int tamanhoExtra);

int main() {
    int opcao, posicao, tamanho, valor, tamanhoExtra;
    inicializarEstruturas(principal);

    do {
        printf("\nMenu:\n");
        printf("1. Criar estrutura auxiliar\n");
        printf("2. Inserir elemento\n");
        printf("3. Listar estruturas\n");
        printf("4. Excluir elemento\n");
        printf("5. Aumentar tamanho da estrutura auxiliar\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Informe a posicao (1 a 10): ");
                scanf("%d", &posicao);
                printf("Informe o tamanho da estrutura auxiliar: ");
                scanf("%d", &tamanho);
                criarEstruturaAuxiliar(principal, posicao, tamanho);
                break;
            case 2:
                printf("Informe a posicao (1 a 10): ");
                scanf("%d", &posicao);
                printf("Informe o valor a inserir: ");
                scanf("%d", &valor);
                inserirElemento(principal, posicao, valor);
                break;
            case 3:
                listarEstruturas(principal);
                break;
            case 4:
                printf("Informe a posicao (1 a 10): ");
                scanf("%d", &posicao);
                printf("Informe o valor a excluir: ");
                scanf("%d", &valor);
                excluirElemento(principal, posicao, valor);
                break;
            case 5:
                printf("Informe a posicao (1 a 10): ");
                scanf("%d", &posicao);
                printf("Informe o tamanho extra a adicionar: ");
                scanf("%d", &tamanhoExtra);
                aumentarEstruturaAuxiliar(principal, posicao, tamanhoExtra);
                break;
            case 6:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 6);

    return 0;
}
