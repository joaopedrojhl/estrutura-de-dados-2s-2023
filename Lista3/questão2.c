#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar um item da lista de compras
struct ItemCompra {
    char nome[50];
    struct ItemCompra *prox;
};

// Função para criar um novo item de compra
struct ItemCompra *criarItemCompra(const char *nome) {
    struct ItemCompra *novoItem = (struct ItemCompra *)malloc(sizeof(struct ItemCompra));
    strcpy(novoItem->nome, nome);
    novoItem->prox = NULL;
    return novoItem;
}

// Função para inserir um item na lista de compras de forma ordenada
void inserirListaOrdenada(struct ItemCompra **head, const char *nome) {
    struct ItemCompra *novoItem = criarItemCompra(nome);
    struct ItemCompra *atual = *head;
    struct ItemCompra *anterior = NULL;

    // Encontre a posição correta para inserir o novo item
    while (atual != NULL && strcmp(atual->nome, nome) < 0) {
        anterior = atual;
        atual = atual->prox;
    }

    // Caso especial: o novo item será o primeiro da lista
    if (anterior == NULL) {
        novoItem->prox = *head;
        *head = novoItem;
    } else {
        // Inserção entre dois itens existentes ou no final da lista
        anterior->prox = novoItem;
        novoItem->prox = atual;
    }
}

// Função para imprimir a lista de compras
void imprimirLista(struct ItemCompra *head) {
    struct ItemCompra *atual = head;
    printf("Lista de Compras:\n");
    while (atual != NULL) {
        printf("%s\n", atual->nome);
        atual = atual->prox;
    }
}

// Função para liberar a memória alocada para a lista de compras
void liberarLista(struct ItemCompra *head) {
    struct ItemCompra *atual = head;
    while (atual != NULL) {
        struct ItemCompra *temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

int main() {
    struct ItemCompra *listaCompras = NULL;
    int tamanho;
    printf("Digite o número de itens na lista de compras: ");
    scanf("%d", &tamanho);

    for (int i = 0; i < tamanho; i++) {
        char nome[50];
        printf("Digite o nome do item %d: ", i + 1);
        scanf("%s", nome);
        inserirListaOrdenada(&listaCompras, nome);
    }

    printf("Lista de Compras Ordenada:\n");
    imprimirLista(listaCompras);

    // Liberar a memória alocada para a lista de compras
    liberarLista(listaCompras);

    return 0;
}
