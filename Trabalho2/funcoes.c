#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

// Definição da estrutura principal
EstruturaAuxiliar principal[10];

// Inicializa as estruturas principais
void inicializarEstruturas() {
    for (int i = 0; i < 10; i++) {
        principal[i].valores = NULL;
        principal[i].tamanho = 0;
        principal[i].ocupados = 0;
    }
}

// Função para criar uma estrutura auxiliar
void criarEstruturaAuxiliar(int posicao, int tamanho) {
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

// Função para inserir elemento em uma estrutura auxiliar
void inserirElemento(int posicao, int valor) {
    if (posicao < 1 || posicao > 10) {
        printf("Posição inválida!\n");
        return;
    }

    EstruturaAuxiliar *aux = &principal[posicao - 1];

    if (aux->valores == NULL) {
        printf("Estrutura auxiliar não existe nesta posição!\n");
        return;
    }

    if (aux->ocupados >= aux->tamanho) {
        printf("Estrutura auxiliar está cheia!\n");
        return;
    }

    aux->valores[aux->ocupados] = valor;
    aux->ocupados++;
    printf("Elemento inserido com sucesso!\n");
}

// Função para excluir um elemento de uma estrutura auxiliar
void excluirElemento(int posicao, int valor) {
    if (posicao < 1 || posicao > 10) {
        printf("Posição inválida!\n");
        return;
    }

    EstruturaAuxiliar *aux = &principal[posicao - 1];

    if (aux->valores == NULL) {
        printf("Estrutura auxiliar não existe nesta posição!\n");
        return;
    }

    // Procura a primeira ocorrência do valor na estrutura auxiliar
    for (int i = 0; i < aux->ocupados; i++) {
        if (aux->valores[i] == valor) {
            aux->valores[i] = 0; // Marca a posição como "vaga" com 0
            printf("Elemento %d excluído com sucesso!\n", valor);
            return;
        }
    }

    printf("Elemento %d não encontrado na estrutura auxiliar.\n", valor);
}

// Função para listar todas as estruturas
void listarEstruturas() {
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
