#include <stdio.h>

struct ContaBancaria {
    char nomeTitular[50];
    int numeroConta;
    float saldo;
};

void depositar(struct ContaBancaria *conta, float valor) {
    conta->saldo += valor;
}

int sacar(struct ContaBancaria *conta, float valor) {
    if (valor <= conta->saldo) {
        conta->saldo -= valor;
        return 1; // Saque bem-sucedido
    } else {
        return 0; // Saldo insuficiente
    }
}

void verificarSaldo(struct ContaBancaria conta) {
    printf("Saldo atual da conta de %s: %.2f\n", conta.nomeTitular, conta.saldo);
}

int main() {
    struct ContaBancaria conta;
    conta.saldo = 1000; // Saldo inicial

    printf("Digite o nome do titular da conta: ");
    scanf("%s", conta.nomeTitular);

    printf("Digite o numero da conta: ");
    scanf("%d", &conta.numeroConta);

    int opcao;
    float valor;

    do {
        printf("\nMenu:\n");
        printf("1. Depositar\n");
        printf("2. Sacar\n");
        printf("3. Verificar Saldo\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser depositado: ");
                scanf("%f", &valor);
                depositar(&conta, valor);
                break;
            case 2:
                printf("Digite o valor a ser sacado: ");
                scanf("%f", &valor);
                if (sacar(&conta, valor)) {
                    printf("Saque bem-sucedido.\n");
                } else {
                    printf("Saldo insuficiente. Saque nao realizado.\n");
                }
                break;
            case 3:
                verificarSaldo(conta);
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
