# Exercícios Teóricos

## Exercício 1 — Identificando partes da árvore

Árvore:
```
        10
       /  \
      5    20
     / \     \
    3   7     30
```

**a) Qual é a raiz?**  
A raiz é o nó **10** — é o nó do topo, sem pai.

**b) Quais são as folhas?**  
As folhas são **3**, **7** e **30** — nós sem filhos.

**c) Quais são os filhos do nó 5?**  
Os filhos de 5 são **3** (esquerda) e **7** (direita).

**d) Qual é o pai do nó 30?**  
O pai do nó 30 é o nó **20**.

**e) Essa árvore é binária? Justifique.**  
Sim. É binária porque cada nó possui **no máximo dois filhos**
(esquerdo e direito). Nenhum nó possui mais de dois filhos.

---

## Exercício 2 — Desenhando uma BST

Inserção: **8, 4, 12, 2, 6, 10, 14**

```
           8
          / \
         4   12
        / \  / \
       2   6 10  14
```

Passo a passo:
- 8 → raiz
- 4 < 8 → esquerda do 8
- 12 > 8 → direita do 8
- 2 < 8, 2 < 4 → esquerda do 4
- 6 < 8, 6 > 4 → direita do 4
- 10 > 8, 10 < 12 → esquerda do 12
- 14 > 8, 14 > 12 → direita do 12

---

## Exercício 5 — Inserção manual

Inserção: **50, 30, 70, 20, 40, 60, 80**

```
           50
          /  \
        30    70
       / \   / \
      20  40 60  80
```

**a)** Quem fica à esquerda do 50? → **30**  
**b)** Quem fica à direita do 50? → **70**  
**c)** O valor 40 fica à **direita** do 30 (40 > 30)  
**d)** O valor 80 fica à **direita** do 70 (80 > 70)

---

## Exercício 7 — Caminhos de busca

Árvore:
```
        50
       /  \
     30    70
    / \   / \
  20  40 60  80
```

**Buscar 40:**  
50 → 40 < 50, vai esquerda → 30 → 40 > 30, vai direita → **40. Encontrado.**

**Buscar 80:**  
50 → 80 > 50, vai direita → 70 → 80 > 70, vai direita → **80. Encontrado.**

**Buscar 25:**  
50 → 25 < 50, vai esquerda → 30 → 25 < 30, vai esquerda → 20 → 25 > 20, vai direita → NULL. **Não encontrado.**

**Buscar 60:**  
50 → 60 > 50, vai direita → 70 → 60 < 70, vai esquerda → **60. Encontrado.**
