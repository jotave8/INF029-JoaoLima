#ifndef DISCIPLINA_H
#define DISCIPLINA_H
#include "defines.h"

typedef struct disc {
  char nome[50];
  int codigo;
  int semestre;
  char docente[10];
  int ativo;
} Disciplina;

int menuDisciplina();
int cadastrarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina);
void listarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina);
int atualizarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina);
int excluirDisciplina(Disciplina listaDisciplina[], int qtdDisciplina);

#endif