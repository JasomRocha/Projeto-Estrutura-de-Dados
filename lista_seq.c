#include <stdio.h>
#include <stdlib.h>
#include "lista_seq.h"

#define MAX 100

//inciar lista sequencial 

Tlista* criar_lista(int x){
	if(x<=0){
		return 0;
	}
	Tlista *list = (Tlista*) malloc(x* sizeof (Tlista));
	if (list == NULL){
		perror("malloc");
		exit(1);
	}
}

void inicia_lista(Tlista *t, int x){
	int i = 0;
	t->ind_ultimo = -1; //indice do último igual a -1 para quando houver a primeira inserção esse indice mudar para zero
	t->quant_elementos = 0; //inicio com quantidade de elementos igual a zero, para facilitar a implementação
	
	for (i=0; i<x; i++){ //preenchendo lista com zeros
		t->lista[i] = 0;
	}	
}

void imprime_lista(Tlista* t, int x){
	int i;
	for(i=0; i<x; i++){
		if(t->lista[i] == 0){
		printf("[\033[31mN\033[0m] ", t->lista[i]);
		} else 
		printf("[\033[44m%d\033[0m]", t->lista[i]);
	}
}

int insere_lista(Tlista* t, int x, int valor, int posicao){
	int i;
	
	if (t->ind_ultimo == (x-1)){
		printf("Lista cheia!\n");
		return 0;
	}
	
	if ((posicao <= 0 ) || (posicao > t->quant_elementos + 1)){
		printf("posicao invalida\n");
		return 0;
	}
	
	else {
		int i;
		for(i = t->ind_ultimo+1; i>= posicao; i--){
				t->lista[i] = t->lista[i-1]; // a posição a frente do vetor vai receber o valor da posicao anterior a ele
		}
		
	t->lista[posicao-1] = valor; 
	t->ind_ultimo++; 	// atualizo o indice 
	t->quant_elementos++; // atualizo a quantidade de elementos
	
		return 1;
	}
}

int remove_lista(Tlista* t, int posicao){
	int i;
	int num;
	
	if(t->ind_ultimo == -1){
		printf("Lista vazia!\n");
		return 0;
	}
	
	if ((posicao <= 0 ) || (posicao > t->quant_elementos)){
		printf("posicao invalida\n");
		return 0;
	}
	
	
	else{
	
		num  = t->lista[posicao-1] ;
		
	for(i = posicao; i<t->quant_elementos; i++){
				t->lista[i-1] = t->lista[i]; // a posição anterior do vetor vai receber o valor da posicao a frente dele
			}
		
		
		t->ind_ultimo--;
		t->quant_elementos--;
		t->lista[t->ind_ultimo+1] = 0;
		
		return num;
	}
}
	 	
int consulta_lista_pos (Tlista *t, int posicao){
	int i;
	
	if ((posicao > t->ind_ultimo+1) || (posicao <= 0)){
		return 0;	
	}
	
	return t->lista[posicao-1];
}

int consulta_lista_valor (Tlista *t, int x, int valor){
	int i;
	int cont = 0;
	int	aux;
	
	
	for (i=0; i<x; i++){
			if (t->lista[i] == valor){
				return i+1;
			} else 
				cont++;
			
			if (cont == x) {
				return 0;
				}
		}
}

int menu(void){
	
	int opcao;
	
	printf("+------------------------------+ \n");
    printf("|       LISTA SEQUENCIAL       | \n");
    printf("|------------------------------| \n");
    printf("| 1. \033[32mInserir\033[0m elementos na lista| \n");
    printf("| 2. \033[31mRemover\033[0m elementos da lista| \n");
    printf("| 3. Consultar por valor       | \n");
    printf("| 4. Consultar por posicao     | \n");
    printf("| 5. \033[33mSair\033[0m                      |\n");
    printf("+------------------------------+ \n");
    printf("\nEscolha uma opcao: ");
	
	scanf("%d", &opcao);	
	
	system("cls");
	
	return opcao;
	
}


