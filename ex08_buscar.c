#include <stdio.h>
#include <stdlib.h>

/* Exercício 8 — Função buscar (retorna 1 ou 0) */

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
    if (raiz == NULL)          return 0; /* não encontrado */
    if (valor == raiz->valor)  return 1; /* encontrado     */
    if (valor < raiz->valor)   return buscar(raiz->esquerda, valor);
    return                            buscar(raiz->direita,  valor);
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

    printf("Busca 40: %s\n", buscar(raiz, 40) ? "Encontrado" : "Não encontrado");
    printf("Busca 25: %s\n", buscar(raiz, 25) ? "Encontrado" : "Não encontrado");
    printf("Busca 80: %s\n", buscar(raiz, 80) ? "Encontrado" : "Não encontrado");

    liberarArvore(raiz);
    return 0;
}
