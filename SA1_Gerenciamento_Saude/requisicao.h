#ifndef REQUISICAO_H
#define REQUISICAO_H

typedef struct {
    char nome[40];
    int codigoInscricao;
    char codigoProcedimento[10];
} Requisicao;

Requisicao criarRequisicao(const char *nome, int codigo, const char *procedimento);

#endif