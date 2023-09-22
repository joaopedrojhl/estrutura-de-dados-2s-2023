#include <stdio.h>

struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};

int main() {
    struct Pessoa pessoa;

    printf("Digite o nome: ");
    scanf("%s", pessoa.nome);

    printf("Digite a idade: ");
    scanf("%d", &pessoa.idade);

    printf("Digite a altura: ");
    scanf("%f", &pessoa.altura);

    printf("Dados da pessoa:\n");
    printf("Nome: %s\n", pessoa.nome);
    printf("Idade: %d anos\n", pessoa.idade);
    printf("Altura: %.2f metros\n", pessoa.altura);

    return 0;
}
