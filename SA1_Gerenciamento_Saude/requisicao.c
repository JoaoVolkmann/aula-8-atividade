#include <stdio.h>
#include <string.h>
#include "requisicao.h"

// O(1)
Requisicao criarRequisicao(const char *nome, int codigo, const char *procedimento) {
    Requisicao r;

    strncpy(r.nome, nome, sizeof(r.nome));
    r.nome[sizeof(r.nome) - 1] = '\0';

    r.codigoInscricao = codigo;

    strncpy(r.codigoProcedimento, procedimento, sizeof(r.codigoProcedimento));
    r.codigoProcedimento[sizeof(r.codigoProcedimento) - 1] = '\0';

    return r;
}