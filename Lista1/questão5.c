#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 100

struct Livro {
    char titulo[100];
    char autor[50];
    int anoPublicacao;
};

void adicionarLivro(struct Livro livros[], int *totalLivros) {
    if (*totalLivros < MAX_LIVROS) {
        printf("Digite o titulo do livro: ");
        scanf(" %[^\n]", livros[*totalLivros].titulo);

        printf("Digite o autor do livro: ");
        scanf(" %[^\n]", livros[*totalLivros].autor);

        printf("Digite o ano de publicacao do livro: ");
        scanf("%d", &livros[*totalLivros].anoPublicacao);

        (*totalLivros)++;
        printf("Livro adicionado com sucesso!\n");
    } else {
        printf("Limite de livros atingido. Nao e possivel adicionar mais livros.\n");
    }
}

void listarLivros(struct Livro livros[], int totalLivros) {
    if (totalLivros > 0) {
        printf("Lista de livros:\n");
        for (int i = 0; i < totalLivros; i++) {
            printf("Titulo: %s, Autor: %s, Ano de Publicacao: %d\n", livros[i].titulo, livros[i].autor, livros[i].anoPublicacao);
        }
    } else {
        printf("Nenhum livro cadastrado.\n");
    }
}

void buscarLivrosPorAutor(struct Livro livros[], int totalLivros, char autorBuscado[]) {
    int encontrados = 0;
    printf("Livros do autor %s:\n", autorBuscado);
    for (int i = 0; i < totalLivros; i++) {
        if (strcmp(livros[i].autor, autorBuscado) == 0) {
            printf("Titulo: %s, Ano de Publicacao: %d\n", livros[i].titulo, livros[i].anoPublicacao);
            encontrados = 1;
        }
    }
    if (!encontrados) {
        printf("Nenhum livro encontrado para este autor.\n");
    }
}

int main() {
    struct Livro livros[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;
    char autorBuscado[50];

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Livro\n");
        printf("2. Listar Livros\n");
        printf("3. Buscar Livros por Autor\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarLivro(livros, &totalLivros);
                break;
            case 2:
                listarLivros(livros, totalLivros);
                break;
            case 3:
                printf("Digite o nome do autor: ");
                scanf(" %[^\n]", autorBuscado);
                buscarLivrosPorAutor(livros, totalLivros, autorBuscado);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 4);

    return 0;
}
