#ifndef ESTRUTURAVETORES_H
#define ESTRUTURAVETORES_H
#include <stdlib.h>
#include <stdio.h>

enum { TODAS_ESTRUTURAS_AUXILIARES_VAZIAS = -11, NOVO_TAMANHO_INVALIDO, NUMERO_INEXISTENTE,
       ESTRUTURA_AUXILIAR_VAZIA, TAMANHO_INVALIDO, SEM_ESPACO_DE_MEMORIA, POSICAO_INVALIDA,
       JA_TEM_ESTRUTURA_AUXILIAR, SEM_ESTRUTURA_AUXILIAR, SEM_ESPACO, SUCESSO };

typedef struct {
    int *elementos;
    int tamanho;
    int capacidade;
} EstruturaAuxiliar;

typedef struct reg {
    int conteudo;
    struct reg *prox;
} No;

int criarEstruturaAuxiliar(EstruturaAuxiliar vetorPrincipal[], int posicao, int tamanho);
int inserirNumeroEmEstrutura(EstruturaAuxiliar vetorPrincipal[], int posicao, int valor);
int excluirNumeroDoFinaldaEstrutura(EstruturaAuxiliar vetorPrincipal[], int posicao);
int excluirNumeroEspecificoDeEstrutura(EstruturaAuxiliar vetorPrincipal[], int posicao, int valor);
int getDadosEstruturaAuxiliar(EstruturaAuxiliar vetorPrincipal[], int posicao, int vetorAux[]);
int getDadosOrdenadosEstruturaAuxiliar(EstruturaAuxiliar vetorPrincipal[], int posicao, int vetorAux[]);
int getDadosDeTodasEstruturasAuxiliares(EstruturaAuxiliar vetorPrincipal[], int vetorAux[]);
int getDadosOrdenadosDeTodasEstruturasAuxiliares(EstruturaAuxiliar vetorPrincipal[], int vetorAux[]);
int modificarTamanhoEstruturaAuxiliar(EstruturaAuxiliar vetorPrincipal[], int posicao, int novoTamanho);
int getQuantidadeElementosEstruturaAuxiliar(EstruturaAuxiliar vetorPrincipal[], int posicao);
No *montarListaEncadeadaComCabecote(EstruturaAuxiliar vetorPrincipal[]);
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]);
void destruirListaEncadeadaComCabecote(No **inicio);

void inicializar();
void finalizar();
int comparar(const void *a, const void *b);

#endif
