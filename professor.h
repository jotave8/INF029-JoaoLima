#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "defines.h"

typedef struct prof {
  int matricula;
  char sexo;
  char nome[80];
  int data_nasc;
  char cpf[12];
  int ativo;
} Professor;

int menuProfessor();
int cadastrarProfessor(Professor listaProfessor[], int qtdProfessor);
void listarProfessor(Professor listaProfessor[], int qtdProfessor);
int atualizarProfessor(Professor listaProfessor[], int qtdProfessor);
int excluirProfessor(Professor listaProfessor[], int qtdProfessor);

#endif