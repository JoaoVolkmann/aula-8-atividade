#include <stdio.h>
#include <stdlib.h>

/* Exercício 10 — Programa completo de teste */

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

int buscar(No *raiz, int valor) {
    if (raiz == NULL)         return 0;
    if (valor == raiz->valor) return 1;
    if (valor < raiz->valor)  return buscar(raiz->esquerda, valor);
    return                           buscar(raiz->direita,  valor);
}

void emOrdem(No *raiz) {
    if (raiz == NULL) return;
    emOrdem(raiz->esquerda);
    printf("%d ", raiz->valor);
    emOrdem(raiz->direita);
}

void liberarArvore(No *raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

int main(void) {
    No *raiz = NULL;

    /* 1. Inserir valores */
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++)
        raiz = inserir(raiz, vals[i]);

    /* 2. Imprimir em ordem crescente */
    printf("Valores em ordem crescente: ");
    emOrdem(raiz);
    printf("\n");

    /* 3. Buscar 40 */
    printf("Busca por 40: %s\n", buscar(raiz, 40) ? "Encontrado" : "Não encontrado");

    /* 4. Buscar 90 */
    printf("Busca por 90: %s\n", buscar(raiz, 90) ? "Encontrado" : "Não encontrado");

    liberarArvore(raiz);
    return 0;
}
