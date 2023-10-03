#ifndef LISTAS_SE_H   // guardas de cabecalho, impedem inclusoes ciclicas
#define LISTAS_SE_H


//declaracoes dos prototipos das funcoes


typedef struct t_lista{  // estrutura da lista 
	struct t_no *cabeca;
	int quant_elementos; // essa variavel ira ajudar na implemetacao dos metodos
}t_lista;

typedef struct t_no {  // estrutura do no que possui o conteudo do no e um ponteiro que aponta para uma estrutura do tipo no 
	int conteudo;
	struct t_no* proximo; 		
}t_no;

void cria_lista_se (t_lista *lista);
int lista_vazia_se (t_lista *lista);
int tamanho_lista_se (t_lista *lista);
int insere_lista_inicio_se (t_lista *lista, int valor);
int insere_lista_meio_se (t_lista *lista, int pos, int valor);
int insere_lista_fim_se (t_lista *lista, int valor);  
int insere_func (t_lista *lista, int valor, int posicao);
void imprime_lista_se (t_lista *lista);	
int remove_lista_se(t_lista *lista, int posicao, int *valor);
int remove_cabeca_lista_se(t_lista *lista, int *valor);
int remove_func (t_lista *lista, int posicao, int *valor);
int consulta_pos_se(t_lista *lista, int posicao, int *valor);
int consulta_cont_se(t_lista *lista, int valor);
int menu_se(void);
	
#endif

 
