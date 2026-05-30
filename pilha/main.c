#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ================= ESTRUTURAS =================

typedef struct No {
    char texto[100];
    int urgencia;
    int id;
    char tecnico[50];
    struct No* prox;
} No;

typedef struct {
    No* topo;
} Pilha;

// ================= FUNÇÕES BASE =================

void inicializar(Pilha* p) {
    p->topo = NULL;
}

int estaVazia(Pilha* p) {
    return p->topo == NULL;
}

// ================= PUSH =================
void push(Pilha* p, char texto[], int urgencia, int id, char tecnico[]) {
    No* novo = (No*) malloc(sizeof(No));
    
    if (novo == NULL) {
        printf("Erro: Falha de alocação\n");
        return;
    }

    strcpy(novo->texto, texto);
    novo->urgencia = urgencia;
    novo->id = id;
    strcpy(novo->tecnico, tecnico);

    novo->prox = p->topo;
    p->topo = novo;
}

// ================= POP =================
int pop(Pilha* p, No* removido) {
    if (estaVazia(p)) {
        printf("Erro: Não há ações para desfazer\n");
        return 0;
    }

    No* temp = p->topo;
    *removido = *temp;

    p->topo = temp->prox;
    free(temp);

    return 1;
}

// ================= PEEK =================
void peek(Pilha* p) {
    if (estaVazia(p)) {
        printf("Pilha vazia\n");
        return;
    }

    printf("Topo: %s\n", p->topo->texto);
}

// ================= COUNT =================
int count(Pilha* p) {
    int cont = 0;
    No* atual = p->topo;

    while (atual != NULL) {
        cont++;
        atual = atual->prox;
    }

    return cont;
}

// ================= CLEAR =================
void limpar_pilha(Pilha* p) {
    No* atual = p->topo;
    int total = 0;

    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        total += sizeof(No);
        free(temp);
    }

    p->topo = NULL;
    printf("Memória liberada: %d bytes\n", total);
}

// ================= COMPARAÇÃO =================
int comparar(Pilha* p1, Pilha* p2) {
    No* a = p1->topo;
    No* b = p2->topo;

    while (a != NULL && b != NULL) {
        if (strcmp(a->texto, b->texto) != 0)
            return 0;

        a = a->prox;
        b = b->prox;
    }

    return (a == NULL && b == NULL);
}

// ================= INVERTER STRING =================
void inverter_string(char str[]) {
    Pilha p;
    inicializar(&p);

    for (int i = 0; str[i] != '\0'; i++) {
        char temp[2] = {str[i], '\0'};
        push(&p, temp, 0, 0, "");
    }

    No n;
    int i = 0;
    while (pop(&p, &n)) {
        str[i++] = n.texto[0];
    }

    str[i] = '\0';
}

// ================= DECIMAL PARA BINÁRIO =================
void decimal_para_binario(int num) {
    Pilha p;
    inicializar(&p);

    while (num > 0) {
        char temp[2];
        sprintf(temp, "%d", num % 2);
        push(&p, temp, 0, 0, "");
        num /= 2;
    }

    No n;
    while (pop(&p, &n)) {
        printf("%s", n.texto);
    }
    printf("\n");
}

// ================= VALIDADOR =================
int validar(char exp[]) {
    Pilha p;
    inicializar(&p);

    for (int i = 0; exp[i]; i++) {
        char c = exp[i];

        if (c == '(' || c == '[' || c == '{') {
            char temp[2] = {c, '\0'};
            push(&p, temp, 0, 0, "");
        } else if (c == ')' || c == ']' || c == '}') {
            No n;
            if (!pop(&p, &n)) return 0;

            if ((c == ')' && n.texto[0] != '(') ||
                (c == ']' && n.texto[0] != '[') ||
                (c == '}' && n.texto[0] != '{')) {
                return 0;
            }
        }
    }

    return estaVazia(&p);
}

// ================= ORDENAR PILHA =================
void ordenar(Pilha* p) {
    Pilha aux;
    inicializar(&aux);

    No temp;

    while (!estaVazia(p)) {
        pop(p, &temp);

        while (!estaVazia(&aux) && strcmp(aux.topo->texto, temp.texto) > 0) {
            No t2;
            pop(&aux, &t2);
            push(p, t2.texto, 0, 0, "");
        }

        push(&aux, temp.texto, 0, 0, "");
    }

    while (!estaVazia(&aux)) {
        No t;
        pop(&aux, &t);
        push(p, t.texto, 0, 0, "");
    }
}

// ================= FILTRO URGÊNCIA =================
void filtrar(Pilha* origem, Pilha* destino) {
    Pilha aux;
    inicializar(&aux);

    No temp;

    while (!estaVazia(origem)) {
        pop(origem, &temp);

        if (temp.urgencia == 5) {
            push(destino, temp.texto, temp.urgencia, temp.id, temp.tecnico);
        } else {
            push(&aux, temp.texto, temp.urgencia, temp.id, temp.tecnico);
        }
    }

    while (!estaVazia(&aux)) {
        pop(&aux, &temp);
        push(origem, temp.texto, temp.urgencia, temp.id, temp.tecnico);
    }
}

// ================= MAIN (TESTE) =================

int main() {
    Pilha p;
    inicializar(&p);

    push(&p, "Ação 1", 3, 1, "Joao");
    push(&p, "Ação 2", 5, 2, "Maria");

    peek(&p);

    printf("Total: %d\n", count(&p));

    decimal_para_binario(10);

    char str[] = "teste";
    inverter_string(str);
    printf("Invertida: %s\n", str);

    if (validar("{[()]}"))
        printf("Expressão válida\n");
    else
        printf("Inválida\n");

    limpar_pilha(&p);

    return 0;
}