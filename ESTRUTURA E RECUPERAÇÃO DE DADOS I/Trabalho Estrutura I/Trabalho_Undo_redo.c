#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char* texto;
    struct No* prox;
} No;

typedef struct {
    No* topo;
} Pilha;

Pilha* criarPilha() {
    Pilha* p = malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void empilhar(Pilha* p, char* palavra) {
    No* novo = malloc(sizeof(No));
    novo->texto = malloc(strlen(palavra) + 1);
    strcpy(novo->texto, palavra);
    novo->prox = p->topo;
    p->topo = novo;
}

char* desempilhar(Pilha* p) {
    if (p->topo == NULL) return NULL;
    No* r = p->topo;
    char* txt = r->texto;
    p->topo = r->prox;
    free(r);
    return txt;
}

void imprimirRec(No* n) {
    if (n == NULL) return;
    imprimirRec(n->prox);
    printf("%s ", n->texto);
}

void imprimirFrase(Pilha* p) {
    imprimirRec(p->topo);
    printf("\n");
}

void esvaziar(Pilha* p) {
    while (p->topo != NULL) {
        char* t = desempilhar(p);
        free(t);
    }
}

int main() {
    Pilha* undo = criarPilha();
    Pilha* redo = criarPilha();
    int op;
    char palavra[100];

    while (1) {
        printf("\nDigite a opção desejada:\n");
        printf("0 – Digitar nova palavra da frase\n");
        printf("1 – Desfazer (Undo)\n");
        printf("2 – Refazer (Redo)\n");
        printf("3 – Imprimir a frase\n");
        printf("4 – Sair\n");
        printf("Qual opção? ");
        scanf("%d", &op);

        if (op == 0) {
            printf("Digite a palavra: ");
            scanf("%s", palavra);
            empilhar(undo, palavra);
            esvaziar(redo);

        } else if (op == 1) {
            char* r = desempilhar(undo);
            if (r == NULL) {
                printf("Nada a desfazer\n");
            } else {
                empilhar(redo, r);
                free(r);
            }

        } else if (op == 2) {
            char* r = desempilhar(redo);
            if (r == NULL) {
                printf("Nada a refazer\n");
            } else {
                empilhar(undo, r);
                free(r);
            }

        } else if (op == 3) {
            imprimirFrase(undo);

        } else if (op == 4) {
            break;
        }
    }

    esvaziar(undo);
    esvaziar(redo);
    free(undo);
    free(redo);

    return 0;
}
