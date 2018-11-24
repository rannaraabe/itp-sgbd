//importando bibliotecas necessarias
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>  //diretorios

//tipo de dado tabela
typedef struct{
        char nome[15];
        char tipo_dado[7];
} dadosTabela;


//funcao pesquisar valor em uma tabela
int pesquisar_valor(FILE *arq){
        //nome tabela
        char nome_tabela[20];
        printf("\nInsira o nome da tabela para realizar a busca: \n");
        scanf("%s", nome_tabela);

        //nome padrao para o arquivo da tabela
        char nome_arquivo[20] = "tabela_";
        strcat(nome_arquivo, nome_tabela);
        strcat(nome_arquivo, ".txt");

        //caminho
        char caminho_arquivo[100] = "arquivos/";
        strcat(caminho_arquivo, nome_arquivo);

        FILE *arquivo = fopen(caminho_arquivo, "r");

        if(arquivo==NULL){
                printf("Opa! Erro ao tentar abrir o arquivo!\n");
                return 0;
        } else {
		printf("\nOpções disponpiveis para busca:\n");
		printf("1. valores maior que o valor informado\n");
		printf("2. valores maior ou igual quer o valor informado\n");
		printf("3. valores igual o valor informado\n");
		printf("4. valores menor que o valor informado\n");
		printf("5. valores menor ou igual que o valor informado\n");
		printf("6. valores próximo ao valor informado [se aplica apenas se a coluna for do tipo string]\n");
	}
}

