//importando bibliotecas necessarias
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//funcao apagar uma linha de uma tabela
int apagar_linha(FILE *arq){
	char nome_tabela[20];
	char c, quebra = '\n';
	int linhas = 0, cont = 1, op = 0;
		
	printf("Insira o nome da tabela que deseja apagar: \n");
	scanf("%s", nome_tabela);

	char nome_arquivo[50] = "tabela_";
	strcat(nome_arquivo, nome_tabela);
	strcat(nome_arquivo, ".txt");

	char caminho_arquivo[100] = "arquivos/";
	strcat(caminho_arquivo, nome_arquivo);

	FILE *arquivo = fopen(caminho_arquivo, "r");
	FILE *new = fopen("arquivos/new.txt", "w");

	if(arquivo==NULL){
		system("clear");
		printf("O arquivo nao existe!\n");    
		return 0;
	} else {
		//pegando a quantidade de linhas do arquivo
		while(fread(&c, sizeof(char), 1, arquivo)) {
			if(c == quebra) {
				linhas++;
			}
		}

		printf("\nEscolha uma opcao:\n1.Apagar uma linha inteira\n2.Apagar um valor especifico\n");
		scanf("%d", &op);
		
		int chave_primaria;
		printf("\nValor da chave: ");
		scanf("%d", &chave_primaria);
		
		rewind(arquivo);
		if(op==1){
			char texto_linha[100];
			char ch = getc(arquivo);

			while(ch != EOF){
				if(cont!=(chave_primaria+1)){
					putc(ch, new);
				}
				ch = getc(arquivo);
				
				if(ch == '\n'){
					cont++;
				}
			}

			fclose(new);
			remove(caminho_arquivo);
			rename("arquivos/new.txt", caminho_arquivo);

		} else if(op==2){
			printf("opcao 2\n");
		} else {
			system("clear");
			printf("\nOpcao invalida, tente novamente!\n");
		}

		system("clear");
		printf("\nApagado com sucesso!\n");
		fclose(arquivo);
		return 0;
	}
}

//funcao apagar uma tabela
int apagar_tabela(FILE *arq){
	char nome_tabela[20];

	printf("Insira o nome da tabela que deseja apagar: ");
	scanf("%s", nome_tabela);

	char nome_arquivo[50] = "tabela_";
	strcat(nome_arquivo, nome_tabela);
	strcat(nome_arquivo, ".txt");

	char caminho_arquivo[100] = "arquivos/";
	strcat(caminho_arquivo, nome_arquivo);

	FILE *arquivo = fopen(caminho_arquivo, "r");

	if(arquivo==NULL){
		system("clear");
		printf("\nOpa! O arquivo não existe!\n");
		return 0;
	} else {
		remove(caminho_arquivo);
		system("clear");
		printf("\nÊêê! Arquivo deletado!\n");
	}

	fclose(arquivo);
	return 0;
}

