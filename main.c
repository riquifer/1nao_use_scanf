#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define PULAR_LINHA putchar('\n') /*Define macro para pular linha de forma mais fácil, em outra palavras, toda vez que eu escrever "PULAR_LINHA", antes do processo de compilação todos os trechos escritos são trocados pelo código "putchar('\n')*/

int main(void){
	char nome[50] = {}; /*Define array onde será armazenado o nome inserido pelo usuário. Importante não deixar vazio o número dentro do colchete, pois dará erro na hora de criar o algoritmo de contagem de letras (acho que é estouro de buffer)*/
	int count = 0; /*Esta variável será usada no algoritmo de contagem de letras mais pro final (o laço for)*/
	PULAR_LINHA;
	printf("\t%s", "PROGRAMA PARA INSERCAO DE NOME");
	PULAR_LINHA;
	printf("\tDigite seu nome: ");
	fgets(nome, 50, stdin);  /*Core da questão desse desafio, utilizar a função fgets() ao invés de scanf()*/
	/*puts(nome);*/  /*Apenas para teste, optei por não excluir por fins didáticos.*/
	nome[strcspn(nome, "\n")] = 0; /*A função strcspn retorna quantidade de índices até chegar no elemento passado no segundo argumento, neste caso, ele vai pegar a array "nome" e contar quantos elementos tem até chegar no elemento "\n" (que significa quebra de linha). A lógica é a seguinte, neste caso, é preciso eliminar a quebra de linha para não ser contada no algoritmo de contagem de letras mais abaixo. Como a string passada pelo usuário é de tamanho aleatório (até no máximo 50 caracteres) o índice do elemento "\n" também será aleatório, sempre obedecendo o padrão de estar no fim da string, obviamente. Como a função strcspn segue o padrão de contar até o elemento que passamos no segundo argumento, e o segundo argumento é "\n", isso significa que o retorno da função sempre vai coincidir com o índice do elemento "\n". Sendo assim, podemos anular a quebra da linha através de uma atribuição simples que vai mudar array[x] = "\n" para array[x] = 0 E isso vai anular o último elemento, que não será contabilizado no algoritmo de contagem abaixo.*/
	int len = strlen(nome); /*Variável para usarmos como limite para o laço for abaixo. strlen() retorna tamanho da string. Importante lembar que na linha de cima anulamos o caractere de quebra de linha "\n".*/
	for (int i = 0; i < len; ++i) { /*Cada vez que i for menor que len, executa condicional e verifica se nome[i] é caractere através da função isspace() que retorna 0 se for caractere. Em caso de retornar 0 (é caractere) a condicional adiciona 1 à variável count, caso contrário, não faz nada e pula para o próximo carcatere, adicionando 1 ao índice i do laço for.)*/
		if (isspace(nome[i]) == 0) {
			count++;
		}
	}
	printf("\tQuantidade de letras no seu nome: %d", count);
	PULAR_LINHA;
	PULAR_LINHA;
	return 0;
}
