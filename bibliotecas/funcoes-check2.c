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
	int condicao = 1, valor_chave = 0, q_colunas = 0;
	dadosTabela tabela;

	char c, quebra = '\n'; 
	int linhas = 0;

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

	FILE *arquivo = fopen(caminho_arquivo, "a+");

	if(arquivo==NULL){
		system("clear");
		printf("\nOpa! Erro ao tentar abrir o arquivo!\n");
		return 0;
	} else {
		//pegando o ultimo valor da chave para incrementar		
		while(fread(&c, sizeof(char), 1, arquivo)) {
			if(c == quebra) {
				linhas++;
			}
		}

		//valor de chave recebe a quantidade de linhas da tabela para incrementar o valor correto
		if(valor_chave>2){
			valor_chave = linhas-1;
		} else {
			valor_chave = linhas;
		}

		printf("Quantas colunas a tabela possui? ");
		scanf("%d", &q_colunas);

		do{
			//chave primaria da tabela
			valor_chave++;
			fprintf(arquivo, "\n%d ", valor_chave);

			for(int i=1; i<=q_colunas; i++){
				printf("\n\nColuna %d: \n", i);
			
				//tipo de dado: para conferir se o usuario vai inserir o tipo certo
				printf("Tipo de dado para o valor: ");
				scanf("%s", &tabela.tipo_dado);
				//caso string
				if(!strcmp(tabela.tipo_dado, "string")){
					//quando sair do if, o vetor eh desalocado
					char valor_s[25];
					printf("Insira o valor sem espaços: ");
					scanf("%s", valor_s);

					fprintf(arquivo, "%s ", valor_s);
				}
				//caso char
				else if(!strcmp(tabela.tipo_dado, "char")){
					char valor_c;
					printf("Insira o valor: ");
					scanf("%s", &valor_c);

					fprintf(arquivo, "%c ", valor_c);
				}
				//caso int
				else if(!strcmp(tabela.tipo_dado, "int")){
					int valor_i;
					do{
						printf("Insira o valor: ");
						scanf("%d", &valor_i);

						if(valor_i<=valor_chave){
							printf("\nOpa! Conflito de valores. Nao eh possivel inserir o mesmo valor de uma chave! Tente novamente!\n");
						}

					} while(valor_i<=valor_chave);

					fprintf(arquivo, "%d ", valor_i);
				}
				//caso float
				else if(!strcmp(tabela.tipo_dado, "float")){
					float valor_f;
					do{
						printf("Insira o valor: ");
						scanf("%f", &valor_f);

						if(valor_f<=valor_chave){
							printf("\nOpa! Conflito de valores. Nao eh possivel inserir o mesmo valor de uma chave! Tente novamente!\n");
						}

					} while(valor_f<=valor_chave);

					fprintf(arquivo, "%f ", valor_f);
				}
				//caso double
				else if(!strcmp(tabela.tipo_dado, "double")){
					double valor_d;
					do{
						printf("Insira o valor:");
						scanf("%lf", &valor_d);

						if(valor_d<=valor_chave){
							printf("\nOpa! Conflito de valores. Nao eh possivel inserir o mesmo valor de uma chave! Tente novamente!\n");
						}

					} while(valor_d<=valor_chave);

					fprintf(arquivo, "%lf ", valor_d);
				} else {
					printf("Opa! Erro ao tentar inserir um tipo inválido!\n");
					fprintf(arquivo, "NULL ");
				}								
			}
			//add mais colunas
			printf("\nAdicionar mais uma tupla? [1-sim 0-não]\n");
			scanf("%d", &condicao);

			if(condicao!=0 && condicao!=1){
				printf("Opa! Opção inválida!");
				condicao = 0;
			}

		} while(condicao!=0);
	}

	system("clear");

	printf("Êêê! A %s foi atualizada com sucesso!\n", nome_arquivo);

	fclose(arquivo);
	return 1;

}

//funcao listar os dados de uma tabela especifica
int listar_dados_tabela(FILE *arq){
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
		printf("\n%s: \n\n", nome_arquivo);
		system(comando);
		printf("\n");
	}

	return 1;
}
