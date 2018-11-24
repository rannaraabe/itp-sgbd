//importando bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bibliotecas/funcoes-check1.h"
#include "bibliotecas/funcoes-check2.h"
#include "bibliotecas/funcoes-check3.h"
#include "bibliotecas/funcoes-check4.h"

int main(void){
	int op_menu;
	
	//limpando o terminal
	system("clear");

	do{
		//menu de navegacao para o usuario		
		printf("\n");
		printf("=================SGDB ITP=================\n");
		printf("| 1 - Criar tabela                       |\n");
		printf("| 2 - Listar tabelas                     |\n");
		printf("| 3 - Criar nova linha na tabela         |\n");
		printf("| 4 - Listar dados de uma tabela         |\n");
		printf("| 5 - Pesquisar valor em uma tabela      |\n");
		printf("| 6 - Apagar valor de uma tabela         |\n");
		printf("| 7 - Apagar uma tabela                  |\n");
		printf("| 0 - Encerrar                           |\n");
		printf("==========================================\n");
		printf("\n");

		printf("Escolha uma opcao: \n");
		//lendo a opcao escolhida pelo usuario
		scanf("%d", &op_menu);

		FILE *arquivo = fopen("arquivos/menu.txt", "r");

		if(op_menu==0){
			//encerrar loop
			break;
		} else if(op_menu==1){
			//criar tabela
			criar_tabela(arquivo);
		} else if(op_menu==2){
			//listar tabela
			listar_tabelas(arquivo);
		} else if(op_menu==3){
			//criar nova linha na tabela
			criar_linha_tabela(arquivo);
		} else if(op_menu==4){
			//listar dados de uma tabela
			listar_dados_tabela(arquivo);
		} else if(op_menu==5){
			//pesquisar valor em uma tabela
		} else if(op_menu==6){
			//apagar valor em uma tabela
		} else if(op_menu==7){
			//apagar uma tabela
			apagar_tabela(arquivo);
		} else {
			//opcao invalida
			printf("Ops, opção inválida!\n");
			op_menu = 0;
		} 
    
	} while(op_menu!=0);

	return 0;
}
