# Tarefa 8 — Árvores Binárias de Busca

**Aluno:** João Volkmann  
**Disciplina:** Estrutura de Dados  

---

## Descrição

Implementação de uma Árvore Binária de Busca (BST) em linguagem C,
com exercícios teóricos e práticos cobrindo inserção, busca, remoção
e percursos.

---

## Estrutura dos arquivos

```
tarefa-8-arvores/
├── README.md
├── ex01_conceitos.md        → Exercícios 1, 2 e 5 (teóricos)
├── ex03_struct.c            → Exercício 3 — struct do nó
├── ex04_criarNo.c           → Exercício 4 — função criarNo
├── ex06_insercao.c          → Exercício 6 — função inserir
├── ex07_busca_caminho.md    → Exercício 7 — caminhos de busca
├── ex08_buscar.c            → Exercício 8 — função buscar
├── ex09_emOrdem.c           → Exercício 9 — percurso em ordem
├── ex10_main.c              → Exercício 10 — programa de teste
└── ex11_completo.c          → Exercício 11 — implementação completa
```

---

## Como compilar e executar

Qualquer arquivo `.c` pode ser compilado com GCC:

```bash
gcc ex10_main.c -o ex10 && ./ex10
gcc ex11_completo.c -o ex11 && ./ex11
```

---

## Como a árvore funciona

Uma **Árvore Binária de Busca** organiza os valores seguindo a regra:

- Valores **menores** que o nó atual vão para a **esquerda**
- Valores **maiores** que o nó atual vão para a **direita**

Isso permite buscar, inserir e remover em **O(log n)** no caso médio.

### Percurso em ordem (esquerda → raiz → direita)
Sempre imprime os valores em **ordem crescente**.

### Remoção — três casos:
| Caso | Situação | Solução |
|------|----------|---------|
| A | Nó folha | Remove diretamente |
| B | Um filho | Substitui pelo filho |
| C | Dois filhos | Substitui pelo sucessor in-order |
