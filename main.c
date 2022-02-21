#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define PULAR_LINHA putchar('\n')

int main(void){
	char nome[50] = {};
	int count = 0;
	PULAR_LINHA;
	printf("\t%s", "PROGRAMA PARA INSERCAO DE NOME");
	PULAR_LINHA;
	printf("\tDigite seu nome: ");
	fgets(nome, 50, stdin);
	/*puts(nome);*/
	nome[strcspn(nome, "\n")] = 0;
	int len = strlen(nome);
	for (int i = 0; i < len; ++i) {
		if (isspace(nome[i]) == 0) {
			count++;
		}
	}
	printf("\tQuantidade de letras no seu nome: %d", count);
	PULAR_LINHA;
	PULAR_LINHA;
	return 0;
}
