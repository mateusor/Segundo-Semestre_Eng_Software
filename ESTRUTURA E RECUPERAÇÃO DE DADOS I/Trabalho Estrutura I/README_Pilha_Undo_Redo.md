# 🧠 Editor de Frases com Undo/Redo (Pilha em C)

Projeto desenvolvido em linguagem **C** que simula um pequeno editor de
frases utilizando **estruturas de dados do tipo Pilha**.

O sistema permite digitar palavras e realizar operações de **desfazer
(Undo)** e **refazer (Redo)** utilizando duas pilhas.

------------------------------------------------------------------------

# 🎯 Objetivo

Demonstrar o funcionamento da estrutura de dados **Pilha (Stack)**
através de um programa interativo no terminal.

O programa armazena palavras digitadas pelo usuário e permite manipular
a frase com operações de histórico.

------------------------------------------------------------------------

# ⚙️ Funcionalidades

O menu do programa possui as seguintes opções:

0 -- Digitar nova palavra da frase\
1 -- Desfazer (Undo)\
2 -- Refazer (Redo)\
3 -- Imprimir a frase\
4 -- Sair

------------------------------------------------------------------------

# 🧱 Estrutura de Dados

O programa utiliza:

-   **Struct No** → representa cada elemento da pilha
-   **Struct Pilha** → representa a pilha
-   Duas pilhas principais:
    -   `undo`
    -   `redo`

Isso permite armazenar o histórico das ações realizadas.

------------------------------------------------------------------------

# 🔄 Funcionamento do Undo/Redo

1.  Quando uma nova palavra é digitada, ela é **empilhada na pilha
    Undo**.
2.  Ao desfazer:
    -   o elemento é removido da pilha **Undo**
    -   e enviado para a pilha **Redo**
3.  Ao refazer:
    -   o elemento é removido da pilha **Redo**
    -   e retorna para a pilha **Undo**.

------------------------------------------------------------------------

# ▶️ Como Executar

Compile o programa:

``` bash
gcc trabalho.c -o programa
```

Execute:

``` bash
./programa
```

------------------------------------------------------------------------

# 🛠 Conceitos Utilizados

-   Estrutura de dados **Pilha**
-   Alocação dinâmica de memória (`malloc`)
-   Manipulação de **strings**
-   Recursividade para impressão da frase
