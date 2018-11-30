//importando bibliotecas necessarias
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//funcao apagar uma linha de uma tabela
int apagar_linha(FILE *arq){
	//variaveis necessarias
	char nome_tabela[20];
	char c, quebra = '\n';
	int linhas = 0, cont = 1;

	//nome
	printf("\nInsira o nome da tabela que deseja apagar: ");
	scanf("%s", nome_tabela);

	//nome do arquivo
	char nome_arquivo[50] = "tabela_";
	strcat(nome_arquivo, nome_tabela);
	strcat(nome_arquivo, ".txt");

	//caminho
	char caminho_arquivo[100] = "arquivos/";
	strcat(caminho_arquivo, nome_arquivo);

	FILE *arquivo = fopen(caminho_arquivo, "r");
	//novo arquivo para copiar o conteudo do outro
	FILE *new = fopen("arquivos/new.txt", "w");

	if(arquivo==NULL){
		system("clear");
		printf("\nO arquivo nao existe!\n");    
		return 0;
	} else {

		//pegando a quantidade de linhas do arquivo             
                while(fread(&c, sizeof(char), 1, arquivo)) {
                        if(c == quebra) {
                                linhas++;
                        }
                }

		//chave primaria
		int chave_primaria;
		printf("Valor da chave: ");
		scanf("%d", &chave_primaria);

		//apagar uma linha
		rewind(arquivo);
		cont = 1;
		char texto_linha[100];
		char ch = getc(arquivo);

		//percorre o arquivo até o fim, se o valor da chave n foi encontrada ele escreve essa linha no arquivo novo
		while(ch != EOF){
			if(cont!=(chave_primaria+1)){
				putc(ch, new);
			}
			ch = getc(arquivo);

			if(ch == '\n'){
				cont++;
			}
		}

		//renomeia o arquivo new e apaga o antigo
		fclose(new);
		remove(caminho_arquivo);
		rename("arquivos/new.txt", caminho_arquivo);

		system("clear");
		printf("\nApagado com sucesso!\n");

		fclose(arquivo);
		return 0;
	}
}

//funcao apagar uma tabela
int apagar_tabela(FILE *arq){
	char nome_tabela[20];

	//nome da tabela
	printf("Insira o nome da tabela que deseja apagar: ");
	scanf("%s", nome_tabela);

	char nome_arquivo[50] = "tabela_";
	strcat(nome_arquivo, nome_tabela);
	strcat(nome_arquivo, ".txt");

	//caminho
	char caminho_arquivo[100] = "arquivos/";
	strcat(caminho_arquivo, nome_arquivo);

	FILE *arquivo = fopen(caminho_arquivo, "r");

	if(arquivo==NULL){
		system("clear");
		printf("\nOpa! O arquivo não existe!\n");
		return 0;
	} else {
		//remove o arquivo
		remove(caminho_arquivo);
		system("clear");
		printf("\nÊêê! Arquivo deletado!\n");
	}

	fclose(arquivo);
	return 0;
}

