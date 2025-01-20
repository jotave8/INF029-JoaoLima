#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"
#define TAM 10
int menu();

int menu(){
    int op;
    printf("\nDigite a opcao desejada\n");
    printf("0 - Sair\n");
    printf("1 - Inserir\n");
    printf("2 - Excluir\n");
    printf("3 - Listar uma estrutura\n");
    printf("10 - Dobrar Numero\n");
    printf("Escolha: ");
    scanf("%d", &op);
    return op;
}

int main(){
    EstruturaAuxiliar vetorPrincipal[TAM];
    inicializar();
    int op;
    int sair = 0;

    while (!sair)
    {
        op = menu();
        switch (op)
        {
        case 0:
        {
            sair = 1;
            finalizar();
            break;
        }
        case 1:
        { // Inserir
            int posicao, valor, ret;
            printf("Informe a posicao (1 a 10): ");
            scanf("%d", &posicao);
            printf("Informe o valor a inserir: ");
            scanf("%d", &valor);

            ret = inserirNumeroEmEstrutura(vetorPrincipal, posicao, valor);

            if (ret == SUCESSO)
            {
                printf("Inserido com sucesso\n");
            }
            else if (ret == SEM_ESPACO)
            {
                printf("Sem espaco\n");
            }
            else if (ret == SEM_ESTRUTURA_AUXILIAR)
            {
                printf("Sem estrutura auxiliar\n");
            }
            else if (ret == POSICAO_INVALIDA)
            {
                printf("Posicao invalida\n");
            }
            break;
        }
        case 2:
        { // Excluir
            int posicao, valor, ret;
            printf("Informe a posicao (1 a 10): ");
            scanf("%d", &posicao);
            printf("Informe o valor a excluir: ");
            scanf("%d", &valor);

            ret = excluirNumeroEspecificoDeEstrutura(vetorPrincipal,posicao, valor);

            if (ret == SUCESSO)
            {
                printf("Valor excluido com sucesso\n");
            }
            else if (ret == NUMERO_INEXISTENTE)
            {
                printf("Numero inexistente\n");
            }
            else if (ret == SEM_ESTRUTURA_AUXILIAR)
            {
                printf("Sem estrutura auxiliar\n");
            }
            else if (ret == POSICAO_INVALIDA)
            {
                printf("Posicao invalida\n");
            }
            break;
        }
        case 3:
        { // Listar estrutura
            int posicao, retorno, qtd;
            printf("Qual a estrutura a ser listada (1..10)? ");
            scanf("%d", &posicao);

            qtd = getQuantidadeElementosEstruturaAuxiliar(vetorPrincipal, posicao);

            if (qtd == POSICAO_INVALIDA)
            {
                printf("Posicao invalida\n");
            }
            else if (qtd == SEM_ESTRUTURA_AUXILIAR)
            {
                printf("Sem estrutura auxiliar\n");
            }
            else if (qtd == ESTRUTURA_AUXILIAR_VAZIA)
            {
                printf("Estrutura auxiliar vazia\n");
            }
            else
            { // Existe elemento
                int vetorAux[qtd];
                retorno = getDadosEstruturaAuxiliar(vetorPrincipal, posicao, vetorAux);

                if (retorno == SUCESSO)
                {
                    printf("Elementos da estrutura auxiliar:\n");
                    for (int i = 0; i < qtd; i++)
                    {
                        printf("%d ", vetorAux[i]);
                    }
                    printf("\n");
                }
            }
            break;
        }
        case 10:
        { // Dobrar
            int valor;
            printf("Digite um numero para dobrar: ");
            scanf("%d", &valor);

            dobrar(&valor);

            printf("O dobro do numero é: %d\n", valor);

            break;
        }
        default:
        {
            printf("Opcao invalida\n");
        }
        }
    }

    return 0;
}
