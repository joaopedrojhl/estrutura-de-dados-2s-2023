#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto {
    char nome[50];
    float preco;
    int quantidade;
};

// Função para calcular o total da compra
float calcularTotalDaCompra(struct Produto produtos[], int numProdutos) {
    float total = 0.0;
    for (int i = 0; i < numProdutos; i++) {
        total += produtos[i].preco * produtos[i].quantidade;
    }
    return total;
}

int main() {
    int numProdutos;
    printf("Quantos produtos deseja comprar? ");
    scanf("%d", &numProdutos);

    struct Produto *produtos = malloc(numProdutos * sizeof(struct Produto));

    // Preencher os detalhes dos produtos
    for (int i = 0; i < numProdutos; i++) {
        printf("Produto #%d:\n", i + 1);

        printf("Nome: ");
        scanf("%s", produtos[i].nome);

        printf("Preço: ");
        scanf("%f", &produtos[i].preco);

        printf("Quantidade em estoque: ");
        scanf("%d", &produtos[i].quantidade);
    }

    printf("\nLista de Produtos:\n");
    printf("Nome\tPreço\tQuantidade\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("%s\t%.2f\t%d\n", produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
    }

    // Comprar produtos
    printf("\nFaça suas compras:\n");
    float totalCompra = 0.0;
    for (int i = 0; i < numProdutos; i++) {
        int quantidadeCompra;
        printf("Quantidade de %s desejada: ", produtos[i].nome);
        scanf("%d", &quantidadeCompra);

        if (quantidadeCompra <= 0) {
            printf("Quantidade inválida!\n");
            continue;
        }

        if (quantidadeCompra > produtos[i].quantidade) {
            printf("Estoque insuficiente para %s!\n", produtos[i].nome);
        } else {
            produtos[i].quantidade -= quantidadeCompra;
            totalCompra += produtos[i].preco * quantidadeCompra;
            printf("%d unidades de %s adicionadas ao carrinho.\n", quantidadeCompra, produtos[i].nome);
        }
    }

    printf("\nTotal da Compra: R$%.2f\n", totalCompra);

    // Liberar a memória alocada
    free(produtos);

    return 0;
}
