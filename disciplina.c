#include "disciplina.h"
#include "util.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int menuDisciplina() {
  int opcaoDisciplina;
  printf("Modulo Disciplina\n");
  printf("0 - Voltar\n");
  printf("1 - Cadastrar Disciplina\n");
  printf("2 - Listar Disciplina\n");
  printf("3 - Atualizar Disciplina\n");
  printf("4 - Excluir Disciplina\n");
  scanf("%d", &opcaoDisciplina);

  return opcaoDisciplina;
}
int cadastrarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina) {
  printf("Cadastrar Professor\n");
  if (qtdDisciplina == TAM_DISCIPLINA) {
    return LISTA_CHEIA;
  } else {
    getchar();
    printf("Informe o nome:\n");
    char nome[50];
    fgets(nome, sizeof(nome), stdin);
    maiusculo(nome);
    nome[strcspn(nome, "\n")] = 0;
    strcpy(listaDisciplina[qtdDisciplina].nome, nome);
    printf("Digite o codigo:\n");
    int codigo;
    scanf("%d", &codigo);
    if (codigo < 0) {
      return CODIGO_INVALIDO;
    }
    listaDisciplina[qtdDisciplina].codigo = codigo;
    listaDisciplina[qtdDisciplina].ativo = 1;
    return CAD_DISC_SUCESSO;
  }
}
void listarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina) {
  printf("Listar Disciplina\n");
  if (qtdDisciplina == 0) {
    printf("Lista de disciplinas vazia\n");
  } else {
    for (int i = 0; i < qtdDisciplina; i++) {
      if (listaDisciplina[i].ativo == 1) {
        printf("Nome: %s    Codigo: %d\n", listaDisciplina[i].nome,
               listaDisciplina[i].codigo);
      }
    }
  }
}
int atualizarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina) {
  printf("Atualizar Disciplina\n");
  printf("Digite o codigo:\n");
  int codigo;
  scanf("%d", &codigo);
  int achou = 0;
  if (codigo < 0) {
    return CODIGO_INVALIDO;
  } else {
    for (int i = 0; i < qtdDisciplina; i++) {
      if (codigo == listaDisciplina[i].codigo) {
        char opcao;
        printf("Deseja atualizar o nome?(S/N)\n");
        scanf(" %c", &opcao);
        opcao = toupper(opcao);
        getchar();
        if (opcao == 'S') {
          char novonome[80];
          printf("Digite a novo nome:\n");
          getchar();
          fgets(novonome, sizeof(novonome), stdin);
          maiusculo(novonome);
          novonome[strcspn(novonome, "\n")] = 0;
          strcpy(listaDisciplina[i].nome, novonome);

        } else if (opcao != 'N') {
          return OPCAO_INVALIDA;
        }
        printf("Deseja atualizar o codigo?(S/N)\n");
        scanf(" %c", &opcao);
        opcao = toupper(opcao);
        getchar();
        if (opcao == 'S') {
          printf("Digite o novo codigo\n");
          int novocodigo;
          scanf("%d", &novocodigo);
          if (novocodigo < 0) {
            return CODIGO_INVALIDO;
          }
           listaDisciplina[i].codigo = novocodigo;
        } else if (opcao != 'N') {
          return OPCAO_INVALIDA;
        }
        achou = 1;
        break;
      }
    }
    if (achou)
      return ATUALIZACAO_DISC_SUCESSO;
    else
      return CODIGO_INEXISTENTE;
  }
}
int excluirDisciplina(Disciplina listaDisciplina[], int qtdDisciplina) {
  printf("Excluir Disciplina\n");
  printf("Digite o codigo:\n");
  int codigo;
  scanf("%d", &codigo);
  int achou = 0;
  if (codigo < 0) {
    return CODIGO_INVALIDO;
  } else {
    for (int i = 0; i < qtdDisciplina; i++) {
      if (codigo == listaDisciplina[i].codigo) {
        listaDisciplina[i].ativo = -1;
        for (int j = i; j < qtdDisciplina - 1; j++) {
          listaDisciplina[j].codigo = listaDisciplina[j + 1].codigo;
          listaDisciplina[j].nome = listaDisciplina [j + 1].nome;
          listaDisciplina[j].ativo = listaDisciplina[j + 1].ativo;
        }
        achou = 1;
        break;
      }
    }
    if (achou)
      return EXCLUSAO_DISC_SUCESSO;
    else
      return CODIGO_INEXISTENTE;
  }
}
