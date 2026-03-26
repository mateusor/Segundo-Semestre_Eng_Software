# 📱 Agenda de Contatos com Árvore Binária (C)

Projeto em **linguagem C** que implementa uma **agenda de contatos**
utilizando uma **Árvore Binária de Busca (Binary Search Tree - BST)**.

Os contatos são organizados automaticamente em ordem alfabética pelo
**nome**.

------------------------------------------------------------------------

# 🎯 Objetivo

Demonstrar o uso da estrutura de dados **Árvore Binária de Busca** para
armazenar e manipular informações de forma eficiente.

------------------------------------------------------------------------

# ⚙️ Funcionalidades

O sistema possui um menu interativo:

1.  Adicionar contato\
2.  Buscar contato\
3.  Remover contato\
4.  Listar contatos\
5.  Sair

------------------------------------------------------------------------

# 🧱 Estrutura de Dados

Cada contato possui:

-   Nome
-   Celular

Estrutura utilizada:

``` c
typedef struct Contato {
    char nome[50];
    char celular[15];
    struct Contato* esquerda;
    struct Contato* direita;
} Contato;
```

A árvore organiza os contatos utilizando **comparação alfabética do
nome**.

------------------------------------------------------------------------

# 🔎 Operações Implementadas

### Inserção

Adiciona um novo contato respeitando a ordem da árvore.

### Busca

Localiza um contato pelo nome.

### Remoção

Remove um contato mantendo a estrutura correta da árvore.

### Listagem

Imprime todos os contatos em **ordem alfabética** usando percurso
**in-order**.

------------------------------------------------------------------------

# ▶️ Como Executar

Compile o programa:

``` bash
gcc agenda.c -o agenda
```

Execute:

``` bash
./agenda
```

------------------------------------------------------------------------

# 🛠 Conceitos Utilizados

-   Estrutura de dados **Árvore Binária de Busca**
-   Recursividade
-   Alocação dinâmica de memória
-   Comparação de strings (`strcmp`)
