# SGBD
SGBD é um Sistema de Gerenciamento de Banco de Dados simplificado baseado no modelo relacional.

*O objetivo do projeto é criar um SGBD para explorar os conceitos abordados nas disciplinas ITP/PTP ministrada pela professora [Márjory Cristiany](https://sigaa.ufrn.br/sigaa/public/docente/portal.jsf?siape=2524467).*

## Funções do SGBD:
O SBGD realiza as seguintes operações:
1. Criar um tabela
2. Listar todas as tabelas
3. Criar uma nova linha na tabela
4. Listar todos os dados de uma tabela
5. Pesquisar valor em uma tabela
	1. valores maior que o valor informado
	2. valores maior ou igual que o valor informado
	3. valores igual o valor informado
	4. valores menor que o valor informado
	5. valores menor ou igual que o valor informado
	6. valores próximo ao valor informado
6. Apagar valor de uma tabela
7. Apagar uma tabela

## Execução
Para executar o SGBD, execute no terminal linux o seguinte comando:

`<gcc main.c bibliotecas/funcoes-check1.c bibliotecas/funcoes-check2.c bibliotecas/funcoes-check3.c bibliotecas/funcoes-check4.c -o ex -g -W>`
