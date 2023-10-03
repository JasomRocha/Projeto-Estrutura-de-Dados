#include <stdio.h>
#include <stdlib.h>
#include "lista_SE.h"

//iniciar lista simplesmente encadeada

void cria_lista_se (t_lista *lista){ // crio a lista vazia, setando o primeiro a lista para apontar para zero e quantidade de elementos tambem igual a zero
	lista->cabeca = NULL;
	lista->quant_elementos = 0;
}

int lista_vazia_se (t_lista *lista){ // a lista estara vazia se a variavel quant_elementos nunca tiver sido incrementada
	if (lista->quant_elementos == 0)
		return 1;
	else 
		return 0;
}

int tamanho_lista_se (t_lista *lista){ // tamanho da lista eh a quantidade de vezes que a variavel quant_elementos foi incrementada
 	return lista->quant_elementos;
}

int insere_lista_inicio_se (t_lista *lista, int valor){ // insere no inicio da lista quando solicitado pelo usuario ou quando a lista eh vazia
	t_no *novo_no;
	
	novo_no = (t_no*)malloc(sizeof(t_no));
	
	if (novo_no == NULL){
		return 0;
	}
	
	novo_no->conteudo = valor;  
	novo_no->proximo = lista->cabeca; // se a lista for vazia ele vai apontar pra NULL que ? como inicializamos a lista
	lista->cabeca = novo_no; // a lista recebe o novo cabeca
	lista->quant_elementos++;
	
	return 1; //retorna 1 para informar que a criacao do novo no foi feita com exito
}

int insere_lista_meio_se (t_lista *lista, int pos, int valor){ // insere na posicao informada pelo usuario
	t_no *pt, *novo_no; 
	int aux = 1;
	
	novo_no = (t_no*)malloc(sizeof(t_no));
	if (novo_no == 0){
		return 0;
	}
	
	pt = lista->cabeca;
	
	while((aux < pos-1) && (pt != NULL)){ // enquanto aux nao chegar na posicao anterior a pt recebe o dado do proximo elemento 
		pt = pt->proximo; 
		aux++;
	} 
	
	if (pt == NULL){ // se pt chegar no final da lista a posicao eh invalida
		printf("ERRO: POSICAO INVALIDA\n");
		return 0;
	}
	
	novo_no->conteudo = valor; 
	novo_no->proximo = pt->proximo;
	pt->proximo = novo_no;
	lista->quant_elementos += 1;
	
	return 1;
}

int insere_lista_fim_se (t_lista *lista, int valor){ // insere no final da lista, procura o final da lista e insere o novo no  
	t_no *pt, *novo_no;
	
	novo_no = (t_no*)malloc(sizeof(t_no));
	
	if (novo_no == NULL){
		return 0;	
	}
	
	novo_no->conteudo = valor;
	pt = lista->cabeca;
	
	while (pt->proximo != NULL){
		pt = pt->proximo; // pt vai ate o ultimo elemento da lista 
	}
	
	pt->proximo = novo_no; // faz o ultimo elemento apontar para o novo no 
	novo_no->proximo = NULL;	//novo no nao tem proximo
	lista->quant_elementos++; // incremento a quantidade de elementos
	
	return 1;		
}

int insere_func (t_lista *lista, int valor, int posicao){ //verifica qual metodo usar com base nas informacoes passadas pelo usario

	t_no *p, *novoNo;
    int  aux, tamanho = lista->quant_elementos;

    if(posicao > lista->quant_elementos+1){ // tratamento de erros
		return 0;
	}
	
	if(posicao <= 0){ //tratamento de erros
		return 0;
	}
	
	if(posicao <= 0){
		return 0;
	}
   
    if ((lista_vazia_se(lista)) || (posicao == 1)){  //se a lista for vazia ou a posicao passada for a cabeca 
        aux = insere_lista_inicio_se(lista, valor);
        return aux;
    }
    
    if (posicao == tamanho+1){ // se aposicao passada for maior que a lista em 1 é a ultima posicao da lista 
        aux = insere_lista_fim_se(lista, valor);
        return aux;
   }
   
   else{
        aux = insere_lista_meio_se(lista, posicao, valor); //qualquer outra posicao sera pelo meio da lista
        return aux;
   }	
	
}

int remove_lista_se(t_lista *lista, int posicao, int *valor){
	t_no *aux, *pt; //pra remocao eu preciso de um ponteiro auxiliar 
	int n = 1;
	
	pt=lista->cabeca;
	
	while((n<posicao) && pt->proximo != NULL){ // enquanto n for menor que a posicao informada pelo usuario e pt nao chegar no final da lista  
		aux = pt; // aux aponta para o antecessor de pt
		pt = pt->proximo; // pt aponta para o proximo elemento da lista
		n++; //incremento o contador que representa o indice
	}
	
	if(pt == NULL){
		return 0; //pt encontrou o ultimo elemento 
	}
	
	*valor = pt->conteudo; // encontrei a posicao, pego o conteudo no a ser excluido, caso preciso procesa-lo de alguma forma 
	aux->proximo = pt->proximo; //o anterior ao no exluido aponta para o proximo dele, excluindo a referencia para este no da lista  
	lista->quant_elementos--; //decremento a quantidade de elementos 
	
	free(pt); //libero memoria alocada para pt;
	return 1;
}

int remove_cabeca_lista_se(t_lista *lista, int *valor){
	t_no *pt; 

	pt = lista->cabeca; // ponteiro para o primeiro elemento da lista
	
	*valor = pt->conteudo; //valor vai receber o conteudo, caso precise pra algum processamento 
	lista->cabeca = pt->proximo; //atuliza o cabeca para o proximo do antigo cabeca 
	lista->quant_elementos--; //decrementa a quantidade de elementos 

	free(pt);
	return 1;
}

int remove_func (t_lista *lista, int posicao, int *valor){
	t_no *pt, *aux; 
	int ret;
	
	if(posicao > lista->quant_elementos){ //tratativa de erro
		return 0;
	}
	
	if(posicao <= 0){ // tratativa de erro
		return 0;
	}
	
	
	if(lista_vazia_se(lista)){ //se lista for vazia nao tem o que remover 
		return 0;
	}
	
	if (posicao == 1){ // posicao igual 1 remove o cabeca
		ret = remove_cabeca_lista_se(lista, valor);
		return ret;
	}
	
	else { // se nao for removo pelo meio da lista ou no fim
		ret = remove_lista_se(lista, posicao, valor);
		return ret;
	}
}

int consulta_pos_se(t_lista *lista, int posicao, int *valor){
	t_no *pt;
	int n = 1;
	
 	if(lista_vazia_se(lista) == 1){ //se lista for vazia nao tem o que consultar
		return 0;
	}
	
	if( posicao > lista->quant_elementos || posicao <= 0){ //tratativa de erro
		return -1;
	}
	
	pt = lista->cabeca; // ponteiro que vai caminhar pela lista
	
	while(pt != NULL && (n<posicao)){ 
		pt = pt->proximo;
		n++;
	}
	
	if(pt == NULL){ //chegou no final da lista 
		return 0;
	}
	
	*valor = pt->conteudo; //valor recebe o conteudo do no removido, caso precise fazer algum processamento 
	
	return *valor;
}	
	
int consulta_cont_se(t_lista *lista, int valor){
	t_no *pt;
	int n = 1;
	
	if(lista_vazia_se(lista) == 1){
		return 0;
	}
	
	pt = lista->cabeca;
	
		while(pt != NULL){
			if(pt->conteudo == valor){
				return n;
			}
		
		pt = pt->proximo;
		n++;
	}
	
}

void imprime_lista_se (t_lista* lista) { 	
	
	t_no *pt;
	char vazio = '\233'; 
	int elementos = lista->quant_elementos;
	int i;
		
		if(lista->quant_elementos == 0){
			printf("<< LISTA VAZIA >>");
		}
	
		pt = lista->cabeca;
		
		for(i=0; i<elementos && pt != NULL; i++){
			
			if(pt->proximo != NULL)
				printf("[\033[44m%d\033[0m|\033[0m\033[33m%#lx\033[0m]->", pt->conteudo, (unsigned long*)pt->proximo);
	
			else{
				printf("[\033[44m%d\033[0m|\033[0m\033[33m%c\033[0m]\n", pt->conteudo, vazio);
			}
			pt = pt->proximo;
		}
			if(lista->cabeca != NULL)
			printf("\nINFORMACOES DA LISTA:\nCABECA:[\033[31m%d|\033[33m%#lx\033[0m\033[0m] | TAMANHO LISTA:[%\033[31m%d\033[0m]\n", lista->cabeca->conteudo, (unsigned long*)lista->cabeca, lista->quant_elementos);
}

int menu_se(void){	
	int opcao;
	
	printf("+------------------------------+ \n");
    printf("| LISTA SIMPLESMENTE ENCADEADA | \n");
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






