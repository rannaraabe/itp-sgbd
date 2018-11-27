# sgbd-itp
Implementação de um Sistema de Gerenciamento de Banco de Dados simplificado baseado no modelo relacional.
O SGBD realiza as seguintes operações:

1. Criar um tabela

2. Listar todas as tabelas

3. Criar uma nova linha na tabela

4. Listar todos os dados de uma tabela

5. Pesquisar valor em uma tabela
	Opções de pesquisa:
	i. valores maior que o valor informado
	ii. valores maior ou igual que o valor informado
	iii. valores igual o valor informado
	iv. valores menor que o valor informado
	v. valores menor ou igual que o valor informado
	vi. valores próximo ao valor informado

6. Apagar valor de uma tabela

7. Apagar uma tabela

Para excutá-lo basta executar no terminal linux o seguinte comando:
<gcc main.c bibliotecas/funcoes-check1.c bibliotecas/funcoes-check2.c bibliotecas/funcoes-check3.c bibliotecas/funcoes-check4.c -o ex -g -W>

*Não é o objetivo desse projeto criar um SGBD para ser utilizado em produção por sistemas de informação, mas “apenas” explorar os conceitos abordados nas disciplinas ITP/PTP.*
