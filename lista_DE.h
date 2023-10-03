#ifndef LISTAS_DE_H   // guardas de cabecalho, impedem inclusoes ciclicas
#define LISTAS_DE_H


//declaracoes dos prototipos das funcoes


typedef struct t_Lista{   
	struct t_No* cabeca;
	struct t_No* cauda;
	int quant_elementos; 
}t_Lista;

typedef struct t_No {   
	int conteudo;
	struct t_No* proximo; 
	struct t_No* anterior;		
}t_No;

void cria_lista_de(t_Lista *lista); 
int lista_vazia_de(t_Lista *lista);
int tamanho_lista_de (t_Lista *lista);
int insere_lista_inicio_de (t_Lista *lista, int valor);
int insere_lista_meio_de (t_Lista *lista, int pos, int valor);
int insere_lista_fim_de (t_Lista *lista, int valor);
int insere_func_de (t_Lista *lista, int valor, int posicao);
int remove_lista_de(t_Lista *lista, int posicao, int *valor);
int remove_cabeca_lista_de(t_Lista *lista, int *valor);
int remove_func_de (t_Lista *lista, int posicao, int *valor);
int consulta_pos_de(t_Lista *lista, int posicao, int *valor);	
int consulta_cont_de(t_Lista *lista, int valor);
void imprime_lista_de (t_Lista* lista); 	
int menu_de(void);

#endif
