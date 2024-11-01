#include "aluno.h"
#include "cpf.h"
#include "util.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int menuAluno() {
  int opcaoAluno;
  printf("0 - Voltar\n");
  printf("1 - Cadastrar Aluno\n");
  printf("2 - Listar Aluno\n");
  printf("3 - Atualizar Aluno\n");
  printf("4 - Excluir Aluno\n");
  scanf("%d", &opcaoAluno);

  return opcaoAluno;
}
int cadastrarAluno(Aluno listaAluno[], int qtdAluno) {
  int validarCPF(const char *cpf);
  printf("Cadastrar Aluno\n");
  if (qtdAluno == TAM_ALUNO) {
    return LISTA_CHEIA;
  } else {
    getchar();
    printf("Informe o nome:\n");
    char nome[80];
    fgets(nome, sizeof(nome), stdin);
    maiusculo(nome);
    nome[strcspn(nome, "\n")] = 0;
    strcpy(listaAluno[qtdAluno].nome, nome);

    printf("Informe o CPF (somente números):\n");
    char cpf[12];
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = 0;
    if (!validarCPF(cpf)) {
      return CPF_INVALIDO;
    }
    strcpy(listaAluno[qtdAluno].cpf, cpf);

    printf("Digite a matricula:\n");
    int matricula;
    scanf("%d", &matricula);
    if (matricula < 0) {
      return MATRICULA_INVALIDA;
    }

    for (int i = 0; i < qtdAluno; i++) {
      if (listaAluno[i].ativo == 1 && listaAluno[i].matricula == matricula) {
        return MATRICULA_INVALIDA;
      }
    }
    listaAluno[qtdAluno].matricula = matricula;
    char sexo;
    getchar();
    printf("Digite o sexo (M/F):\n");
    scanf("%c", &sexo);
    sexo = toupper(sexo);

    if (sexo == 'M' ||sexo == 'F') {
      listaAluno[qtdAluno].sexo = sexo;
      listaAluno[qtdAluno].ativo = 1;
      return CAD_ALUNO_SUCESSO;
    } else {
      return OPCAO_INVALIDA;
    }
  }
}
void listarAluno(Aluno listaAluno[], int qtdAluno) {
  printf("Listar Aluno\n");
  if (qtdAluno == 0) {
    printf("Lista de alunos vazia\n");
  } else {
    for (int i = 0; i < qtdAluno; i++) {
      if (listaAluno[i].ativo == 1) {
        printf("Nome: %s    Matricula: %d   Sexo: %c  CPF: %s\n",
               listaAluno[i].nome, listaAluno[i].matricula, listaAluno[i].sexo,
               listaAluno[i].cpf);
      }
    }
  }
}
int atualizarAluno(Aluno listaAluno[], int qtdAluno) {
  printf("Atualizar Aluno\n");
  printf("Digite a matricula\n");
  int matricula;
  scanf("%d", &matricula);
  int achou = 0;
  if (matricula < 0) {
    return MATRICULA_INVALIDA;
  } else {
    for (int i = 0; i < qtdAluno; i++) {
      if (matricula == listaAluno[i].matricula) {
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
          strcpy(listaAluno[i].nome, novonome);

        } else if (opcao != 'N') {
          return OPCAO_INVALIDA;
        }

        printf("Deseja atualizar o CPF?(S/N)\n");
        scanf(" %c", &opcao);
        opcao = toupper(opcao);
        if (opcao == 'S') {
          char novocpf[12];
          printf("Digite a novo cpf:\n");
          getchar();
          fgets(novocpf, sizeof(novocpf), stdin);
          novocpf[strcspn(novocpf, "\n")] = 0;
          strcpy(listaAluno[i].cpf, novocpf);

        } else if (opcao != 'N') {
          return OPCAO_INVALIDA;
        }

        printf("Deseja atualizar a matricula?(S/N)\n");
        scanf(" %c", &opcao);
        opcao = toupper(opcao);
        getchar();
        if (opcao == 'S') {
          printf("Digite a nova matricula\n");
          int novamatricula;
          scanf("%d", &novamatricula);
          if (novamatricula < 0) {
            return MATRICULA_INVALIDA;
          }
          listaAluno[i].matricula = novamatricula;
        } else if (opcao != 'N') {
          return OPCAO_INVALIDA;
        }

        printf("Deseja atualizar o sexo?(S/N)\n");
        scanf(" %c", &opcao);
        opcao = toupper(opcao);
        if (opcao == 'S') {
          getchar();
          printf("Digite o sexo:\n");
          char novosexo;
          scanf("%c", &novosexo);
          novosexo = toupper(novosexo);
          if (novosexo == 'M' || novosexo == 'F') {
            listaAluno[i].sexo = novosexo;
          } else {
            return OPCAO_INVALIDA;
          }
        } else if (opcao != 'N') {
          return OPCAO_INVALIDA;
        }

        achou = 1;
        break;
      }
    }
    if (achou)
      return ATUALIZACAO_ALUNO_SUCESSO;
    else
      return MATRICULA_INEXISTENTE;
  }
}
int excluirAluno(Aluno listaAluno[], int qtdAluno) {
  printf("Excluir Aluno\n");
  printf("Digite a matricula\n");
  int matricula;
  scanf("%d", &matricula);
  int achou = 0;
  if (matricula < 0) {
    return MATRICULA_INVALIDA;
  } else {
    for (int i = 0; i < qtdAluno; i++) {
      if (matricula == listaAluno[i].matricula) {

        listaAluno[i].ativo = -1;
        for (int j = i; j < qtdAluno - 1; j++) {
          listaAluno[j].matricula = listaAluno[j + 1].matricula;
          strcpy(listaAluno[j].nome, listaAluno[j + 1].nome);
          listaAluno[j].sexo = listaAluno[j + 1].sexo;
          strcpy(listaAluno[j].cpf, listaAluno[j + 1].cpf);
          listaAluno[j].ativo = listaAluno[j + 1].ativo;
        }
        achou = 1;
        break;
      }
    }
    if (achou)
      return EXCLUSAO_ALUNO_SUCESSO;
    else
      return MATRICULA_INEXISTENTE;
  }
}