#include <stdio.h>

struct Moeda {
    double dolares;
    double euros;
};

// Função para converter dólares em euros usando uma taxa de câmbio
double converterDolaresParaEuros(double dolares, double taxaCambio) {
    return dolares * taxaCambio;
}

// Função para converter euros em dólares usando uma taxa de câmbio
double converterEurosParaDolares(double euros, double taxaCambio) {
    return euros / taxaCambio;
}

int main() {
    struct Moeda moeda;

    // Taxa de câmbio atual (exemplo)
    double taxaCambioAtual = 0.85; // 1 dólar = 0.85 euros

    printf("Digite o valor em dólares: ");
    scanf("%lf", &moeda.dolares);

    printf("Digite o valor em euros: ");
    scanf("%lf", &moeda.euros);

    int escolha;
    printf("\nEscolha a operação:\n");
    printf("1. Converter dólares para euros\n");
    printf("2. Converter euros para dólares\n");
    printf("Digite 1 ou 2: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            printf("Valor em euros: %.2lf\n", converterDolaresParaEuros(moeda.dolares, taxaCambioAtual));
            break;
        case 2:
            printf("Valor em dólares: %.2lf\n", converterEurosParaDolares(moeda.euros, taxaCambioAtual));
            break;
        default:
            printf("Escolha inválida!\n");
            break;
    }

    return 0;
}
