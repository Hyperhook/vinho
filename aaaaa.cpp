#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Fila
typedef struct Node{
	struct Registro *registro;
	struct Node *next;
} Node;

//Data
typedef struct Data{
	int dia;
	int mes;
	int ano;
} Data;

//Registro
typedef struct Registro{
	int codigo;
	char nome[255];
	struct Data *data;
} Registro;


Data *iniciar_data(){
	Data *data = (Data*)malloc(sizeof(Data));
	return data;
}

Registro *iniciar_registro(){
	Registro *reg = (Registro*)malloc(sizeof(Registro));
	reg->data = iniciar_data();
	return reg;
}

void inserir_registro(Node *head){
	Node *current = head;
	int codigo = 1;
	char name[255];
	int dia, mes, ano;
	
	while(current->next != NULL){
		current = current->next;
		codigo++;
	}
	
	current->next = (Node*)malloc(sizeof(Node));
	current->next->next = NULL;
	current->registro = iniciar_registro();
	
	printf("Inserir o nome do produto: ");
	scanf("%s", &current->registro->nome);
	printf("Inserir dia: ");
	scanf("%d", &current->registro->data->dia);
	printf("Inserir mes: ");
	scanf("%d", &current->registro->data->mes);
	printf("Inserir ano: ");
	scanf("%d", &current->registro->data->ano);
	current->registro->codigo = codigo;
	
	printf("Nome: %s\nCodigo: %i\nDia: %i\nMes: %i\nAno: %i\n",
	current->registro->nome,
	current->registro->codigo,
	current->registro->data->dia,
	current->registro->data->mes,
	current->registro->data->ano);
}


void remover_registro(Node **head, int codigo){
	Node *current, *prev;
	
	prev = NULL;
	
	for(current = *head; current != NULL; prev=current, current=current->next){
		if(current->registro->codigo == codigo){
			if(prev == NULL){
				*head = current->next;
			}
			else{
				prev->next = current->next;
			}
			free(current->registro->data);
			free(current->registro);
			free(current);
			break;
		}
	}
}

void pesquisa_codigo(Node *head){
	Node *current = head;
	int codigo;
	
	printf("Insira o codigo do produto: ");
	scanf("%d", &codigo);
	
	if(current->registro->codigo == codigo){
		printf("\nProduto: %s\nData: %i/%i/%i\n\n", 
		current->registro->nome, 
		current->registro->data->dia,
		current->registro->data->mes,
		current->registro->data->ano);
		return;
	}
	
	while(current->next != NULL){
		if(current->registro->codigo == codigo){
			printf("Produto: %s\nData: %i/%i/%i",
			current->registro->nome, 
			current->registro->data->dia,
			current->registro->data->mes,
			current->registro->data->ano);
			break;
		}
		current = current->next;
	}
	
	printf("O item nao foi encontrado\n\n");
}

void qtd_items(Node *head){
	Node *current = head;
	int counter = 0;
	
	if(current->registro != NULL && current->next == NULL){
		counter++;
		printf("Items: %i\n\n", counter);
		return;
	}
	
	while(current->next != NULL && current->registro != NULL){
		current = current->next;
		counter++;
	}
	printf("Items: %i\n\n", counter);
}

void pesquisa_nome(Node *head){
	Node *current = head;
	char nome[255];
	
	printf("Insira o codigo do produto: ");
	scanf("%s", &nome);
	
	if(current->registro->nome == nome){
		printf("\nProduto: %s\nData: %i/%i/%i\n\n", 
		current->registro->nome, 
		current->registro->data->dia,
		current->registro->data->mes,
		current->registro->data->ano);
		return;
	}
	
	while(current->next != NULL){
		if(current->registro->nome == nome){
			printf("Produto: %s\nData: %i/%i/%i",
			current->registro->nome, 
			current->registro->data->dia,
			current->registro->data->mes,
			current->registro->data->ano);
			break;
		}
		current = current->next;
	}
}

void menu(){
	printf("SISTEMA DE CONTROLE DE VINHOS\n");
	printf("[1] Incluir registro\n");
	printf("[2] Pesquisar por codigo\n");
	printf("[3] Pesquisar por nome\n");
	printf("[4] Alterar dados\n");
	printf("[5] Remover registro\n");
	printf("[8] Quantidade de items\n");
	printf("[6] Imprimir relatorio geral\n");
	printf("[7] Sair\n");
}

void inserir_registro(Node *head);
void pesquisa_codigo(Node *head);
void pesquisa_nome(Node *head, char nome[]);
void qtd_items(Node *head);

int main(void){
	//FILE *fptr;
	
	//Arquivo nao existe
	/*if((fptr = fopen("./test.txt", "r")) == NULL){
		printf("Arquivo nao encontrado!\nCriando arquivo...\n");
		fptr = fopen("./hehehe.txt", "w");
		fclose(fptr);
		
		Node *head = (Node*)malloc(sizeof(Node));
	}
	//Arquivo existe
	else{
		//logica de leitura das linhas
		return 0;
	}*/
	printf("Seja bem-vindo!\n");
	int exec;
	Node *head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	do{
		menu();
		printf("Inserir opcao: ");
		scanf("%i", &exec);
		switch(exec){
		case 1:
			printf("1\n");
			inserir_registro(head);
			break;
		
		case 2:
			printf("2\n");
			pesquisa_codigo(head);
			break;
			
		case 3:
			printf("3\n");
			pesquisa_nome(head);
			break;
			
		case 4:
			printf("4\n");
			//alterar_dados();
			break;
			
		case 5:
			int codigo;
			printf("Inserir o codigo do produto a ser deletado: ");
			scanf("%d", &codigo);
			remover_registro(&head, codigo);
			break;
			
		case 6:
			printf("6\n");
			//relatorio();
			break;
			
		case 7:
			printf("7\n");
			break;
		
		case 8:
			qtd_items(head);
			break;
		
		default:
			printf("Opcao invalida\n");
		}
	}
	while(exec != 7);
	
	return 0;
}
