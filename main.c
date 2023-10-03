#include <stdio.h>
#include <stdlib.h>
#include "lista_seq.h" //inclusao do headers para chamada de funcoes
#include "lista_SE.h"
#include "lista_DE.h"



int main(int argc, char *argv[]) { // funcao principal 
	int escolha;
	
	do{ 
			
	printf("+--------------MENU--------------+\n"); // Menu principal
 	printf("|       \033[33mSELECIONE UMA OPCAO\033[0m      |\n");
	printf("|1- LISTA SEQUENCIAL             |\n");
	printf("|2- LISTA SIMPLESMENTE ENCADEADA |\n");
	printf("|3- LISTA DUPLAMENTE ENCADEADA   |\n");
	printf("|\033[31m0- SAIR\033[0m                         |\n");
	printf("+--------------------------------+\n");
	printf("\nEscolha uma opcao: ");

	scanf("%d", &escolha);	
	
	system("cls");
	
	
	if(escolha == 1){ 
	
	int tam_lista;
	int num, opcao=0;
	
	printf("informe o tamanho da lista:");
	scanf("%d", &tam_lista);
	system("cls");
	
	Tlista *list = criar_lista(tam_lista); //chamo a funcao criar lista, que ira alocar memoria para a lista e reotornar um endereco, ou um erro.
	
	if(list == 0){
		printf("ERRO: NAO E POSSIVEL CRIAR LISTA COM ESSE TAMANHO\n");
		getchar();
		getchar();
		system("cls");
	}
	
	inicia_lista(list, tam_lista);

	system("cls");
	
	do{
	
	opcao = menu();
	
	if(opcao == 1){ //Inserir elementos na lista 
		int valor_insere; //variavel de teste
		int posicao_insere;
		
		printf("Valor: ");
			scanf("%d", &valor_insere);
		printf("posicao: ");
			scanf("%d", &posicao_insere);
		
		int retorno_inserir = insere_lista(list, tam_lista, valor_insere, posicao_insere); //chamada da funcao inserir
		
		if(retorno_inserir == 0){
			printf("Nao foi possivel inserir!\n");
			getchar();
			getchar();
		}
		
		else 
		system("cls");
			printf("LISTA ATUAL >>> ");
			imprime_lista(list, tam_lista);
				getchar();
				getchar();
		system("cls");
	}
	
	if(opcao == 2){ //Remover elementos da lista
		int posicao_remove; 
		int removido; // variavel de teste
		
		imprime_lista(list, tam_lista);
			printf(">>>> posicao para remover:");
				scanf("%d", &posicao_remove);
		
			removido = remove_lista(list, posicao_remove); //chamada da funcao remove_lista
		
		if (removido == 0){
			printf("Nao foi possivel remover!\n");
			getchar();
			getchar();
			system("cls");
		}
		
		else{
		printf("<<<< %d foi removido >>>\n", removido);
		printf("LISTA ATUAL >>> ");
			imprime_lista(list, tam_lista);
				getchar();
				getchar();
		system("cls");
		}
	}	
		
	if(opcao == 3){ //consultar por valor
		int aux;
		int valor_consulta;
		
		printf("informe o valor que voce deseja consultar na lista: ");
			scanf("%d", &valor_consulta);
			
		aux = consulta_lista_valor(list, tam_lista, valor_consulta);
		
		if (aux == 0){
			printf("ERRO: ELEMENTO NAO ESTA NA LISTA\n");
		} 
		
		else 
			printf("o valor %d esta na posicao: %d\n", valor_consulta, aux);
			printf("LISTA ATUAL >>> ");
			imprime_lista(list, tam_lista);
			getchar();
			getchar();	
			system("cls");
	}	
		
	if(opcao == 4){ //consultar por posicao 
		
		int aux;
		int posicao_consulta;
		
		printf("informe a posicao que voce deseja consultar na lista: ");
			scanf("%d", &posicao_consulta);
			
		aux = consulta_lista_pos(list, posicao_consulta);
		
		if (aux == 0){
			printf("ERRO: POSICAO INVALIDA\n");
		} 
		
		else 
			printf("A posicao %d contem o inteiro %d\n", posicao_consulta, aux);
			printf("LISTA ATUAL >>> ");
			imprime_lista(list, tam_lista);	
			getchar();
			getchar();
			system("cls");
	}	
	
		
	} while(opcao != 5);

	}
	
	
	if(escolha == 2){ // Aqui comeca a logica de listas simplesmete encadeadas
	t_lista lista;
	int aux;
	int rec;
	
	cria_lista_se(&lista);
	
	do {
		int valor, posicao,test;
		rec = menu_se();
		
		
		if(rec == 1){
		printf("TAMANHO DA LISTA: %d\n\n", lista.quant_elementos);	
		printf("LISTA ATUAL: ");
			imprime_lista_se(&lista);
			getchar();
			getchar();
			system("cls");
			printf("Valor: ");
				scanf("%d", &valor);
			printf("posicao: ");
				scanf("%d", &posicao);
			
			test = insere_func(&lista, valor, posicao);
			
			if(test == 0){
				printf("ERRO: NAO FOI POSSIVEL CRIAR O NOVO NO\n");
				getchar();
				getchar();
				system("cls");	
			}
			else {
				system("cls");
				printf("LISTA ATUAL>> ");
				imprime_lista_se(&lista);
				getchar();
				getchar();
				system("cls");
			}
		}
	
		if(rec == 2){
			printf("TAMANHO DA LISTA: %d\n\n", lista.quant_elementos);
			printf("LISTA ATUAL: ");
			imprime_lista_se(&lista);
			getchar();
			getchar();
			system("cls");
			if(lista_vazia_se(&lista)){
				printf("ERRO: NAO FOI POSSIVEL REMOVER O NO\n");
				getchar();
				getchar();
				system("cls");
			}
			else{
			
			printf("posicao: ");
				scanf("%d", &posicao);
			
			test = remove_func(&lista, posicao, &valor);
			
			if(test == 0){
				printf("ERRO: NAO FOI POSSIVEL REMOVER O NO SOLICITADO\n");	
				getchar();
				getchar();
				system("cls");
			}
			else {
				system("cls");
				printf("LISTA ATUAL>> ");
				imprime_lista_se(&lista);
				getchar();
				getchar();
				system("cls");
				}
			}
		}
	
		if(rec == 3){
			printf("TAMANHO DA LISTA: %d\n\n", lista.quant_elementos);
			int valor;
			system("cls");
			printf("Valor: ");
				scanf("%d", &valor);
			
			int test = consulta_cont_se(&lista, valor);
			
			if(test == 0){
				printf("ERRO: O VALOR NAO ESTA NA LISTA\n");	
				getchar();
				getchar();
				system("cls");
			}
			else {
				system("cls");
				printf(">>>>\033[32mRESULTADO DA PESQUISA:\033[0m O VALOR \033[44m%d\033[0m ESTA NA POSICAO %d\n\n", valor, test);
				printf("LISTA ATUAL>> ");
				imprime_lista_se(&lista);
				getchar();
				getchar();
				system("cls");
			}
		}
		
		if(rec == 4){
			printf("TAMANHO DA LISTA: %d\n\n", lista.quant_elementos);
			int posicao;
			system("cls");
			printf("POSICAO: ");
				scanf("%d", &posicao);
			int valor;
			consulta_pos_se(&lista, posicao, &valor);
			
			if(valor == -1){
				printf("ERRO:POSICAO INVALIDA\n");	
				getchar();
				getchar();
				system("cls");
			}
			
			if(valor == 0){
				printf("ERRO:POSICAO INVALIDA\n");	
				getchar();
				getchar();
				system("cls");
			}
			else {
				system("cls");
				printf(">>>>\033[32mRESULTADO DA PESQUISA:\033[0mA POSICAO %d CONTEM O VALOR \033[44m%d\033[0m\n\n", posicao, valor);
				printf("LISTA ATUAL>> ");
				imprime_lista_se(&lista);
				getchar();
				getchar();
				system("cls");
			}
			
		}	

	} while (rec != 5);
	
			
	}
	
	
	if(escolha == 3){ //Aqui comeca a logica de lista duplamente encadeada
		t_Lista lista;
		int aux;
		int rec;
	
		cria_lista_de(&lista); //criacao da lista, atraves de chamada de funcao
	
		do {
			int valor, posicao, test;
			rec = menu_de();
		
		
			if(rec == 1){
				printf("TAMANHO DA LISTA: %d\n\n", lista.quant_elementos);	
				printf("LISTA ATUAL: ");
					imprime_lista_de(&lista); 
					getchar();
					getchar();
					system("cls");
					printf("Valor: ");
						scanf("%d", &valor);
					printf("posicao: ");
						scanf("%d", &posicao);
			
			test = insere_func_de(&lista, valor, posicao); //insercao do elemento na lista
			
				if(test == 0){
					printf("ERRO: NAO FOI POSSIVEL CRIAR O NOVO NO\n");	
					getchar();
					getchar();
					system("cls");
				}
				else {
					system("cls");
					printf("LISTA APOS INSERCAO>> ");
					imprime_lista_de(&lista);
					getchar();
					getchar();
					system("cls");
			}
		}
	
			if(rec == 2){
				printf("TAMANHO DA LISTA: %d\n\n\n", lista.quant_elementos);
				printf("LISTA ATUAL: ");
				imprime_lista_de(&lista);
				getchar();
				getchar();
				system("cls");
				if(lista_vazia_de(&lista)){
					printf("ERRO: NAO FOI POSSIVEL REMOVER O NO\n");
					getchar();
					getchar();
					system("cls");
				}
				else{
			
					printf("posicao: ");
						scanf("%d", &posicao);
			
					test = remove_func_de(&lista, posicao, &valor);
			
					if(test == 0 || test == -1){
						printf("ERRO: NAO FOI POSSIVEL REMOVER O NO SOLICITADO\n");	
						getchar();
						getchar();
						system("cls");
				}
					else {
						system("cls");
						printf("LISTA APOS REMOCAO>> ");
						imprime_lista_de(&lista);
						getchar();
						getchar();
						system("cls");
				}
			}
		}
	
		if(rec == 3){
			printf("TAMANHO DA LISTA: \033[44m%d\033[0m\n\n\n", lista.quant_elementos);
			int valor;
			system("cls");
			printf("Valor: ");
				scanf("%d", &valor);
			
			int test = consulta_cont_de(&lista, valor);
		
			if(test == 0){
				printf("ERRO: O VALOR NAO ESTA NA LISTA\n");	
				getchar();
				getchar();
				system("cls");
			}
			else {
				system("cls");
				printf(">>>>\033[32mRESULTADO DA PESQUISA:\033[0m O VALOR \033[44m%d\033[0m ESTA NA POSICAO %d\n\n", valor, test);
				printf("LISTA ATUAL>> ");
				imprime_lista_de(&lista);
				getchar();
				getchar();
				system("cls");
			}
		}
		
		if(rec == 4){
			printf("TAMANHO DA LISTA: %d\n\n\n", lista.quant_elementos);
			int posicao;
			system("cls");
			printf("POSICAO: ");
				scanf("%d", &posicao);
			int valor;
				
				consulta_pos_de(&lista, posicao, &valor);
			
			if(valor == -1){
				printf("ERRO:POSICAO INVALIDA\n");	
				getchar();
				getchar();
				system("cls");
			}
			
				
			if(valor == 0){
				printf("ERRO:POSICAO INVALIDA\n");	
				getchar();
				getchar();
				system("cls");
			}
			else {
				system("cls");
				printf(">>>>\033[32mRESULTADO DA PESQUISA:\033[0mA POSICAO %d CONTEM O VALOR \033[44m%d\033[0m\n\n", posicao, valor);
				printf("LISTA ATUAL>> ");
				imprime_lista_de(&lista);
				getchar();
				getchar();
				system("cls");
				}
			
			}	

		} while (rec != 5);

	}
		
	}while(escolha != 0);
	
	printf("PROGRAMA FINALIZADO!!!\n");
	printf("ALUNO: JASOM ISRAEL ROCHA SANTOS\n");
	printf("MATRICULA: 20170171760\n");
	printf("DISCIPLINA: ESTRUTURA DE DADOS\n");
	printf("PROFESSOR: TIAGO MARITAN UGULINO DE ARAUJO\n");
	printf("REFERENCIAS: Szwarcfiter, J. L., & Markenzon, L. (2020). Estrutura de Dados e seus Algoritmos (3ª edicao). Editora LTC.\n");
	getchar();
	getchar();
	system("cls");
	
	return 0;
} 
	

