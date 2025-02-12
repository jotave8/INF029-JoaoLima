#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EstruturaVetores.h"

EstruturaAuxiliar vetorPrincipal[TAM];

void inicializar() {
    for (int i = 0; i < TAM; i++) {
        vetorPrincipal[i].vetor = NULL;
        vetorPrincipal[i].tamanho = 0;
        vetorPrincipal[i].quantidade = 0;
    }
    carregarDados();
}

void finalizar() {
    salvarDados();
    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i].vetor != NULL) {
            free(vetorPrincipal[i].vetor);
            vetorPrincipal[i].vetor = NULL;
        }
    }
}

int ehPosicaoValida(int posicao) {
    if (posicao < 1 || posicao > TAM)
        return POSICAO_INVALIDA;
    return SUCESSO;
}

int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void dobrar(int *x) {
    *x *= 2;
}

int criarEstruturaAuxiliar(int posicao, int tamanho) {
    if (ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;

    if (tamanho <= 0)
        return TAMANHO_INVALIDO;

    posicao--;
    if (vetorPrincipal[posicao].vetor != NULL)
        return JA_TEM_ESTRUTURA_AUXILIAR;

    vetorPrincipal[posicao].vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetorPrincipal[posicao].vetor == NULL)
        return SEM_ESPACO_DE_MEMORIA;

    vetorPrincipal[posicao].tamanho = tamanho;
    vetorPrincipal[posicao].quantidade = 0;
    return SUCESSO;
}

int inserirNumeroEmEstrutura(int posicao, int valor) {
    if (ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;

    posicao--;
    if (vetorPrincipal[posicao].vetor == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetorPrincipal[posicao].quantidade >= vetorPrincipal[posicao].tamanho)
        return SEM_ESPACO;

    vetorPrincipal[posicao].vetor[vetorPrincipal[posicao].quantidade++] = valor;
    return SUCESSO;
}

int excluirNumeroDoFinaldaEstrutura(int posicao) {
    if (ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;

    posicao--;
    if (vetorPrincipal[posicao].vetor == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetorPrincipal[posicao].quantidade == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    vetorPrincipal[posicao].quantidade--;
    return SUCESSO;
}

int excluirNumeroEspecificoDeEstrutura(int posicao, int valor) {
    if (ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;

    posicao--;

    if (vetorPrincipal[posicao].vetor == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    int i, encontrou = 0;
    for (i = 0; i < vetorPrincipal[posicao].quantidade; i++) {
        if (vetorPrincipal[posicao].vetor[i] == valor) {
            encontrou = 1;
            break;
        }
    }
    if (!encontrou)
        return NUMERO_INEXISTENTE;

    for (; i < vetorPrincipal[posicao].quantidade - 1; i++) {
        vetorPrincipal[posicao].vetor[i] = vetorPrincipal[posicao].vetor[i + 1];
    }
    vetorPrincipal[posicao].quantidade--;
    return SUCESSO;
}

int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho) {
    if (ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;

    posicao--;
    if (vetorPrincipal[posicao].vetor == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetorPrincipal[posicao].tamanho + novoTamanho < 1)
        return NOVO_TAMANHO_INVALIDO;

    int *novoVetor = (int *)realloc(vetorPrincipal[posicao].vetor, (vetorPrincipal[posicao].tamanho + novoTamanho) * sizeof(int));
    if (novoVetor == NULL)
        return SEM_ESPACO_DE_MEMORIA;

    vetorPrincipal[posicao].vetor = novoVetor;
    vetorPrincipal[posicao].tamanho += novoTamanho;
    if (vetorPrincipal[posicao].quantidade > vetorPrincipal[posicao].tamanho)
        vetorPrincipal[posicao].quantidade = vetorPrincipal[posicao].tamanho;

    return SUCESSO;
}

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
    if (ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;

    posicao--;
    if (vetorPrincipal[posicao].vetor == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetorPrincipal[posicao].quantidade == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    for (int i = 0; i < vetorPrincipal[posicao].quantidade; i++) {
        vetorAux[i] = vetorPrincipal[posicao].vetor[i];
    }
    return SUCESSO;
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
    int retorno;
    if (ehPosicaoValida(posicao) != SUCESSO) {
        retorno = POSICAO_INVALIDA;
    } else {
        posicao--;
        if (vetorPrincipal[posicao].vetor == NULL) {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        } else if (vetorPrincipal[posicao].quantidade == 0) {
            retorno = ESTRUTURA_AUXILIAR_VAZIA;
        } else {
            for (int i = 0; i < vetorPrincipal[posicao].quantidade; i++) {
                vetorAux[i] = vetorPrincipal[posicao].vetor[i];
            }
            qsort(vetorAux, vetorPrincipal[posicao].quantidade, sizeof(int), comparar);
            retorno = SUCESSO;
        }
    }
    return retorno;
}

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){
    int quantidadeTotal = 0;
    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i].vetor != NULL && vetorPrincipal[i].quantidade > 0) {
            for (int j = 0; j < vetorPrincipal[i].quantidade; j++) {
                vetorAux[quantidadeTotal++] = vetorPrincipal[i].vetor[j];
            }
        }
    }
    if (quantidadeTotal == 0) {
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    qsort(vetorAux, quantidadeTotal, sizeof(int), comparar);
    return SUCESSO;
}

int getQuantidadeElementosEstruturaAuxiliar(int posicao) {
    if (ehPosicaoValida(posicao) != SUCESSO) {
        return POSICAO_INVALIDA;
    }
    posicao--;
    if (vetorPrincipal[posicao].vetor == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }
    if (vetorPrincipal[posicao].quantidade == 0) {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }
    return vetorPrincipal[posicao].quantidade;
}

No *montarListaEncadeadaComCabecote() {
    No *cabecote = (No *)malloc(sizeof(No));
    if (cabecote == NULL) {
        return NULL;
    }
    cabecote->prox = NULL;
    No *ultimo = cabecote;
    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i].vetor != NULL && vetorPrincipal[i].quantidade > 0) {
            for (int j = 0; j < vetorPrincipal[i].quantidade; j++) {
                // Cria um novo nó para cada elemento
                No *novo = (No *)malloc(sizeof(No));
                if (novo == NULL) {
                    No *temp = cabecote->prox;
                    while (temp != NULL) {
                        No *prox = temp->prox;
                        free(temp);
                        temp = prox;
                    }
                    free(cabecote);
                    return NULL;
                }
                novo->conteudo = vetorPrincipal[i].vetor[j];
                novo->prox = NULL;
                ultimo->prox = novo;
                ultimo = novo;
            }
        }
    }
    return (cabecote->prox != NULL) ? cabecote : NULL;
}

void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]) {
    if (inicio == NULL) {
        return;
    }
    No *atual = inicio->prox;
    int i = 0;
    while (atual != NULL) {
        vetorAux[i++] = atual->conteudo;
        atual = atual->prox;
    }
}

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
    int quantidadeTotal = 0;
    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i].vetor != NULL && vetorPrincipal[i].quantidade > 0) {
            for (int j = 0; j < vetorPrincipal[i].quantidade; j++) {
                vetorAux[quantidadeTotal++] = vetorPrincipal[i].vetor[j];
            }
        }
    }
    if (quantidadeTotal == 0) {
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    return SUCESSO;
}

void destruirListaEncadeadaComCabecote(No **inicio) {
    No *atual = *inicio;
    No *temp;
    while (atual != NULL) {
        temp = atual;
        atual = atual->prox;
        free(temp);
    }
    *inicio = NULL;
}

void salvarDados() {
    FILE *arquivo = fopen("dados.txt", "w");
    if (!arquivo) {
        printf("Erro ao abrir arquivo para salvar os dados.\n");
        return;
    }
    for (int i = 0; i < TAM; i++) {
        int qtd = getQuantidadeElementosEstruturaAuxiliar(i);

        if (qtd > 0) { 
            int vetorAux[qtd];
            getDadosEstruturaAuxiliar(i, vetorAux);

            fprintf(arquivo, "Posição: %d   Elementos:", i); 
            for (int j = 0; j < qtd; j++) {
                fprintf(arquivo, " %d", vetorAux[j]);
            }
            fprintf(arquivo, "\n");
        }
    }
    fclose(arquivo);
}


void carregarDados() {
    FILE *arquivo = fopen("dados.txt", "r");
    if (!arquivo) {
        printf("Nenhum dado salvo encontrado. Inicializando estrutura vazia.\n");
        return;
    }

    int posicao, tamanho, qtd, valor;

    while (fscanf(arquivo, "Posição: %d   Elementos:", &posicao) == 1) {
        fscanf(arquivo, " %d", &tamanho);
        criarEstruturaAuxiliar(posicao + 1, tamanho);

        for (int i = 0; i < tamanho; i++) {
            fscanf(arquivo, " %d", &valor);
            inserirNumeroEmEstrutura(posicao + 1, valor);
        }
    }
    fclose(arquivo);
}
