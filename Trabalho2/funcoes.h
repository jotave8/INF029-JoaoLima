#ifndef FUNCOES_H
#define FUNCOES_H

// Definição da estrutura auxiliar
typedef struct {
    int *valores;  // Ponteiro para a estrutura auxiliar
    int tamanho;   // Tamanho total da estrutura auxiliar
    int ocupados;  // Quantidade de posições ocupadas
} EstruturaAuxiliar;


void inicializarEstruturas();
void criarEstruturaAuxiliar(int posicao, int tamanho);
void inserirElemento(int posicao, int valor);
void excluirElemento(int posicao, int valor);
void listarEstruturas();

#endif
