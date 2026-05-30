#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "requisicao.h"

typedef struct No {
    Requisicao dados;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Fila;

Fila* criarFila();
void enfileirar(Fila *fila, Requisicao r);
Requisicao desenfileirar(Fila *fila);
int tamanhoFila(Fila *fila);
void liberarFila(Fila *fila);

#endif