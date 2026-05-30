#include <stdio.h>
#include "estrutura.h"
#include "requisicao.h"

int main() {
    Fila *fila = criarFila();

    if (fila == NULL) {
        printf("Erro ao criar fila\n");
        return 1;
    }

    enfileirar(fila, criarRequisicao("Joao", 1, "PROC001"));
    enfileirar(fila, criarRequisicao("Maria", 2, "PROC002"));
    enfileirar(fila, criarRequisicao("Carlos", 3, "PROC003"));

    printf("Tamanho da fila: %d\n", tamanhoFila(fila));

    Requisicao r = desenfileirar(fila);
    printf("Atendido: %s (%d)\n", r.nome, r.codigoInscricao);

    printf("Tamanho da fila: %d\n", tamanhoFila(fila));

    liberarFila(fila);

    return 0;
}