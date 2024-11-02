#include "professor.h"
#include "cpf.h"
#include "util.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int menuProfessor() {
  int opcaoProfessor;
  printf("0 - Voltar\n");
  printf("1 - Cadastrar Professor\n");
  printf("2 - Listar Professor\n");
  printf("3 - Atualizar Professor\n");
  printf("4 - Excluir Professor\n");
  scanf("%d", &opcaoProfessor);

  return opcaoProfessor;
}
int cadastrarProfessor(Professor listaProfessor[], int qtdProfessor) {
  printf("Cadastrar Professor\n");
  if (qtdProfessor == TAM_PROFESSOR) {
    return LISTA_CHEIA;
  } else {
    getchar();
    printf("Informe o nome:\n");
    char nome[80];
    fgets(nome, sizeof(nome), stdin);
    maiusculo(nome);
    nome[strcspn(nome, "\n")] = 0;
    strcpy(listaProfessor[qtdProfessor].nome, nome);

    printf("Informe o CPF (somente números):\n");
    char cpf[12];
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = 0;
    if (!validarCPF(cpf)) {
      return CPF_INVALIDO;
    }
    strcpy(listaProfessor[qtdProfessor].cpf, cpf);

    printf("Informe o dia de nascimento:\n");
    scanf("%d", &listaProfessor[qtdProfessor].diaNascimento);
    printf("Informe o mês de nascimento:\n");
    scanf("%d", &listaProfessor[qtdProfessor].mesNascimento);
    printf("Informe o ano de nascimento:\n");
    scanf("%d", &listaProfessor[qtdProfessor].anoNascimento);

    printf("Digite a matricula\n");
    int matricula;
    scanf("%d", &matricula);
    if (matricula < 0) {
      return MATRICULA_INVALIDA;
    }

    for (int i = 0; i < qtdProfessor; i++) {
      if (listaProfessor[i].ativo == 1 &&
          listaProfessor[i].matricula == matricula) {
        return MATRICULA_INVALIDA;
      }
    }
    listaProfessor[qtdProfessor].matricula = matricula;

    char sexo;
    getchar();
    printf("Digite o sexo (M/F): ");
    scanf("%c", &sexo);
    sexo = toupper(sexo);

    if (sexo == 'M' || sexo == 'F') {
      listaProfessor[qtdProfessor].sexo = sexo;
      listaProfessor[qtdProfessor].ativo = 1;
      return CAD_PROF_SUCESSO;
    } else {
      return OPCAO_INVALIDA;
    }
  }
}
void listarProfessor(Professor listaProfessor[], int qtdProfessor) {
  printf("Listar Professor\n");
  if (qtdProfessor == 0) {
    printf("Lista de Professores vazia\n");
  } else {
    for (int i = 0; i < qtdProfessor; i++) {
      if (listaProfessor[i].ativo == 1) {
        printf("Nome: %s    Matricula: %d   Sexo: %c  CPF: %s   Data de Nascimento: %02d/%02d/%d\n",
               listaProfessor[i].nome, listaProfessor[i].matricula,
               listaProfessor[i].sexo, listaProfessor[i].cpf,listaProfessor[i].diaNascimento, listaProfessor[i].mesNascimento,
               listaProfessor[i].anoNascimento);
      }
    }
  }
}
int atualizarProfessor(Professor listaProfessor[], int qtdProfessor) {
  printf("Atualizar Professor\n");
  printf("Digite a matricula\n");
  int matricula;
  scanf("%d", &matricula);
  int achou = 0;
  if (matricula < 0) {
    return MATRICULA_INVALIDA;
  } else {
    for (int i = 0; i < qtdProfessor; i++) {
      if (matricula == listaProfessor[i].matricula) {
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
          strcpy(listaProfessor[i].nome, novonome);

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
          strcpy(listaProfessor[i].cpf, novocpf);

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
          listaProfessor[i].matricula = novamatricula;
        } else if (opcao != 'N') {
          return OPCAO_INVALIDA;
        }

        printf("Deseja atualizar a data de nascimento?(S/N)\n");
        scanf(" %c", &opcao);
        opcao = toupper(opcao);
        if (opcao == 'S') {
            printf("Informe o novo dia de nascimento:\n");
            scanf("%d", &listaProfessor[i].diaNascimento);
            printf("Informe o novo mês de nascimento:\n");
            scanf("%d", &listaProfessor[i].mesNascimento);
            printf("Informe o novo ano de nascimento:\n");
            scanf("%d", &listaProfessor[i].anoNascimento);
        }else if (opcao != 'N') {
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
            listaProfessor[i].sexo = novosexo;
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
      return ATUALIZACAO_PROF_SUCESSO;
    else
      return MATRICULA_INEXISTENTE;
  }
}
int excluirProfessor(Professor listaProfessor[], int qtdProfessor) {
  printf("Excluir Professor\n");
  printf("Digite a matricula\n");
  int matricula;
  scanf("%d", &matricula);
  int achou = 0;
  if (matricula < 0) {
    return MATRICULA_INVALIDA;
  } else {
    for (int i = 0; i < qtdProfessor; i++) {
      if (matricula == listaProfessor[i].matricula) {
        listaProfessor[i].ativo = -1;
        for (int j = i; j < qtdProfessor - 1; j++) {
          listaProfessor[j].matricula = listaProfessor[j + 1].matricula;
          strcpy(listaProfessor[j].nome, listaProfessor[j + 1].nome);
          listaProfessor[j].sexo = listaProfessor[j + 1].sexo;
          listaProfessor[j].ativo = listaProfessor[j + 1].ativo;
          strcpy(listaProfessor[j].cpf, listaProfessor[j + 1].cpf);
        }
        achou = 1;
        break;
      }
    }
    if (achou)
      return EXCLUSAO_PROF_SUCESSO;
    else
      return MATRICULA_INEXISTENTE;
  }
}