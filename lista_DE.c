#include <stdio.h>
#include <stdlib.h>
#include "lista_DE.h"

// iniciar lista duplamente encadeada

void cria_lista_de(t_Lista *lista){ // crio a lista vazia
	lista->cabeca = NULL; //ponteiro pra primeiro elemento da lista
	lista->cauda = NULL; //ponteiro para o ultimo elemento da lista
	lista->quant_elementos = 0; //quantidade de elementos inicia com zero
}

int lista_vazia_de(t_Lista *lista){ // a lista estara vazia se a variavel quant_elementos nunca tiver sido incrementada
	if (lista->quant_elementos == 0)
		return 1;
	else 
		return 0;
}

int tamanho_lista_de (t_Lista *lista){ // tamanho da lista eh a quantidade de vezes que a variavel quant_elementos foi incrementada
 	return lista->quant_elementos;
}

int insere_lista_inicio_de (t_Lista *lista, int valor){ // insere no inicio da lista quando solicitado pelo usuario ou quando a lista eh vazia

	t_No *novo_no;
	
	novo_no = (t_No*)malloc(sizeof(t_No)); // aloco memoria para um novo no
	
	if (novo_no == NULL){ // caso o malloc retorne NULL nao consegui alocar memoria 
		return 0;
	}
	
	novo_no->conteudo = valor; //seto o conteudo do no com o valor passado pelo usuario  
	novo_no->proximo = lista->cabeca; // se a lista for vazia ele vai apontar pra NULL que eh como inicializamos a lista
	novo_no->anterior = NULL; //primeiro elemento nao tem antecessor, entao sempre aponta para NULL
	
	if(lista->cabeca != NULL){
		lista->cabeca->anterior = novo_no; // caso a lista ja tenha um cabeca, fazemos o antigo cabeca apontar para o novo cabeca 
	}
	
	lista->cabeca = novo_no; // a lista recebe o novo cabeca
	lista->quant_elementos++; // incrementamos a quantidade de elementos da lista 
	
	return 1; //retorna 1 para informar que a criacao do novo no foi feita com exito
}

int insere_lista_meio_de (t_Lista *lista, int pos, int valor){ // insere na posicao informada pelo usuario
	
	t_No *pt, *ct, *novo_no;  //crio ponteiros do tipo no
	int aux = 1;
	
	novo_no = (t_No*)malloc(sizeof(t_No)); //alocamos memoria para o novo no
	
	if (novo_no == NULL){ // caso malloc retorne NULL nao conseguiu recurso para alocar 
		return 0;
	}
	
	pt = lista->cabeca; //ponteiro que recebe a cabeca
	ct = NULL; //ponteiro que recebe NULL e vai receber o anterior de pt
	
	while((aux < pos) && (pt != NULL)){
		ct = pt; //ct recebe o valor anterior de pt 
		pt = pt->proximo; //pt contiuna a caminhar pela lista enquanto nao encontrar a posicao passada pelo usuario ou chegue ao fim da lista 
		aux++; //incrementa aux pois quando encontrar a posicao aux tera o valor da posicao desejada 
	} 
	
	 if ((pos > 1) && (pt == NULL)) { // Verifique se a posição é válida
        printf("ERRO: POSICAO INVALIDA\n");
        free(novo_no); // Libere a memória alocada para o novo nó
        return 0;
    }

    novo_no->conteudo = valor; //seta o conteudo do novo no como 
    novo_no->proximo = pt;
    novo_no->anterior = ct;

    if (ct != NULL) { //se ct nao for o ultimo elemento da lista 
        ct->proximo = novo_no;
    } else {
        lista->cabeca = novo_no; // Se ct for NULL, o novo nó será a nova cabeça da lista
    }

    if (pt != NULL) {
        pt->anterior = novo_no; // Atualize o ponteiro anterior do nó seguinte
    }

    lista->quant_elementos += 1;

    return 1;
}

int insere_lista_fim_de (t_Lista *lista, int valor){ // insere no final da lista, procura o final da lista e insere o novo no  
	
	t_No *pt, *novo_no;
	
	novo_no = (t_No*)malloc(sizeof(t_No)); // aloco memoria para o no
	
	if (novo_no == NULL){ // caso nao consiga malloc retorna NULL
		return 0;	
	}
	
		novo_no->conteudo = valor; 
		pt = lista->cabeca; //ponteiro recebe o cabeca
	
	while (pt->proximo != NULL){
		pt = pt->proximo;	// enquanto nao chegar no fim da lista vai recebendo o proximo 
	}
	
	novo_no->proximo = NULL; //como eh o ultimo elemento, nao tem proximo
	novo_no->anterior = pt; // o anteiror eh o ultimo elemento recebido por pt
	pt->proximo = novo_no; //pt modifica o proximo do elemento que ele aponta, para o novo no 

	lista->cauda = novo_no;	// atualiza o valor da cauda
	lista->quant_elementos++; // incrementa a quantidade de elementos
	
	return 1;		
}

int insere_func_de (t_Lista *lista, int valor, int posicao){ //verifica qual metodo usar com base nas informacoes passadas pelo usario
	
    int  aux, tamanho = lista->quant_elementos;
	
	if(posicao > tamanho+1){ 
		return 0;
	}
	
	if(posicao <= 0 ){
		return 0;
	}

    if ((lista_vazia_de(lista)) || (posicao == 1)){
        aux = insere_lista_inicio_de(lista, valor);
        return aux;
    }
    
    if (posicao == tamanho+1){
        aux = insere_lista_fim_de(lista, valor);
        return aux;
   }
   
   else{
        aux = insere_lista_meio_de(lista, posicao, valor);
        return aux;
   }	
	
}

int remove_lista_de(t_Lista *lista, int posicao, int *valor){
	
	t_No *aux, *pt; 
	int n = 1;
	
	pt=lista->cabeca;
	
	while((n<posicao) && pt->proximo != NULL){
		aux = pt;
		pt = pt->proximo;
		n++;
	}
	
	if(pt == NULL){
		return 0;
	}
	
	*valor = pt->conteudo;
    aux->proximo = pt->proximo;
    
	if (pt->proximo != NULL) { 
        pt->proximo->anterior = aux;
    }
    
    if(pt->proximo == NULL){ //se for o ultimo elemento da lista eu tenho que atualizar a cauda 
    	lista->cauda = aux;
	}

	free(pt); //liberando memoria alocada para os ponteiros para nos   
    lista->quant_elementos--;
	return 1;
}

int remove_cabeca_lista_de(t_Lista *lista, int *valor){
 	
	 t_No *pt;

    pt = lista->cabeca;

    if (pt->proximo == NULL && pt->anterior == NULL) { // A lista contém apenas um elemento, mas não queremos zerá-la
        *valor = pt->conteudo;
        lista->cabeca = NULL;
        lista->cauda = NULL;
    } else {
        *valor = pt->conteudo;
        lista->cabeca = pt->proximo;
        lista->cabeca->anterior = NULL;
    }

    lista->quant_elementos--;
    
	free(pt); // libero a memoria alocada para pt 

    return 1;
}

int remove_func_de (t_Lista *lista, int posicao, int *valor){
	int ret;
	
	if(posicao > lista->quant_elementos){ // se a posicao informada for maior que lista
		return -1;
	}
	
	if(posicao <= 0 ){ // posicao informada igual a zero ou menor 
		return -1;
	}
	
	if(lista_vazia_de(lista)){ // se lista vazia
		return 0;
	}
	
	if (posicao == 1){
		ret = remove_cabeca_lista_de(lista, valor); // se posicao for equivalente ao cabeca
		return ret;
	}
	
	else {
		ret = remove_lista_de(lista, posicao, valor); //qualquer posicao diferente da cabeca, inclusive a cauda
 		return ret;
	}
}

int consulta_pos_de(t_Lista *lista, int posicao, int *valor){
	t_No *pt;
	int n = 1;
	
	if(lista_vazia_de(lista) == 1){ // se alista estiver vazia nao tem o que consultar
		return 0;
	}
	
		
	if( posicao > lista->quant_elementos || posicao <= 0){ //tratamento de erro
		return -1;
	}
	
	pt = lista->cabeca; // ponteiro que caminha na lista 
	
	while(pt != NULL && (n<posicao)){
		pt = pt->proximo;
		n++;
	}
	
	if(pt == NULL){
		return 0;
	}
	
	*valor = pt->conteudo;
	
	return *valor;
}	
	
int consulta_cont_de(t_Lista *lista, int valor){ 

	t_No *pt;
	int n = 1;
	
	if(lista_vazia_de(lista) == 1){
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

void imprime_lista_de (t_Lista* lista) { 	
	
	t_No *pt, *nt;
	char vazio = '\233'; 
	int elementos = lista->quant_elementos;
	int i;
		if(lista->quant_elementos == 0){
			printf("<< LISTA VAZIA >>");
		}
	
			
		pt = lista->cabeca;
		nt = lista->cauda;
		
		for(i=0; i<elementos && pt != NULL; i++){
			
			if(pt->proximo != NULL && pt->anterior != NULL)
				printf("[\033[0m\033[33m%#lx\033[0m|\033[44m%d\033[0m|\033[33m%#lx\033[0m]<->", (unsigned long*)pt->anterior, pt->conteudo, (unsigned long*)pt->proximo);
	
			if(pt->proximo != NULL && pt->anterior == NULL)
				printf("[%c|\033[44m%d\033[0m|\033[0m\033[33m%#lx\033[0m]<->", vazio, pt->conteudo, (unsigned long*)pt->proximo);
			
			if(pt->proximo == NULL && pt->anterior != NULL)
				printf("[\033[0m\033[33m%#lx\033[0m|\033[44m%d\033[0m|%c]\n", (unsigned long*)pt->anterior, pt->conteudo, vazio);
			
			if(pt->proximo == NULL && pt->anterior == NULL)
				printf("[%c|\033[44m%d\033[0m|%c]\n", vazio, pt->conteudo, vazio);
			
			pt = pt->proximo;
		}
			if (nt != NULL) 			
        		printf("\nINFORMACOES DA LISTA:\nCABECA:[\033[31m%d|\033[33m%#lx\033[0m\033[0m] |CAUDA:[%\033[31m%d|\033[33m%#lx\033[0m\033[0m]|TAMANHO LISTA:[%\033[31m%d\033[0m]\n", lista->cabeca->conteudo, (unsigned long*)lista->cabeca, lista->cauda->conteudo, (unsigned long*)lista->cauda, lista->quant_elementos);
    
}

int menu_de(void){	
	int opcao;
	
	printf("+------------------------------+ \n");
    printf("¦  LISTA DUPLAMENTE ENCADEADA  ¦ \n");
    printf("¦------------------------------¦ \n");
    printf("¦ 1. \033[32mInserir\033[0m elementos na lista¦ \n");
    printf("¦ 2. \033[31mRemover\033[0m elementos da lista¦ \n");
    printf("¦ 3. Consultar por valor       ¦ \n");
    printf("¦ 4. Consultar por posicao     ¦ \n");
    printf("¦ 5. \033[33mSair\033[0m                      ¦ \n");
    printf("+------------------------------+ \n");
    printf("\nEscolha uma opcao: ");
	
	scanf("%d", &opcao);	
	
	system("cls");
	
	return opcao;
	
}

