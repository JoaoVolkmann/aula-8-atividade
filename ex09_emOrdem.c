#include <stdio.h>
#include <stdlib.h>

/* Exercício 9 — Percurso em ordem */

/*
   Árvore:
           50
          /  \
        30    70
       / \   / \
     20  40 60  80

   Em ordem (esq → raiz → dir): 20 30 40 50 60 70 80
*/

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

No* criarNo(int valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->valor    = valor;
    novo->esquerda = NULL;
    novo->direita  = NULL;
    return novo;
}

No* inserir(No *raiz, int valor) {
    if (raiz == NULL) return criarNo(valor);
    if (valor < raiz->valor) raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->valor) raiz->direita = inserir(raiz->direita, valor);
    return raiz;
}

void emOrdem(No *raiz) {
    if (raiz == NULL) return;
    emOrdem(raiz->esquerda);   /* 1. visita esquerda */
    printf("%d ", raiz->valor); /* 2. imprime raiz    */
    emOrdem(raiz->direita);    /* 3. visita direita   */
}

void liberarArvore(No *raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

int main(void) {
    No *raiz = NULL;
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++)
        raiz = inserir(raiz, vals[i]);

    printf("Em ordem: ");
    emOrdem(raiz);
    printf("\n");

    liberarArvore(raiz);
    return 0;
}
