#include "aluno.h"
#include "cpf.h"
#include "defines.h"
#include "disciplina.h"
#include "professor.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int menuGeral();

int main(void) {

  Aluno listaAluno[TAM_ALUNO];
  Professor listaProfessor[TAM_PROFESSOR];
  Disciplina listaDisciplina[TAM_DISCIPLINA];
  int opcao;
  int qtdAluno = 0;
  int qtdProfessor = 0;
  int qtdDisciplina = 0;

  int sair = 0;
  while (!sair) {

    opcao = menuGeral();
    switch (opcao) {
    case 0: {
      sair = 1;
      break;
    }
    case 1: {
      printf("Modulo Aluno\n");
      int sairAluno = 0;
      int opcaoAluno;

      while (!sairAluno) {

        opcaoAluno = menuAluno();
        switch (opcaoAluno) {
        case 0: {
          sairAluno = 1;
          break;
        }
        case 1: {
          int retorno = cadastrarAluno(listaAluno, qtdAluno);
          switch (retorno) {
          case LISTA_CHEIA: {
            printf("Lista de alunos cheia\n");
            break;
          }
          case MATRICULA_INVALIDA: {
            printf("Matricula invalida\n");
            break;
          }
          case OPCAO_INVALIDA: {
            printf("Opção invalida\n");
            break;
          }
          case CPF_INVALIDO: {
            printf("CPF invalido\n");
            break;
          }
          case CAD_ALUNO_SUCESSO: {
            printf("Cadastrado com sucesso\n");
            qtdAluno++;
            break;
          }
          }

          break;
        }
        case 2: {
          listarAluno(listaAluno, qtdAluno);
          break;
        }
        case 3: {
          int retorno = atualizarAluno(listaAluno, qtdAluno);
          switch (retorno) {
          case MATRICULA_INVALIDA: {
            printf("Matricula invalida\n");
            break;
          }
          case ATUALIZACAO_ALUNO_SUCESSO: {
            printf("Aluno atualizado com sucesso\n");
            break;
          }
          case MATRICULA_INEXISTENTE: {
            printf("Matricula inexistente\n");
            break;
          }
          case OPCAO_INVALIDA: {
            printf("Opcao invalida\n");
          }
          }
          break;
        }
        case 4: {
          int retorno = excluirAluno(listaAluno, qtdAluno);
          switch (retorno) {
          case MATRICULA_INVALIDA: {
            printf("Matricula invalida\n");
            break;
          }
          case EXCLUSAO_ALUNO_SUCESSO: {
            printf("Aluno excluido com sucesso\n");
            qtdAluno--;
            break;
          }
          case MATRICULA_INEXISTENTE: {
            printf("Matricula inexistente\n");
            break;
          }
          }
          break;
        }
        default: {
          printf("Opção Invalida\n");
        }
        }
      }

      break;
    }
    case 2: {
      printf("Modulo Professor\n");
      int sairProfessor = 0;
      int opcaoProfessor;

      while (!sairProfessor) {

        opcaoProfessor = menuProfessor();
        switch (opcaoProfessor) {
        case 0: {
          sairProfessor = 1;
          break;
        }
        case 1: {
          int retorno = cadastrarProfessor(listaProfessor, qtdProfessor);
          switch (retorno) {
          case LISTA_CHEIA: {
            printf("Lista de Professores cheia\n");
            break;
          }
          case MATRICULA_INVALIDA: {
            printf("Matricula invalida\n");
            break;
          }
          case CAD_PROF_SUCESSO: {
            printf("Cadastrado com sucesso\n");
            qtdProfessor++;
            break;
          }
          case OPCAO_INVALIDA: {
            printf("Opcao invalida");
          }
          }
          break;
        }
        case 2: {
          listarProfessor(listaProfessor, qtdProfessor);
          break;
        }
        case 3: {
          int retorno = atualizarProfessor(listaProfessor, qtdProfessor);
          switch (retorno) {
          case MATRICULA_INVALIDA: {
            printf("Matricula invalida\n");
            break;
          }
          case ATUALIZACAO_PROF_SUCESSO: {
            printf("Professor atualizado com sucesso\n");
            break;
          }
          case MATRICULA_INEXISTENTE: {
            printf("Matricula inexistente\n");
            break;
          }
          }
          break;
        }
        case 4: {
          int retorno = excluirProfessor(listaProfessor, qtdProfessor);
          switch (retorno) {
          case MATRICULA_INVALIDA: {
            printf("Matricula invalida\n");
            break;
          }
          case EXCLUSAO_PROF_SUCESSO: {
            printf("Professor excluido com sucesso\n");
            qtdAluno--;
            break;
          }
          case MATRICULA_INEXISTENTE: {
            printf("Matricula inexistente\n");
            break;
          }
          }
          break;
        }
        }
      }

      break;
    }
    case 3: {
      printf("Modulo Disciplina\n");
      int sairDisciplina = 0;
      int opcaoDisciplina;
      while (!sairDisciplina) {

        opcaoDisciplina = menuDisciplina();
        switch (opcaoDisciplina) {
        case 0: {
          sairDisciplina = 1;
          break;
        }
        case 1: {
          int retorno = cadastrarDisciplina(listaDisciplina, qtdDisciplina);
          if (retorno == LISTA_CHEIA)
            printf("Lista de alunos cheia\n");
          else if (retorno == CODIGO_INVALIDO)
            printf("Codigo invalido\n");
          else {
            printf("Cadastrado com sucesso\n");
            qtdDisciplina++;
          }
          break;
        }
        case 2: {
          listarDisciplina(listaDisciplina, qtdDisciplina);
          break;
        }
        case 3: {
          int retorno = atualizarDisciplina(listaDisciplina, qtdDisciplina);
          switch (retorno) {
          case CODIGO_INVALIDO: {
            printf("Codigo invalido\n");
            break;
          }
          case ATUALIZACAO_DISC_SUCESSO: {
            printf("Disciplina atualizado com sucesso\n");
            break;
          }
          case CODIGO_INEXISTENTE: {
            printf("Codigo inexistente\n");
            break;
          }
          }
          break;
        }
        case 4: {
          int retorno = excluirDisciplina(listaDisciplina, qtdDisciplina);
          switch (retorno) {
          case CODIGO_INVALIDO: {
            printf("Codigo invalido\n");
            break;
          }
          case EXCLUSAO_DISC_SUCESSO: {
            printf("Disciplina excluida com sucesso\n");
            qtdAluno--;
            break;
          }
          case CODIGO_INEXISTENTE: {
            printf("Codigo inexistente\n");
            break;
          }
          }
          break;
        }
        default: {
          int retorno = printf("Opção Invalida\n");
        }
        }
      }

      break;
    }
    default: {
      printf("Opcao Invalida\n");
    }
    }
  }
}

int menuGeral() {
  int opcao;
  printf("╔═════════════════════════════════════════╗\n");
  printf("║             Projeto Escola              ║\n");
  printf("║═════════════════════════════════════════║\n");
  printf("║      Joao Victor e Angelito Chagas      ║\n");
  printf("╚═════════════════════════════════════════╝\n\n");
  printf("0 - Sair\n");
  printf("1 - Aluno\n");
  printf("2 - Professor\n");
  printf("3 - Disciplina\n");
  scanf("%d", &opcao);

  return opcao;
}
