#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct {
    int *valores;
    int tamanho;
    int ocupados;
} EstruturaAuxiliar;

void inicializarEstruturas();
void criarEstruturaAuxiliar(int posicao, int tamanho);
void inserirElemento(int posicao, int valor);
void excluirElemento(int posicao, int valor);
void listarEstruturas();

#endif
