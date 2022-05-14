#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "ArvoreBinaria.h"

#define N 8

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	ArvBin* raiz = cria_ArvBin();
	
	if (estaVazia_ArvBin(raiz)) {
		printf("A árvore está vazia.\n");
	}
	
	int i;
	int dados[N] = {50, 100, 30, 20, 40, 45, 35, 37};
	
	for (i = 0; i < N; i++) {
		insere_ArvBin(raiz, dados[i]);
	}
	
	printf("A árvore tem %d nós.\n", totalNO_ArvBin(raiz));
	
	printf("A altura da árvore é %d.\n", altura_ArvBin(raiz));
	
	printf("Impressão em pre ordem: \n");
	preOrdem_ArvBin(raiz);
	printf("\n");
	
	printf("Impressão em ordem: \n");
	emOrdem_ArvBin(raiz);
	printf("\n");
	
	printf("Impressão em pos ordem: \n");
	posOrdem_ArvBin(raiz);
	printf("\n");
	
	printf("Removendo o elemento %d.\n", dados[3]);
	if (remove_ArvBin(raiz, dados[3])) {
		printf("Item removido com sucesso.\n");
		printf("Impressão em pos ordem: \n");
		posOrdem_ArvBin(raiz);
		printf("\n");
	}
	
	printf("Procurar pelo número %d.\n", dados[1]);
	if (consulta_ArvBin(raiz, dados[1])) {
		printf("O valor %d foi encontrado na árvore.\n", dados[1]);
	} else {
		printf("O valor %d não foi encontrado na árvore.\n", dados[1]);
	}
	
	liberta_ArvBin(raiz);
	
	return 0;
}
