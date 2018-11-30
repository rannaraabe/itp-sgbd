#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//funcoa renomear tabela
int renomear_tabela(FILE *arq){
	//nome tabela
	char nome_tabela[20];
	printf("\nInsira o nome da tabela: ");
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
		system("clear");
		printf("\nOpa! Erro ao tentar abrir o arquivo!\n");
		return 0;
	} else {
		char novo_nome[20];
		printf("\nInforme o novo nome para %s: ", nome_arquivo);
		scanf("%s", novo_nome);

		strcat(novo_nome, ".txt");

		char novo_nome_arquivo[15] = "tabela_";
		strcat(novo_nome_arquivo, novo_nome);

		char novo_caminho[20] = "arquivos/";
		strcat(novo_caminho, novo_nome_arquivo);

		rename(caminho_arquivo, novo_caminho);
	}

	fclose(arquivo);

	system("clear");
	printf("\nTabela reneomeada com sucesso!\n");
	return 1;
}

//funcao limpar uma tabela (truncate)
int limpar_tabela(FILE *arq){
	//declaracao de variaveis
	char c, quebra = '\n';
	int linhas = 0, cont = 0;

	char str[250];
	char* temp = 0;
	char** resultado = 0;
	unsigned int tamanho = 0;

	//nome tabela
	char nome_tabela[20];
	printf("\nInsira o nome da tabela: ");
	scanf("%s", nome_tabela);

	//nome padrao para o arquivo da tabela
	char nome_arquivo[20] = "tabela_";
	strcat(nome_arquivo, nome_tabela);
	strcat(nome_arquivo, ".txt");

	//caminho
	char caminho_arquivo[100] = "arquivos/";
	strcat(caminho_arquivo, nome_arquivo);

	FILE *arquivo = fopen(caminho_arquivo, "r");
	FILE *new = fopen("arquivos/new.txt", "w");

	if(arquivo==NULL){
		system("clear");
		printf("\nOpa! Erro ao tentar abrir o arquivo!\n");
		return 0;
	} else {
		//pegando a quantidade de linhas do arquivo             
		while(fread(&c, sizeof(char), 1, arquivo)) {
			if(c == quebra) {
				linhas++;
			}
		}

		rewind(arquivo);
                cont = 1;
                char texto_linha[100];
                char ch = getc(arquivo);

                //percorre o arquivo até o fim, se o valor da chave n foi encontrada ele escreve essa linha no arquivo novo
                while(ch != EOF){
                        putc(ch, new);
                        ch = getc(arquivo);

                        if(ch == '\n'){
                                break;
                        }
                }
		
		fprintf(new, "\n");

		//renomeia o arquivo new e apaga o antigo
		fclose(new);
		remove(caminho_arquivo);
		rename("arquivos/new.txt", caminho_arquivo);

	}

	fclose(arquivo);

	system("clear");
	printf("\nTabela truncada com sucesso!\n");
	return 1;
}
