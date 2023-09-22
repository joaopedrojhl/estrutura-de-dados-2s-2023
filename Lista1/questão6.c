#include <stdio.h>

struct Estudante {
    char nome[50];
    int matricula;
    float notas[3];
};

// Função para calcular a média das notas de um estudante
float calcularMedia(struct Estudante estudante) {
    float soma = 0;
    for (int i = 0; i < 3; i++) {
        soma += estudante.notas[i];
    }
    return soma / 3;
}

// Função para verificar se um estudante está aprovado (média maior ou igual a 7)
int estaAprovado(struct Estudante estudante) {
    float media = calcularMedia(estudante);
    return (media >= 7);
}

int main() {
    struct Estudante estudante;

    printf("Digite o nome do estudante: ");
    scanf("%s", estudante.nome);

    printf("Digite a matricula do estudante: ");
    scanf("%d", &estudante.matricula);

    printf("Digite as notas do estudante (3 notas separadas por espaco): ");
    for (int i = 0; i < 3; i++) {
        scanf("%f", &estudante.notas[i]);
    }

    printf("Nome do estudante: %s\n", estudante.nome);
    printf("Matricula: %d\n", estudante.matricula);
    printf("Notas: %.2f, %.2f, %.2f\n", estudante.notas[0], estudante.notas[1], estudante.notas[2]);

    float media = calcularMedia(estudante);
    printf("Media das notas: %.2f\n", media);

    if (estaAprovado(estudante)) {
        printf("O estudante esta aprovado.\n");
    } else {
        printf("O estudante nao esta aprovado.\n");
    }

    return 0;
}
