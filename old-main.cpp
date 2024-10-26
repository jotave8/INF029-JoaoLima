#include <stdio.h>
#include <string.h>
#define TAM_ALUNO 10
#define TAM_PROFESSOR 5
#define TAM_DISCIPLINA 10

typedef enum {
    CAD_ALUNO_SUCESSO = -1,
    MATRICULA_INVALIDA = -2,
    LISTA_CHEIA = -3,
    ATUALIZACAO_ALUNO_SUCESSO = -4,
    MATRICULA_INEXISTENTE = -5,
    EXCLUSAO_ALUNO_SUCESSO = -6,
    CAD_PROF_SUCESSO = -7,
    ATUALIZACAO_PROF_SUCESSO = -8,
    EXCLUSAO_PROF_SUCESSO = -9,
    CAD_DISC_SUCESSO = -10,
    ATUALIZACAO_DISC_SUCESSO = -11,
    EXCLUSAO_DISC_SUCESSO = -12,
    CODIGO_INVALIDO = -13,
    CODIGO_INEXISTENTE = -14,
    OPCAO_INVALIDA = -15
} StatusCodigo;

typedef struct alu{
	int matricula;
	char sexo;
	char nome [80];
	char data_nasc[11];
	int cpf;
	int ativo;
} Aluno;

typedef struct prof{
    int matricula;
	char sexo;
	char nome [80];
	int data_nasc;
	int cpf;
	int ativo;
} Professor;

typedef struct disc{
    char nome[50];
    int codigo;
    int semestre;
    char docente[10];
    int ativo;
} Disciplina;

// prototipos das funções
int menuGeral();

int menuAluno();
int cadastrarAluno(Aluno listaAluno[], int qtdAluno);
void listarAluno(Aluno listaAluno[], int qtdAluno);
int atualizarAluno(Aluno listaAluno[], int qtdAluno);
int excluirAluno(Aluno listaAluno[], int qtdAluno);

int menuProfessor();
int cadastrarProfessor(Professor listaProfessor[], int qtdProfessor);
void listarProfessor(Professor listaProfessor[], int qtdProfessor);
int atualizarProfessor(Professor listaProfessor[], int qtdProfessor);
int excluirProfessor(Professor listaProfessor[], int qtdProfessor);

int menuDisciplina();
int cadastrarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina);
void listarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina);
int atualizarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina);
int excluirDisciplina(Disciplina listaDisciplina[], int qtdDisciplina);

// utilizar um gerador automatico de matricula
// modularização (organização em módulos)
// novos atributos na struct aluno e fazer a leitura desses atributos
// validações 


int main (void){
	
	Aluno listaAluno[TAM_ALUNO];
	Professor listaProfessor[TAM_PROFESSOR];
	Disciplina listaDisciplina[TAM_DISCIPLINA];
	int opcao;
	int qtdAluno = 0;
	int qtdProfessor = 0;
	int qtdDisciplina = 0;
	
	int sair = 0; //falso
	
	while(!sair){
		
		opcao = menuGeral();
		switch (opcao){
			case 0:{
				sair = 1;
				break;
			}
			case 1:{
				printf("Modulo Aluno\n");
				int sairAluno = 0;
				int opcaoAluno;
				
				while(!sairAluno){
					
					opcaoAluno = menuAluno();
					switch(opcaoAluno){
						case 0:{
							sairAluno = 1;
							break;
						}
						case 1:{
							int retorno = cadastrarAluno(listaAluno,qtdAluno);
							switch(retorno){
							    case LISTA_CHEIA:{
							        printf("Lista de alunos cheia\n");
							        break;
							    }
							    case MATRICULA_INVALIDA:{
							        printf("Matricula invalida\n");
							        break;
							    }
							    case OPCAO_INVALIDA:{
							        printf("Opção Invalida\n");
							        break;
							    }
							    case CAD_ALUNO_SUCESSO:{
							       	printf("Cadastrado com sucesso\n");	
							    	qtdAluno++;
							    	break;
							    }
							}

							break;
						}
						case 2:{
							listarAluno(listaAluno,qtdAluno);
							break;
						}
						case 3:{
							int retorno = atualizarAluno(listaAluno,qtdAluno);
							switch(retorno){
							    case MATRICULA_INVALIDA:{
							        printf("Matricula invalida\n");
							        break;
							    }
							    case ATUALIZACAO_ALUNO_SUCESSO:{
							        printf("Aluno atualizado com sucesso\n");
							        break;
							    }
							    case MATRICULA_INEXISTENTE:{
							        printf("Matricula inexistente\n");
							        break;
							    }
							    case OPCAO_INVALIDA:{
							        printf("Opcao invalida\n");
							    }
							}
							break;
						}
						case 4:{
						    int retorno = excluirAluno(listaAluno,qtdAluno);
						    switch (retorno){
						        case MATRICULA_INVALIDA:{
							        printf("Matricula invalida\n");
							        break;
							    }
							    case EXCLUSAO_ALUNO_SUCESSO:{
							        printf("Aluno excluido com sucesso\n");
							        qtdAluno --;
							        break;
							    }
							    case MATRICULA_INEXISTENTE:{
							        printf("Matricula inexistente\n");
							        break;
							    }
						    
							}
							break;
						}
						default:{
							printf("Opção Invalida\n");
						}
					}
				}
							
				break;
			}
			case 2:{
				printf("Modulo Professor\n");
				int sairProfessor = 0;
				int opcaoProfessor;
				
				while(!sairProfessor){
					
					opcaoProfessor = menuProfessor();
					switch(opcaoProfessor){
						case 0:{
							sairProfessor = 1;
							break;
						}
						case 1:{	
						    int retorno = cadastrarProfessor(listaProfessor,qtdProfessor);
						    switch(retorno){
						        case LISTA_CHEIA:{
						            printf("Lista de Professores cheia\n");
						            break;
						        }
						        case MATRICULA_INVALIDA:{
						            printf("Matricula invalida\n");
						            break;
						        }
						        case CAD_PROF_SUCESSO:{
						            printf("Cadastrado com sucesso\n");	
								    qtdProfessor++;
								    break;
						        }
						        case OPCAO_INVALIDA:{
						            printf("Opcao invalida");
						        }
						        
						    }
							break;
						}
						case 2:{
						    listarProfessor(listaProfessor, qtdProfessor);
							break;
						}
						case 3:{
						    int retorno = atualizarProfessor(listaProfessor,qtdProfessor);
							switch(retorno){
							    case MATRICULA_INVALIDA:{
							        printf("Matricula invalida\n");
							        break;
							    }
							    case ATUALIZACAO_PROF_SUCESSO:{
							        printf("Professor atualizado com sucesso\n");
							        break;
							    }
							    case MATRICULA_INEXISTENTE:{
							        printf("Matricula inexistente\n");
							        break;
							    }
							}
							break;
						}
						case 4:{
						    int retorno = excluirProfessor(listaProfessor,qtdProfessor);
						    switch (retorno){
						        case MATRICULA_INVALIDA:{
							        printf("Matricula invalida\n");
							        break;
							    }
							    case EXCLUSAO_PROF_SUCESSO:{
							        printf("Professor excluido com sucesso\n");
							        qtdAluno --;
							        break;
							    }
							    case MATRICULA_INEXISTENTE:{
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
			case 3:{
			    printf("Modulo Disciplina\n");
				int sairDisciplina = 0;
				int opcaoDisciplina;
				while(!sairDisciplina){
					
					opcaoDisciplina = menuDisciplina();
					switch(opcaoDisciplina){
						case 0:{
							sairDisciplina = 1;
							break;
						}
						case 1:{
							int retorno = cadastrarDisciplina(listaDisciplina,qtdDisciplina);
							if (retorno == LISTA_CHEIA)
								printf("Lista de alunos cheia\n");
							else if (retorno == CODIGO_INVALIDO)
								printf("Codigo invalido\n");
							else{
								printf("Cadastrado com sucesso\n");	
								qtdDisciplina++;	
							}
							break;
						}
						case 2:{
							listarDisciplina(listaDisciplina,qtdDisciplina);
							break;
						}
						case 3:{
							int retorno = atualizarDisciplina(listaDisciplina,qtdDisciplina);
							switch(retorno){
							    case CODIGO_INVALIDO:{
							        printf("Codigo invalido\n");
							        break;
							    }
							    case ATUALIZACAO_DISC_SUCESSO:{
							        printf("Disciplina atualizado com sucesso\n");
							        break;
							    }
							    case CODIGO_INEXISTENTE:{
							        printf("Codigo inexistente\n");
							        break;
							    }
							}
							break;
						}
						case 4:{
						    int retorno = excluirDisciplina(listaDisciplina,qtdDisciplina);
						    switch (retorno){
						        case CODIGO_INVALIDO:{
							        printf("Codigo invalido\n");
							        break;
							    }
							    case EXCLUSAO_DISC_SUCESSO:{
							        printf("Disciplina excluida com sucesso\n");
							        qtdAluno --;
							        break;
							    }
							    case CODIGO_INEXISTENTE:{
							        printf("Codigo inexistente\n");
							        break;
							    }
						    
							}
							break;
						}
						default:{
						    int retorno =
							printf("Opção Invalida\n");
						}
					}
				}
				
				break;
			}
			default:{
				printf("Opcao Invalida\n");
			}
		}
	}
}

// funções 

int menuGeral(){
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

int menuAluno(){
	int opcaoAluno;
	printf("0 - Voltar\n");
	printf("1 - Cadastrar Aluno\n");
	printf("2 - Listar Aluno\n");
	printf("3 - Atualizar Aluno\n");
	printf("4 - Excluir Aluno\n");
	scanf("%d", &opcaoAluno);
	
	return opcaoAluno;
}		
int cadastrarAluno(Aluno listaAluno[], int qtdAluno){
	printf("Cadastrar Aluno\n");
	if(qtdAluno == TAM_ALUNO){
		return LISTA_CHEIA;
	}else{
	    getchar();
	    printf("Informe o nome:\n");
	    char nome[80];
	    fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = 0;
        strcpy(listaAluno[qtdAluno].nome, nome);
		printf("Digite a matricula:\n");
		int matricula;
		scanf("%d",&matricula);
 		if (matricula < 0){
 			return MATRICULA_INVALIDA;
		}

	 	for(int i = 0; i < qtdAluno; i++){
	 	    if(listaAluno[i].ativo == 1 && listaAluno[i].matricula == matricula){
	 	        return MATRICULA_INVALIDA;
	 	    }
	 	}	 	
	 	listaAluno[qtdAluno].matricula = matricula;
        char sexo;
		getchar();
        printf("Digite o sexo (M/F):\n");
        scanf("%c", &sexo);
    
        if (sexo == 'M' || sexo == 'm' || sexo == 'F' || sexo == 'f') {
            listaAluno[qtdAluno].sexo = sexo;
	    	listaAluno[qtdAluno].ativo = 1;
		    return  CAD_ALUNO_SUCESSO;
        } else{
            return OPCAO_INVALIDA;
        }		
	}
}
void listarAluno(Aluno listaAluno[], int qtdAluno){
	printf("Listar Aluno\n");
	if (qtdAluno == 0){
		printf("Lista de alunos vazia\n");
	}else{
		for (int i = 0; i < qtdAluno; i++){
 			if (listaAluno[i].ativo == 1){
				printf("Nome: %s    Matricula: %d   Sexo: %c\n",listaAluno[i].nome, listaAluno[i].matricula,listaAluno[i].sexo);
			}
		}
	}
}
int atualizarAluno(Aluno listaAluno[], int qtdAluno){
	printf("Atualizar Aluno\n");
	printf("Digite a matricula\n");
	int matricula;
	scanf("%d",&matricula);
	int achou = 0;
	if (matricula < 0){
		return MATRICULA_INVALIDA;
	}else{
		for (int i = 0; i < qtdAluno; i++){
			if (matricula == listaAluno[i].matricula){
				//atualização
				char opcao;
				printf("Deseja atualizar o nome?(S/N)\n");
				scanf(" %c", &opcao);
				getchar();
				if (opcao == 'S' || opcao == 's'){
				    char novonome[80];
				    printf("Digite a novo nome:\n");
				    getchar();
				    fgets(novonome, sizeof(novonome), stdin);
                    novonome[strcspn(novonome, "\n")] = 0;
                    strcpy(listaAluno[i].nome, novonome);
                    
				}else if(opcao != 'N' && opcao != 'n'){
				    return OPCAO_INVALIDA;
				}
				
				getchar();
				printf("Deseja atualizar a matricula?(S/N)\n");
				scanf("%c", &opcao);
				if (opcao == 'S' || opcao == 's'){
    				printf("Digite a nova matricula\n");
    				int novamatricula;
    				scanf("%d",&novamatricula);
    				if (novamatricula < 0){
    		            return MATRICULA_INVALIDA;
                	}
                	listaAluno[i].matricula = novamatricula;
				}else if(opcao != 'N' && opcao != 'n'){
				    return OPCAO_INVALIDA;
				}
				getchar();
				printf("Deseja atualizar o sexo?(S/N)\n");
				scanf("%c", &opcao);
				if(opcao == 'S' || opcao == 's'){
				    getchar();
				    printf("Digite o sexo:\n");
				    char novosexo;
				    scanf("%c",&novosexo);
				    if (novosexo == 'M' || novosexo == 'm' || novosexo == 'F' || novosexo == 'f') {
                        listaAluno[i].sexo = novosexo;
                    } else{
                        return OPCAO_INVALIDA;
                    }		
				}else if(opcao != 'N' && opcao != 'n'){
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
int excluirAluno(Aluno listaAluno[], int qtdAluno){
	printf("Excluir Aluno\n");
 	printf("Digite a matricula\n");
	int matricula;
	scanf("%d",&matricula);
	int achou = 0;
	if (matricula < 0){
	    return MATRICULA_INVALIDA;
	}else{
		for (int i = 0; i < qtdAluno; i++){
			if (matricula == listaAluno[i].matricula){
				//exclusão lógica
				listaAluno[i].ativo = -1;
				for (int j = i; j < qtdAluno - 1; j++){//esse metodo de mover para casa anterio se chama Shift
					listaAluno[j].matricula = listaAluno[j+1].matricula;
					listaAluno[j].sexo = listaAluno[j+1].sexo;
					listaAluno[j].ativo = listaAluno[j+1].ativo;
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

int menuProfessor(){
    int opcaoProfessor;
    printf("0 - Voltar\n");
	printf("1 - Cadastrar Professor\n");
	printf("2 - Listar Professor\n");
	printf("3 - Atualizar Professor\n");
	printf("4 - Excluir Professor\n");
	scanf("%d",&opcaoProfessor);
	
	return opcaoProfessor;
}
int cadastrarProfessor(Professor listaProfessor[], int qtdProfessor){
    printf("Cadastrar Professor\n");
	if(qtdProfessor == TAM_PROFESSOR){
		return LISTA_CHEIA;
	}else{
	    getchar();
	    printf("Informe o nome:\n");
	    char nome[80];
	    fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = 0;
        strcpy(listaProfessor[qtdProfessor].nome, nome);
		printf("Digite a matricula\n");
		int matricula;
		scanf("%d",&matricula);
 		if (matricula < 0){
 			return MATRICULA_INVALIDA;
		}
		
	 	for(int i = 0; i < qtdProfessor; i++){
	 	    if(listaProfessor[i].ativo == 1 && listaProfessor[i].matricula == matricula){
	 	        return MATRICULA_INVALIDA;
	 	    }
	 	}	 	
	 	listaProfessor[qtdProfessor].matricula = matricula;
        char sexo;
		getchar();
        printf("Digite o sexo (M/F): ");
        scanf("%c", &sexo);
    
        if (sexo == 'M' || sexo == 'm' || sexo == 'F' || sexo == 'f') {
            listaProfessor[qtdProfessor].sexo = sexo;
	    	listaProfessor[qtdProfessor].ativo = 1;
		    return  CAD_PROF_SUCESSO;
        } else{
            return OPCAO_INVALIDA;
        }
        
	}
}
void listarProfessor(Professor listaProfessor[], int qtdProfessor){
	printf("Listar Professor\n");
	if (qtdProfessor == 0){
		printf("Lista de Professores vazia\n");
	}else{
		for (int i = 0; i < qtdProfessor; i++){
 			if (listaProfessor[i].ativo == 1){
				printf("Nome: %s    Matricula: %d   Sexo: %c\n",listaProfessor[i].nome, listaProfessor[i].matricula, listaProfessor[i].sexo);
			}
		}
	}
}
int atualizarProfessor(Professor listaProfessor[], int qtdProfessor){
	printf("Atualizar Professor\n");
	printf("Digite a matricula\n");
	int matricula;
	scanf("%d",&matricula);
	int achou = 0;
	if (matricula < 0){
		return MATRICULA_INVALIDA;
	}else{
		for (int i = 0; i < qtdProfessor; i++){
			if (matricula == listaProfessor[i].matricula){
				//atualização
                char opcao;
				printf("Deseja atualizar o nome?(S/N)\n");
				scanf(" %c", &opcao);
				getchar();
				if (opcao == 'S' || opcao == 's'){
				    char novonome[80];
				    printf("Digite a novo nome:\n");
				    getchar();
				    fgets(novonome, sizeof(novonome), stdin);
                    novonome[strcspn(novonome, "\n")] = 0;
                    strcpy(listaProfessor[i].nome, novonome);
                    
				}else if(opcao != 'N' && opcao != 'n'){
				    return OPCAO_INVALIDA;
				}
				
				getchar();
				printf("Deseja atualizar a matricula?(S/N)\n");
				scanf("%c", &opcao);
				if (opcao == 'S' || opcao == 's'){
    				printf("Digite a nova matricula\n");
    				int novamatricula;
    				scanf("%d",&novamatricula);
    				if (novamatricula < 0){
    		            return MATRICULA_INVALIDA;
                	}
                	listaProfessor[i].matricula = novamatricula;
				}else if(opcao != 'N' && opcao != 'n'){
				    return OPCAO_INVALIDA;
				}
				getchar();
				printf("Deseja atualizar o sexo?(S/N)\n");
				scanf("%c", &opcao);
				if(opcao == 'S' || opcao == 's'){
				    getchar();
				    printf("Digite o sexo:\n");
				    char novosexo;
				    scanf("%c",&novosexo);
				    if (novosexo == 'M' || novosexo == 'm' || novosexo == 'F' || novosexo == 'f') {
                        listaProfessor[i].sexo = novosexo;
                    } else{
                        return OPCAO_INVALIDA;
                    }		
				}else if(opcao != 'N' && opcao != 'n'){
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
int excluirProfessor(Professor listaProfessor[], int qtdProfessor){
	printf("Excluir Professor\n");
 	printf("Digite a matricula\n");
	int matricula;
	scanf("%d",&matricula);
	int achou = 0;
	if (matricula < 0){
	    return MATRICULA_INVALIDA;
	}else{
		for (int i = 0; i < qtdProfessor; i++){
			if (matricula == listaProfessor[i].matricula){
				//exclusão lógica
				listaProfessor[i].ativo = -1;
				for (int j = i; j < qtdProfessor - 1; j++){//esse metodo de mover para casa anterior se chama Shift
					listaProfessor[j].matricula = listaProfessor[j+1].matricula;
					listaProfessor[j].sexo = listaProfessor[j+1].sexo;
					listaProfessor[j].ativo = listaProfessor[j+1].ativo;
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

int menuDisciplina(){
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
int cadastrarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina){
    printf("Cadastrar Professor\n");
	if(qtdDisciplina == TAM_DISCIPLINA){
		return LISTA_CHEIA;
	}else{
	    getchar();
	    printf("Informe o nome:\n");
	    char nome[50];
	    fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = 0;
        strcpy(listaDisciplina[qtdDisciplina].nome, nome);
		printf("Digite o codigo:\n");
		int codigo;
		scanf("%d",&codigo);
 		if (codigo < 0){
 			return CODIGO_INVALIDO;
		}
	 	listaDisciplina[qtdDisciplina].codigo = codigo;
		listaDisciplina[qtdDisciplina].ativo = 1;	
		return  CAD_DISC_SUCESSO;
	} 
}
void listarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina){
	printf("Listar Disciplina\n");
	if (qtdDisciplina == 0){
		printf("Lista de disciplinas vazia\n");
	}else{
		for (int i = 0; i < qtdDisciplina; i++){
 			if (listaDisciplina[i].ativo == 1){
				printf("Nome: %s    Codigo: %d\n", listaDisciplina[i].nome, listaDisciplina[i].codigo);
			}
		}
	}    
}
int atualizarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina){
	printf("Atualizar Disciplina\n");
	printf("Digite o codigo:\n");
	int codigo;
	scanf("%d",&codigo);
	int achou = 0;
	if (codigo < 0){
		return CODIGO_INVALIDO;
	}else{
		for (int i = 0; i < qtdDisciplina; i++){
			if (codigo == listaDisciplina[i].codigo){
				//atualização
				printf("Digite o novo codigo:\n");
				int novocodigo;
				scanf("%d",&novocodigo);
				if (novocodigo < 0){
		            return CODIGO_INVALIDO;
            	}
            	listaDisciplina[i].codigo = novocodigo;
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
int excluirDisciplina(Disciplina listaDisciplina[], int qtdDisciplina){
	printf("Excluir Disciplina\n");
 	printf("Digite o codigo:\n");
	int codigo;
	scanf("%d",&codigo);
	int achou = 0;
	if (codigo < 0){
	    return CODIGO_INVALIDO;
	}else{
		for (int i = 0; i < qtdDisciplina; i++){
			if (codigo == listaDisciplina[i].codigo){
				//exclusão lógica
				listaDisciplina[i].ativo = -1;
				for (int j = i; j < qtdDisciplina - 1; j++){//esse metodo de mover para casa anterio se chama Shift
					listaDisciplina[j].codigo = listaDisciplina[j+1].codigo;
					listaDisciplina[j].ativo = listaDisciplina[j+1].ativo;
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
