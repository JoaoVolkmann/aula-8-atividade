#include <stdio.h>
#include <stdlib.h>

/* Exercício 4 — Função criarNo */

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

No* criarNo(int valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->valor     = valor;
    novo->esquerda  = NULL;
    novo->direita   = NULL;
    return novo;
}

int main(void) {
    No *n = criarNo(42);
    printf("Nó criado com valor: %d\n", n->valor);
    printf("Esquerda: %s\n", n->esquerda == NULL ? "NULL" : "ocupado");
    printf("Direita:  %s\n", n->direita  == NULL ? "NULL" : "ocupado");
    free(n);
    return 0;
}
