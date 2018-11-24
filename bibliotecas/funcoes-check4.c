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


//funcao apagar uma linha de uma tabela
int apagar_linha(FILE *arq){

}

//funcao apagar uma tabela
int apagar_tabela(FILE *arq){
        char nome_tabela[20];

        printf("Insira o nome da tabela que deseja apagar: \n");
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
                int delete = 1;
                delete = (remove(caminho_arquivo));

                system("clear");
                printf("\nÊêê! Arquivo deletado!\n");
        }

        fclose(arquivo);
        return 0;
}

