#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct {
    int *valores;
    int tamanho;
    int ocupados;
} EstruturaAuxiliar;

void inicializarEstruturas();
void criarEstruturaAuxiliar(EstruturaAuxiliar principal[10], int posicao, int tamanho);
void inserirElemento(EstruturaAuxiliar principal[10], int posicao, int valor);
void aumentarEstruturaAuxiliar(EstruturaAuxiliar principal[10], int posicao, int tamanhoExtra);
void excluirElemento(EstruturaAuxiliar principal[10], int posicao, int valor);
void listarEstruturas();

#endif
