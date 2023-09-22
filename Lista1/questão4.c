#include <stdio.h>
#include <string.h>

#define MAX_CONTATOS 100

struct Contato {
    char nome[50];
    char telefone[20];
};

void adicionarContato(struct Contato contatos[], int *totalContatos) {
    if (*totalContatos < MAX_CONTATOS) {
        printf("Digite o nome do contato: ");
        scanf("%s", contatos[*totalContatos].nome);

        printf("Digite o telefone do contato: ");
        scanf("%s", contatos[*totalContatos].telefone);

        (*totalContatos)++;
        printf("Contato adicionado com sucesso!\n");
    } else {
        printf("Limite de contatos atingido. Nao e possivel adicionar mais contatos.\n");
    }
}

void listarContatos(struct Contato contatos[], int totalContatos) {
    if (totalContatos > 0) {
        printf("Lista de contatos:\n");
        for (int i = 0; i < totalContatos; i++) {
            printf("Nome: %s, Telefone: %s\n", contatos[i].nome, contatos[i].telefone);
        }
    } else {
        printf("Nenhum contato disponivel.\n");
    }
}

void buscarContato(struct Contato contatos[], int totalContatos, char nomeBuscado[]) {
    int encontrado = 0;
    for (int i = 0; i < totalContatos; i++) {
        if (strcmp(contatos[i].nome, nomeBuscado) == 0) {
            printf("Contato encontrado:\n");
            printf("Nome: %s, Telefone: %s\n", contatos[i].nome, contatos[i].telefone);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Contato nao encontrado.\n");
    }
}

int main() {
    struct Contato contatos[MAX_CONTATOS];
    int totalContatos = 0;
    int opcao;
    char nomeBuscado[50];

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Contato\n");
        printf("2. Listar Contatos\n");
        printf("3. Buscar Contato\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato(contatos, &totalContatos);
                break;
            case 2:
                listarContatos(contatos, totalContatos);
                break;
            case 3:
                printf("Digite o nome do contato a ser buscado: ");
                scanf("%s", nomeBuscado);
                buscarContato(contatos, totalContatos, nomeBuscado);
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
