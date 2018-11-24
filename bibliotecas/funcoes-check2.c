//importando bibliotecas necessarias
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//tipo de dado tabela
typedef struct{
	char nome[15];
	char tipo_dado[7];
} dadosTabela;


//funcao criar uma nova linha em uma tabela especifica
int criar_linha_tabela(FILE *arq){
	int condicao = 1;
	dadosTabela tabela;

	//variaveis para a chave na hora de pegar o valor do arquivo e comparar
	char nomeChave[15], tipoChave[4];
	int valorChave;

	//nome tabela
	char nome_tabela[20];
	printf("\nInsira o nome da tabela: \n");
	scanf("%s", nome_tabela);

	//nome padrao para o arquivo da tabela
	char nome_arquivo[20] = "tabela_";
	strcat(nome_arquivo, nome_tabela);
	strcat(nome_arquivo, ".txt");

	//caminho
	char caminho_arquivo[100] = "arquivos/";
	strcat(caminho_arquivo, nome_arquivo);

	FILE *arquivo = fopen(caminho_arquivo, "a+");

	if(arquivo==NULL){
		system("clear");
		printf("\nOpa! Erro ao tentar abrir o arquivo!\n");
		return 0;
	} else {
		while(condicao!=0){
			//nome da coluna
			printf("\nNome coluna: \n");			
			scanf("%s", &tabela.nome);
			fprintf(arquivo, "%s ", &tabela.nome);

			//tipo do dado
			printf("Tipo de dado: \n");
			scanf("%s", &tabela.tipo_dado);

			//caso string
			if(!strcmp(tabela.tipo_dado, "string")){
				fprintf(arquivo, "%s ", &tabela.tipo_dado);

				//quando sair do if, o vetor eh desalocado
				char valor_s[25];               
				printf("Insira o valor: *sem espacos!*\n");
				scanf("%s", valor_s);

				fprintf(arquivo, "%s\n", valor_s);
			}
			//caso char
			else if(!strcmp(tabela.tipo_dado, "char")){
				fprintf(arquivo, "%s ", &tabela.tipo_dado);

				char valor_c;
				printf("Insira o valor:\n");
				scanf("%s", &valor_c);

				fprintf(arquivo, "%c\n", valor_c);
			} 
			//caso int
			else if(!strcmp(tabela.tipo_dado, "int")){
				fprintf(arquivo, "%s ", &tabela.tipo_dado);

				int valor_i;

				do{
					printf("Insira o valor:\n");
					scanf("%d", &valor_i);

					//pegando os valores da chave primaria do arquivo para comparar
					rewind(arquivo);
					fscanf(arquivo, "%s %s %d", nomeChave, tipoChave, &valorChave);

					if(valor_i==valorChave){
						printf("\nOpa! Conflito de valores.\nA coluna '%s' nao pode ter o mesmo valor da chave primaria! Tente novamente!\n", tabela.nome);
					}

				} while(valor_i==valorChave);

				fprintf(arquivo, "%d\n", valor_i);

			}
			//caso float       
			else if(!strcmp(tabela.tipo_dado, "float")){
				fprintf(arquivo, "%s ", &tabela.tipo_dado);

				float valor_f;

				do{
					printf("Insira o valor:\n");
					scanf("%f", &valor_f);

					//pegando os valores da chave primaria do arquivo para comparar
					rewind(arquivo);
					fscanf(arquivo, "%s %s %d", nomeChave, tipoChave, &valorChave);

					if(valor_f==valorChave){
						printf("\nOpa! Conflito de valores.\nA coluna '%s' nao pode ter o mesmo valor da chave primaria! Tente novamente!\n", tabela.nome);
					}

				} while(valor_f==valorChave);

				fprintf(arquivo, "%f\n", valor_f);

			}
			//caso double
			else if(!strcmp(tabela.tipo_dado, "double")){
				fprintf(arquivo, "%s ", &tabela.tipo_dado);

				double valor_d;

				do{
					printf("Insira o valor:\n");
					scanf("%lf", &valor_d);

					//pegando os valores da chave primaria do arquivo para comparar
					rewind(arquivo);
					fscanf(arquivo, "%s %s %d", nomeChave, tipoChave, &valorChave);

					if(valor_d==valorChave){
						printf("\nOpa! Conflito de valores.\nA coluna '%s' nao pode ter o mesmo valor da chave primaria! Tente novamente!\n", tabela.nome);
					}

				} while(valor_d==valorChave);

				fprintf(arquivo, "%lf\n", valor_d);

			} else {
				printf("Opa! Erro ao tentar inserir um tipo invalido!\n");
				fprintf(arquivo, "NULL, NULL\n");
				condicao = 0;
			}

			printf("\nAdicionar mais uma coluna? [1-sim 0-não]\n");
			scanf("%d", &condicao);

			if(condicao!=0 && condicao!=1){
				printf("Opa! Opção invalida!");
				condicao = 0;
			}

		}
	}

	system("clear");

	fclose(arquivo);
	return 1;

}

//funcao listar os dados de uma tabela especifica
int listar_dados_tabela(FILE *arq){
	//nome tabela
	char nome_tabela[20];
	printf("\nInsira o nome da tabela: \n");
	scanf("%s", nome_tabela);

	//nome padrao para o arquivo da tabela
	char nome_arquivo[20] = "tabela_";
	strcat(nome_arquivo, nome_tabela);
	strcat(nome_arquivo, ".txt");

	//caminho
	char caminho_arquivo[100] = "arquivos/";
	strcat(caminho_arquivo, nome_arquivo);

	FILE *arquivo = fopen(caminho_arquivo, "r");

	//comando cat
	char comando[] = "cat";
	strcat(comando, " arquivos/");
	strcat(comando, nome_arquivo);

	if(arquivo==NULL){
		system("clear");
		printf("\nOpa! Erro ao tentar abrir o arquivo!\n");
		return 0;
	} else {
		system("clear");
		printf("\n%s:\n\n", nome_arquivo);
		system(comando);
	}

	return 1;
}

