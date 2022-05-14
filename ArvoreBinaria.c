#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

struct NO {
	int info;
	struct NO *esq;
	struct NO *dir;
};

ArvBin* cria_ArvBin() {
	ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
	
	if (raiz != NULL) *raiz = NULL;
	
	return raiz;
}

void liberta_NO(struct NO* no) {
	if (no == NULL) return;
	
	liberta_NO(no->esq);
	liberta_NO(no->dir);
	free(no);
	no = NULL;
}

void liberta_ArvBin(ArvBin *raiz) {
	if (raiz == NULL) return;
	
	liberta_NO(*raiz); //liberta os nós da raiz
	free(raiz); //liberta a raiz
}

int estaVazia_ArvBin(ArvBin *raiz) {
	if (raiz == NULL || *raiz == NULL) return 1;
	else return 0;
}

int insere_ArvBin(ArvBin* raiz, int valor) {
    if (raiz == NULL) return 0;
    
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if (novo == NULL)
        return 0;
        
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if (*raiz == NULL) *raiz = novo;
    else {
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        
        while (atual != NULL) {
            ant = atual;
            if (valor == atual->info) {
                free(novo);
                return 0;//elemento já existe
            }

            if (valor > atual->info) atual = atual->dir;
            else atual = atual->esq;
        }
        
        if (valor > ant->info) ant->dir = novo;
        else ant->esq = novo;
    }
    
    return 1;
}

int totalNO_ArvBin(ArvBin *raiz) {
	if (raiz == NULL || *raiz == NULL) return 0;
	
	int alt_esq = 0, alt_dir = 0;
	
	alt_esq = totalNO_ArvBin(&((*raiz)->esq));
	alt_dir = totalNO_ArvBin(&((*raiz)->dir));
	
	return (alt_esq + alt_dir + 1);
}

int altura_ArvBin(ArvBin *raiz) {
	if (raiz == NULL || *raiz == NULL) return 0;
	
	int alt_esq = 0, alt_dir = 0;
	
	alt_esq = altura_ArvBin(&((*raiz)->esq));
	alt_dir = altura_ArvBin(&((*raiz)->dir));
	
	if (alt_esq > alt_dir) return (alt_esq + 1);
	else return (alt_dir + 1);
}

void preOrdem_ArvBin(ArvBin *raiz) {
	if (raiz == NULL) return;
	
	if (*raiz != NULL) {
		printf("%d\n", (*raiz)->info);
		preOrdem_ArvBin(&((*raiz)->esq));
		preOrdem_ArvBin(&((*raiz)->dir));
	}
}

void emOrdem_ArvBin(ArvBin *raiz) {
	if (raiz == NULL) return;
	
	if (*raiz != NULL) {
		emOrdem_ArvBin(&((*raiz)->esq));
		printf("%d\n", (*raiz)->info);
		emOrdem_ArvBin(&((*raiz)->dir));
	}
}

void posOrdem_ArvBin(ArvBin *raiz) {
	if (raiz == NULL) return;
	
	if (*raiz != NULL) {
		posOrdem_ArvBin(&((*raiz)->esq));
		posOrdem_ArvBin(&((*raiz)->dir));
		printf("%d\n", (*raiz)->info);
	}
}

