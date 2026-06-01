#include <stdio.h>
#include <stdlib.h>

/*
 * Exercício 11 — Implementação completa da BST
 * Operações: inserir, buscar, remover, emOrdem, liberarArvore
 */

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

/* ── criarNo ─────────────────────────────────── */
No* criarNo(int valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->valor    = valor;
    novo->esquerda = NULL;
    novo->direita  = NULL;
    return novo;
}

/* ── inserir ─────────────────────────────────── */
No* inserir(No *raiz, int valor) {
    if (raiz == NULL) return criarNo(valor);
    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita  = inserir(raiz->direita,  valor);
    return raiz;
}

/* ── buscar ──────────────────────────────────── */
int buscar(No *raiz, int valor) {
    if (raiz == NULL)         return 0;
    if (valor == raiz->valor) return 1;
    if (valor < raiz->valor)  return buscar(raiz->esquerda, valor);
    return                           buscar(raiz->direita,  valor);
}

/* ── menorNo (auxiliar para remoção) ─────────── */
static No* menorNo(No *no) {
    while (no->esquerda != NULL)
        no = no->esquerda;
    return no;
}

/* ── remover ─────────────────────────────────── */
No* remover(No *raiz, int valor) {
    if (raiz == NULL) return NULL;

    if (valor < raiz->valor) {
        raiz->esquerda = remover(raiz->esquerda, valor);

    } else if (valor > raiz->valor) {
        raiz->direita  = remover(raiz->direita,  valor);

    } else {
        /* Nó encontrado */

        /* Caso A: folha ou só filho direito */
        if (raiz->esquerda == NULL) {
            No *tmp = raiz->direita;
            free(raiz);
            return tmp;
        }
        /* Caso B: só filho esquerdo */
        if (raiz->direita == NULL) {
            No *tmp = raiz->esquerda;
            free(raiz);
            return tmp;
        }
        /* Caso C: dois filhos — usa sucessor in-order */
        No *suc      = menorNo(raiz->direita);
        raiz->valor  = suc->valor;
        raiz->direita = remover(raiz->direita, suc->valor);
    }

    return raiz;
}

/* ── emOrdem ─────────────────────────────────── */
void emOrdem(No *raiz) {
    if (raiz == NULL) return;
    emOrdem(raiz->esquerda);
    printf("%d ", raiz->valor);
    emOrdem(raiz->direita);
}

/* ── liberarArvore ───────────────────────────── */
void liberarArvore(No *raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

/* ── main ────────────────────────────────────── */
int main(void) {
    No *raiz = NULL;

    printf("=== ARVORE BINARIA DE BUSCA ===\n\n");

    /* Inserções */
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++)
        raiz = inserir(raiz, vals[i]);

    printf("Em ordem apos insercoes:\n  ");
    emOrdem(raiz);
    printf("\n\n");

    /* Busca */
    printf("Busca por 40: %s\n", buscar(raiz, 40) ? "Encontrado" : "Nao encontrado");
    printf("Busca por 90: %s\n\n", buscar(raiz, 90) ? "Encontrado" : "Nao encontrado");

    /* Remoção — Caso A: folha */
    printf("Removendo 20 (no folha)...\n");
    raiz = remover(raiz, 20);
    printf("Em ordem: "); emOrdem(raiz); printf("\n\n");

    /* Remoção — Caso B: um filho */
    printf("Removendo 30 (um filho apos remover 20)...\n");
    raiz = remover(raiz, 30);
    printf("Em ordem: "); emOrdem(raiz); printf("\n\n");

    /* Remoção — Caso C: dois filhos */
    printf("Removendo 70 (dois filhos)...\n");
    raiz = remover(raiz, 70);
    printf("Em ordem: "); emOrdem(raiz); printf("\n\n");

    /* Remoção de valor inexistente */
    printf("Removendo 99 (inexistente)...\n");
    raiz = remover(raiz, 99);
    printf("Em ordem: "); emOrdem(raiz); printf("\n\n");

    /* Libera memória */
    liberarArvore(raiz);
    printf("Memoria liberada com sucesso.\n");

    return 0;
}
