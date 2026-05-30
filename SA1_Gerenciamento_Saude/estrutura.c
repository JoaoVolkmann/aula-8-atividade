#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"

// O(1)
Fila* criarFila() {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    if (f == NULL) return NULL;

    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;

    return f;
}

// O(1)
void enfileirar(Fila *fila, Requisicao r) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return;

    novo->dados = r;
    novo->prox = NULL;

    if (fila->fim == NULL) {
        fila->inicio = novo;
    } else {
        fila->fim->prox = novo;
    }

    fila->fim = novo;
    fila->tamanho++;
}

// O(1)
Requisicao desenfileirar(Fila *fila) {
    if (fila->inicio == NULL) {
        printf("Fila vazia!\n");
        exit(1);
    }

    No *temp = fila->inicio;
    Requisicao r = temp->dados;

    fila->inicio = temp->prox;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(temp);
    fila->tamanho--;

    return r;
}

// O(1)
int tamanhoFila(Fila *fila) {
    return fila->tamanho;
}

// O(n)
void liberarFila(Fila *fila) {
    No *atual = fila->inicio;

    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    free(fila);
}