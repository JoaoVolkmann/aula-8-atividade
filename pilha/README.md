# 📚 Estrutura de Dados - Pilha em C

## 👨‍💻 Autor

* Nome: SEU NOME AQUI
* Curso: SEU CURSO
* Disciplina: Estrutura de Dados

---

## 📌 Descrição

Este projeto implementa uma **pilha utilizando lista encadeada (alocação dinâmica)**, respeitando o conceito **LIFO (Last In, First Out)**.

O objetivo é demonstrar o funcionamento de operações fundamentais e aplicações práticas da estrutura de dados pilha.

---

## ⚙️ Funcionalidades

### 🔹 Parte 1 - Fundamentos

* Push (empilhar)
* Pop (desempilhar)
* Peek (visualizar topo)
* Contagem de elementos
* Limpeza de memória

### 🔹 Parte 2 - Aplicações

* Inversão de string
* Conversão decimal para binário

### 🔹 Parte 3 - Avançado

* Validação de expressões ((), [], {})
* Comparação de pilhas
* Ordenação usando pilha auxiliar
* Filtro por prioridade (urgência 5)

---

## 🧠 Estrutura utilizada

A pilha foi implementada com **lista encadeada**, utilizando a estrutura:

```c
typedef struct No {
    char texto[100];
    struct No* prox;
} No;
```

---

## ▶️ Como executar

### 1. Compilar:

```bash
gcc main.c -o programa
```

### 2. Executar:

```bash
./programa
```

---

## ⚠️ Tratamento de erros

O programa trata:

* Pilha vazia
* Falha de alocação de memória (malloc)

---

## 💡 Observações

* Não foi utilizado vetor em nenhuma operação
* Todas as operações respeitam o conceito LIFO
* A pilha permanece intacta quando necessário (ex: contagem e comparação)

---

## 🚀 Tecnologias utilizadas

* Linguagem C
* VS Code
* Git/GitHub
