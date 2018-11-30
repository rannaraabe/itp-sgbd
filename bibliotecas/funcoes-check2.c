//importando bibliotecas necessarias
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//struct referente às colunas
typedef struct{
	char nome[15];
	char tipo_dado[7];
} dadosTabela;

//funcao criar uma nova linha em uma tabela especifica
int criar_linha_tabela(FILE *arq){
	//declarando variaveis necessarias
	int condicao = 1,
	    valor_chave = 0,
	    q_colunas = 0;
	
	dadosTabela tabela;

	char c, quebra = '\n'; 
	int linhas = 0;

	char texto[250];
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

	FILE *arquivo = fopen(caminho_arquivo, "a+");

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

		//imprimindo as colunas cadastradas do banco
		rewind(arquivo);
		while(fgets(texto, 250, arquivo)!=NULL){
                        printf("\nColunas da tabela:\n");

                        temp = strtok(texto, " ");

                        if(temp){
                                resultado = malloc((tamanho+1)*sizeof(char**));
                                resultado[tamanho++] = temp;
                        }

                        while((temp=strtok(0, " "))!=0){
                                resultado = realloc(resultado, (tamanho+1)*sizeof(char**));
                                resultado[tamanho++] = temp;
                        }
			//break para parar quando terminar de ler e alocar a primeira linha que eh a linha das colunas
                        break;
                }	

		for(unsigned int i=0; i<tamanho-1; i++){
			printf("%d. %s\n", i+1, resultado[i]);
		}

		//tirando 1 do valor do tamanho, pois ele incrementa 1 valor a mais
		q_colunas = tamanho-1;

		printf("Lembrete: a tabela da chave primaria é AI, por isso insira valores para as outras colunas.\n");

		do{
			//salvando em um vetor as chaves já cadastradas
			int cont = 0;
			char str[1000];
			int ids[1000];

			rewind(arquivo);
			while(fgets(str, 1000, arquivo) != NULL){
				if(cont != 0){
					ids[cont-1] = atoi(strcat(str, " "));
				}
				cont++;
			}
		
			//escrevendo chave primaria na tabela
			fprintf(arquivo, "%d ", ids[cont-2]+1);

			//pedindo os valores referentes às colunas das tabelas
			for(int i=1; i<=q_colunas-1; i++){
				printf("\nColuna %d: \n", i+1);

				//tipo de dado: para conferir se o usuario vai inserir o tipo certo
				printf("Tipo de dado: ");
				scanf("%s", &tabela.tipo_dado);	
				//caso string
				if(!strcmp(tabela.tipo_dado, "string")){
					//quando sair do if, o vetor eh desalocado
					char valor_s[25];
					printf("Valor sem espaços: ");
					scanf("%s", valor_s);

					fprintf(arquivo, "%s ", valor_s);
				}
				//caso char
				else if(!strcmp(tabela.tipo_dado, "char")){
					char valor_c;
					printf("Valor: ");
					scanf("%s", &valor_c);

					fprintf(arquivo, "%c ", valor_c);
				}
				//caso int
				else if(!strcmp(tabela.tipo_dado, "int")){
					int valor_i;
					do{
						printf("Valor: ");
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
						printf("Valor: ");
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
						printf("Valor:");
						scanf("%lf", &valor_d);

						if(valor_d<=valor_chave){
							printf("\nOpa! Conflito de valores. Nao eh possivel inserir o mesmo valor de uma chave! Tente novamente!\n");
						}

					} while(valor_d<=valor_chave);

					fprintf(arquivo, "%lf ", valor_d);
				//caso default, salva no aquivo um valor null
				} else {
					printf("Opa! Erro ao tentar inserir um tipo inválido! Valor salvo por padrao: NULL\n");
					fprintf(arquivo, "NULL ");
				}

				fprintf(arquivo, "\n");	
			}

			//para add mais colunas
			printf("\nAdicionar mais uma tupla? [1-sim 0-não]\n");
			scanf("%d", &condicao);

			if(condicao!=0 && condicao!=1){
				printf("Opa! Opção inválida!");
				condicao = 0;
			}

		} while(condicao!=0);
	}

	system("clear");
	printf("\nÊêê! A %s foi atualizada com sucesso!\n", nome_arquivo);
	
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
	}

	return 1;
}
