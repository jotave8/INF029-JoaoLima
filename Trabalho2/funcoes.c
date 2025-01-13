#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void inicializarEstruturas(EstruturaAuxiliar principal[10]) {
    for (int i = 0; i < 10; i++) {
        principal[i].valores = NULL;
        principal[i].tamanho = 0;
        principal[i].ocupados = 0;
    }
}

void criarEstruturaAuxiliar(EstruturaAuxiliar principal[10], int posicao, int tamanho) {
    if (posicao < 1 || posicao > 10) {
        printf("Posição inválida!\n");
        return;
    }
    if (principal[posicao - 1].valores != NULL) {
        printf("Estrutura auxiliar já existe nesta posição!\n");
        return;
    }
    principal[posicao - 1].valores = (int *)malloc(tamanho * sizeof(int));
    if (principal[posicao - 1].valores == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    principal[posicao - 1].tamanho = tamanho;
    principal[posicao - 1].ocupados = 0;
    printf("Estrutura auxiliar criada com sucesso!\n");
}

void inserirElemento(EstruturaAuxiliar principal[10], int posicao, int valor) {
    if (posicao < 1 || posicao > 10) {
        printf("Posição inválida!\n");
        return;
    }

    EstruturaAuxiliar *aux = &principal[posicao - 1];
    if (aux->valores == NULL) {
        int tamanho;
        printf("Estrutura auxiliar não existe nesta posição. Informe o tamanho: ");
        scanf("%d", &tamanho);
        if (tamanho <= 0) {
            printf("Tamanho inválido!\n");
            return;
        }
        criarEstruturaAuxiliar(principal, posicao, tamanho);
        aux = &principal[posicao - 1];
    }
    if (aux->ocupados >= aux->tamanho) {
        printf("Estrutura auxiliar está cheia!\n");
        return;
    }

    aux->valores[aux->ocupados] = valor;
    aux->ocupados++;
    printf("Elemento inserido com sucesso!\n");
    for (int i = 1; i < aux->ocupados; i++) {
        int chave = aux->valores[i];
        int j = i - 1;
        while (j >= 0 && aux->valores[j] > chave) {
            aux->valores[j + 1] = aux->valores[j];
            j--;
        }
        aux->valores[j + 1] = chave;
    }
}

void aumentarEstruturaAuxiliar(EstruturaAuxiliar principal[10], int posicao, int tamanhoExtra) {
    if (posicao < 1 || posicao > 10) {
        printf("Posição inválida!\n");
        return;
    }
    EstruturaAuxiliar *aux = &principal[posicao - 1];
    if (aux->valores == NULL) {
        printf("Estrutura auxiliar não existe nesta posição!\n");
        return;
    }
    if (tamanhoExtra <= 0) {
        printf("Tamanho extra inválido!\n");
        return;
    }
    int novoTamanho = aux->tamanho + tamanhoExtra;
    int *novoArray = (int *)realloc(aux->valores, novoTamanho * sizeof(int));
    if (novoArray == NULL) {
        printf("Erro ao realocar memória!\n");
        return;
    }

    aux->valores = novoArray;
    aux->tamanho = novoTamanho;
    printf("Estrutura auxiliar aumentada para %d posições!\n", novoTamanho);
}

void excluirElemento(EstruturaAuxiliar principal[10], int posicao, int valor) {
    if (posicao < 1 || posicao > 10) {
        printf("Posição inválida!\n");
        return;
    }

    EstruturaAuxiliar *aux = &principal[posicao - 1];

    if (aux->valores == NULL) {
        printf("Estrutura auxiliar não existe nesta posição!\n");
        return;
    }

    for (int i = 0; i < aux->ocupados; i++) {
        if (aux->valores[i] == valor) {
            for (int j = i; j < aux->ocupados - 1; j++) {
                aux->valores[j] = aux->valores[j + 1];
            }
            aux->ocupados--;
            printf("Elemento %d excluído com sucesso!\n", valor);
            return;
        }
    }

    printf("Elemento %d não encontrado na estrutura auxiliar.\n", valor);
}

void listarEstruturas(EstruturaAuxiliar principal[10]) {
    for (int i = 0; i < 10; i++) {
        printf("Posição %d: ", i + 1);
        if (principal[i].valores == NULL) {
            printf("Estrutura não criada\n");
        } else {
            printf("Tamanho: %d, Ocupados: %d, Elementos: ", 
                   principal[i].tamanho, principal[i].ocupados);
            for (int j = 0; j < principal[i].ocupados; j++) {
                printf("%d ", principal[i].valores[j]);
            }
            printf("\n");
        }
    }
}
