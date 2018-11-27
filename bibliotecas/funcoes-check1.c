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

//funcao criar tabela
int criar_tabela(FILE *arq){
	//declarando variaveis
	int condicao = 1, valor_chave = 0, cont_coluna = 1;
	char chave_primaria[15];
	dadosTabela tabela;

	//nome tabela
	char nome_tabela[15];
	printf("\nInsira o nome da tabela: \n");
	scanf("%s", &nome_tabela);

	//nome padrao para o arquivo da tabela
	char nome_arquivo[30] = "tabela_";
	strcat(nome_arquivo, nome_tabela);
	strcat(nome_arquivo, ".txt");

	//caminho
	char caminho_arquivo[100] = "arquivos/";
	strcat(caminho_arquivo, nome_arquivo);

	FILE *arquivo = fopen(caminho_arquivo, "w");

	if(arquivo==NULL){
		system("clear");
		printf("\nOpa! Erro ao tentar abrir o arquivo!\n");
		return 0;
	} else {
		//chave primaria
		printf("\nInsira o nome para a coluna da chave primaria:\n");
		scanf("%s", chave_primaria);

		//valor chave primaria
		valor_chave++;
		fprintf(arquivo, "%d ", valor_chave);

		//adicionando colunas
		while(condicao!=0){
			//nome da coluna
			printf("\nInsira o nome da coluna %d: \n", cont_coluna);
			scanf("%s", &tabela.nome);

			//tipo de dado: para conferir se o usuario vai inserir o tipo certo
			printf("Tipo de dado: \n");
			scanf("%s", &tabela.tipo_dado);
			//caso string
			if(!strcmp(tabela.tipo_dado, "string")){
				//quando sair do if, o vetor eh desalocado
				char valor_s[25];
				printf("Insira o valor da coluna %s: *sem espacos!*\n", tabela.nome);
				scanf("%s", valor_s);

				fprintf(arquivo, "%s ", valor_s);
			}
			//caso char
			else if(!strcmp(tabela.tipo_dado, "char")){
				char valor_c;
				printf("Insira o valor da coluna %s:\n", tabela.nome);
				scanf("%s", &valor_c);

				fprintf(arquivo, "%c ", valor_c);
			}
			//caso int
			else if(!strcmp(tabela.tipo_dado, "int")){
				int valor_i;
				do{
					printf("Insira o valor da coluna %s:\n", tabela.nome);
					scanf("%d", &valor_i);

					if(valor_i<=valor_chave){
						printf("\nOpa! Conflito de valores.\nA coluna '%s' nao pode ter o mesmo valor da chave primaria! Tente novamente!\n", tabela.nome);
					}

				} while(valor_i<=valor_chave);

				fprintf(arquivo, "%d ", valor_i);
			}
			//caso float
			else if(!strcmp(tabela.tipo_dado, "float")){
				float valor_f;

				do{
					printf("Insira o valor da coluna %s:\n", tabela.nome);
					scanf("%f", &valor_f);

					if(valor_f<=valor_chave){
						printf("\nOpa! Conflito de valores.\nA coluna '%s' nao pode ter o mesmo valor da chave primaria! Tente novamente!\n", tabela.nome);
					}

				} while(valor_f<=valor_chave);

				fprintf(arquivo, "%f ", valor_f);
			}
			//caso double
			else if(!strcmp(tabela.tipo_dado, "double")){
				double valor_d;

				do{
					printf("Insira o valor da coluna %s:\n", tabela.nome);
					scanf("%lf", &valor_d);

					if(valor_d<=valor_chave){
						printf("\nOpa! Conflito de valores.\nA coluna '%s' nao pode ter o mesmo valor da chave primaria! Tente novamente!\n", tabela.nome);
					}

				} while(valor_d<=valor_chave);

				fprintf(arquivo, "%lf ", valor_d);
			} else {
				printf("Opa! Erro ao tentar inserir um tipo inválido!\n");
				fprintf(arquivo, "NULL ");
			}

			//add mais colunas
			printf("\nAdicionar mais uma coluna? [1-sim 0-não]\n");
			scanf("%d", &condicao);

			if(condicao!=0 && condicao!=1){
				printf("Opa! Opção inválida!");
				condicao = 0;
			}
		}
	}

	system("clear");

	fclose(arquivo);
	return 1;
}

//funcao listar tabelas
int listar_tabelas(FILE *arq){
	//declarando variaveis
	int controle = 0;
	struct dirent *entrada;
	DIR *diretorio;

	diretorio = opendir("arquivos");

	if(diretorio==NULL){
		system("clear");
		printf("\nOpa! Erro ao abrir o diretorio!\n");
		return 0;
	}

	system("clear");
	printf("\nTabelas cadastradas:\n\n");

	//lendo os arquivos do diretorio e printando na tela
	while(entrada = readdir(diretorio)){
		controle++;
		if(controle>=1){
			printf("%s\n", entrada->d_name);
		}
	}

	if(controle==2){
		printf("\nNão há tabelas no sistema!\nCadastre na opção 1!\n");
	}

	closedir(diretorio);
	return 1;
}

