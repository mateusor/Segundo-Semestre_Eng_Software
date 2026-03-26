#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contato {
    char nome[50];
    char celular[15];
    struct Contato* esquerda;
    struct Contato* direita;
} Contato;

Contato* inserir(Contato* raiz, Contato* novo);
Contato* buscar(Contato* raiz, const char* nome);
Contato* remover(Contato* raiz, const char* nome);
Contato* encontrarMenor(Contato* raiz);
void ImprimirArvoreDeContatos(Contato* raiz);
void liberarArvore(Contato* raiz);
void menu();

int main() {
    Contato* raiz = NULL;
    int opcao;
    
    do {
        menu();
        scanf("%d", &opcao);
        getchar();
        
        switch (opcao) {
            case 1: {
                Contato* novo = (Contato*)malloc(sizeof(Contato));
                printf("Nome: ");
                scanf(" %[^\n]", novo->nome);
                printf("Celular: ");
                scanf(" %[^\n]", novo->celular);
                novo->esquerda = NULL;
                novo->direita = NULL;
                raiz = inserir(raiz, novo);
                printf("\nContato adicionado com sucesso!\n\n");
                break;
            }
            case 2: {
                char nome[50];
                printf("Nome para buscar: ");
                scanf(" %[^\n]", nome);
                Contato* encontrado = buscar(raiz, nome);
                if (encontrado) {
                    printf("\nContato encontrado:\nNome: %s\nCelular: %s\n\n", encontrado->nome, encontrado->celular);
                } else {
                    printf("\nContato não encontrado.\n\n");
                }
                break;
            }
            case 3: {
                char nome[50];
                printf("Nome para remover: ");
                scanf(" %[^\n]", nome);
                Contato* encontrado = buscar(raiz, nome);
                if (encontrado) {
                    raiz = remover(raiz, nome);
                    printf("\nContato removido com sucesso!\n\n");
                } else {
                    printf("\nContato não encontrado.\n\n");
                }
                break;
            }
            case 4: {
                printf("\nContatos:\n");
                if (raiz == NULL) {
                    printf("Nenhum contato cadastrado.\n\n");
                } else {
                    ImprimirArvoreDeContatos(raiz);
                    printf("\n");
                }
                break;
            }
            case 5:
                liberarArvore(raiz);
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n\n");
        }
    } while (opcao != 5);
    
    return 0;
}

Contato* inserir(Contato* raiz, Contato* novo) {
    if (raiz == NULL) return novo;
    int comparacao = strcmp(novo->nome, raiz->nome);
    if (comparacao < 0) raiz->esquerda = inserir(raiz->esquerda, novo);
    else if (comparacao > 0) raiz->direita = inserir(raiz->direita, novo);
    else {
        strcpy(raiz->celular, novo->celular);
        free(novo);
    }
    return raiz;
}

Contato* buscar(Contato* raiz, const char* nome) {
    if (raiz == NULL || strcmp(raiz->nome, nome) == 0) return raiz;
    int comparacao = strcmp(nome, raiz->nome);
    if (comparacao < 0) return buscar(raiz->esquerda, nome);
    else return buscar(raiz->direita, nome);
}

Contato* encontrarMenor(Contato* raiz) {
    while (raiz->esquerda != NULL) raiz = raiz->esquerda;
    return raiz;
}

Contato* remover(Contato* raiz, const char* nome) {
    if (raiz == NULL) return raiz;
    int comparacao = strcmp(nome, raiz->nome);
    if (comparacao < 0) raiz->esquerda = remover(raiz->esquerda, nome);
    else if (comparacao > 0) raiz->direita = remover(raiz->direita, nome);
    else {
        if (raiz->esquerda == NULL) {
            Contato* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            Contato* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        Contato* temp = encontrarMenor(raiz->direita);
        strcpy(raiz->nome, temp->nome);
        strcpy(raiz->celular, temp->celular);
        raiz->direita = remover(raiz->direita, temp->nome);
    }
    return raiz;
}

void ImprimirArvoreDeContatos(Contato* raiz) {
    if (raiz != NULL) {
        ImprimirArvoreDeContatos(raiz->esquerda);
        printf("- %s, Celular: %s\n", raiz->nome, raiz->celular);
        ImprimirArvoreDeContatos(raiz->direita);
    }
}

void liberarArvore(Contato* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

void menu() {
    printf("Menu:\n");
    printf("1. Adicionar contato\n");
    printf("2. Buscar contato\n");
    printf("3. Remover contato\n");
    printf("4. Listar contatos\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
}
