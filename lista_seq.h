#ifndef LISTAS_SEQ_H   // guardas de cabecalho, impedem inclusoes ciclicas
#define LISTAS_SEQ_H

#define MAX 100 //lista sequencial tem tamanho maximo

//declaracao dos prototipos das funcoes


typedef struct {
	int lista[MAX]; //vetor que contem a lista 
	int ind_ultimo; //indice do ultimo elemento
	int quant_elementos;
}Tlista;

void inicia_lista(Tlista *t, int x);	
void imprime_lista(Tlista* t, int x);
int insere_lista(Tlista* t, int x, int valor, int posicao);	
int remove_lista(Tlista* t, int posicao);	 	
int consulta_lista_pos (Tlista *t, int posicao);
int consulta_lista_valor (Tlista *t, int x, int valor);
int menu(void);

#endif
