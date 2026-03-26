
#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 100
#define MAX_EMPRESTIMOS 10

typedef struct {
    char nome[100];
    char cpf[20];
} Pessoa;

typedef struct {
    char titulo[100];
    char autor[100];
    int ano;
    int id;
    int quantidadeDisponivel;
    int quantidadeTotal;
    Pessoa pessoas[MAX_EMPRESTIMOS];
    int contadorPessoas;
} Livro;

typedef struct {
    Livro livros[MAX_LIVROS];
    int contadorLivros;
} Biblioteca;

int buscarLivroPorId(Biblioteca *b, int id) {
    for (int i = 0; i < b->contadorLivros; i++) {
        if (b->livros[i].id == id) {
            return i;
        }
    }
    return -1;
}

void cadastrarLivro(Biblioteca *b) {
    if (b->contadorLivros >= MAX_LIVROS) {
        printf("Limite de livros atingido.\n");
        return;
    }

    Livro novo;

    printf("ID: ");
    scanf("%d", &novo.id);

    if (buscarLivroPorId(b, novo.id) != -1) {
        printf("ID ja existente.\n");
        return;
    }

    printf("Titulo: ");
    scanf(" %[^\n]", novo.titulo);

    printf("Autor: ");
    scanf(" %[^\n]", novo.autor);

    printf("Ano: ");
    scanf("%d", &novo.ano);

    printf("Quantidade de exemplares (max 10): ");
    scanf("%d", &novo.quantidadeTotal);

    if (novo.quantidadeTotal > 10) novo.quantidadeTotal = 10;

    novo.quantidadeDisponivel = novo.quantidadeTotal;
    novo.contadorPessoas = 0;

    b->livros[b->contadorLivros] = novo;
    b->contadorLivros++;

    printf("Livro cadastrado.\n");
}

void listarLivros(Biblioteca *b) {
    for (int i = 0; i < b->contadorLivros; i++) {
        Livro l = b->livros[i];
        printf("\nID: %d\n", l.id);
        printf("Titulo: %s\n", l.titulo);
        printf("Autor: %s\n", l.autor);
        printf("Ano: %d\n", l.ano);
        printf("Disponivel: %d\n", l.quantidadeDisponivel);
    }
}

void buscarLivro(Biblioteca *b) {
    int id;
    printf("Digite o ID: ");
    scanf("%d", &id);

    int pos = buscarLivroPorId(b, id);

    if (pos == -1) {
        printf("Livro nao encontrado.\n");
        return;
    }

    Livro l = b->livros[pos];

    printf("Titulo: %s\n", l.titulo);
    printf("Autor: %s\n", l.autor);
    printf("Ano: %d\n", l.ano);
    printf("Disponivel: %d\n", l.quantidadeDisponivel);
}

int pessoaJaPegou(Livro *l, char cpf[]) {
    for (int i = 0; i < l->contadorPessoas; i++) {
        if (strcmp(l->pessoas[i].cpf, cpf) == 0) {
            return 1;
        }
    }
    return 0;
}

void emprestarLivro(Biblioteca *b) {
    int id;
    printf("ID do livro: ");
    scanf("%d", &id);

    int pos = buscarLivroPorId(b, id);

    if (pos == -1) {
        printf("Livro nao encontrado.\n");
        return;
    }

    Livro *l = &b->livros[pos];

    if (l->quantidadeDisponivel == 0) {
        printf("Sem exemplares disponiveis.\n");
        return;
    }

    Pessoa p;

    printf("Nome: ");
    scanf(" %[^\n]", p.nome);

    printf("CPF: ");
    scanf(" %[^\n]", p.cpf);

    if (pessoaJaPegou(l, p.cpf)) {
        printf("Pessoa ja pegou este livro.\n");
        return;
    }

    l->pessoas[l->contadorPessoas] = p;
    l->contadorPessoas++;
    l->quantidadeDisponivel--;

    printf("Emprestimo realizado.\n");
}

void devolverLivro(Biblioteca *b) {
    int id;
    char cpf[20];

    printf("ID do livro: ");
    scanf("%d", &id);

    int pos = buscarLivroPorId(b, id);

    if (pos == -1) {
        printf("Livro nao encontrado.\n");
        return;
    }

    Livro *l = &b->livros[pos];

    printf("CPF da pessoa: ");
    scanf(" %[^\n]", cpf);

    int encontrado = -1;

    for (int i = 0; i < l->contadorPessoas; i++) {
        if (strcmp(l->pessoas[i].cpf, cpf) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Emprestimo nao encontrado.\n");
        return;
    }

    for (int i = encontrado; i < l->contadorPessoas - 1; i++) {
        l->pessoas[i] = l->pessoas[i + 1];
    }

    l->contadorPessoas--;
    l->quantidadeDisponivel++;

    printf("Livro devolvido.\n");
}

void removerLivro(Biblioteca *b) {
    int id;
    printf("ID do livro: ");
    scanf("%d", &id);

    int pos = buscarLivroPorId(b, id);

    if (pos == -1) {
        printf("Livro nao encontrado.\n");
        return;
    }

    for (int i = pos; i < b->contadorLivros - 1; i++) {
        b->livros[i] = b->livros[i + 1];
    }

    b->contadorLivros--;

    printf("Livro removido.\n");
}

int main() {
    Biblioteca biblioteca;
    biblioteca.contadorLivros = 0;

    int opcao;

    do {
        printf("\n1 Cadastrar livro\n");
        printf("2 Listar livros\n");
        printf("3 Buscar livro\n");
        printf("4 Emprestar livro\n");
        printf("5 Devolver livro\n");
        printf("6 Remover livro\n");
        printf("7 Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: cadastrarLivro(&biblioteca); break;
            case 2: listarLivros(&biblioteca); break;
            case 3: buscarLivro(&biblioteca); break;
            case 4: emprestarLivro(&biblioteca); break;
            case 5: devolverLivro(&biblioteca); break;
            case 6: removerLivro(&biblioteca); break;
        }

    } while (opcao != 7);

    return 0;
}
