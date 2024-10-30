#ifndef ALUNO_H
#define ALUNO_H

typedef enum {
  TAM_ALUNO 10
  CAD_ALUNO_SUCESSO -1
  MATRICULA_INVALIDA -2
  LISTA_CHEIA -3
  ATUALIZACAO_ALUNO_SUCESSO = -4
  MATRICULA_INEXISTENTE = -5
  EXCLUSAO_ALUNO_SUCESSO = -6
  OPCAO_INVALIDA = -15
  CPF_INVALIDO = -16

}StatusCodigo;

typedef struct alu{
	int matricula;
	char sexo;
	char nome [80];
	char cpf[12];
	int ativo;
} Aluno;

// Declaração das funções de aluno
int menuAluno();
int cadastrarAluno(Aluno listaAluno[], int qtdAluno);
void listarAluno(Aluno listaAluno[], int qtdAluno);
int atualizarAluno(Aluno listaAluno[], int qtdAluno);
int excluirAluno(Aluno listaAluno[], int qtdAluno);

#endif
