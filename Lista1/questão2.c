#include <stdio.h>

struct Tipo {
    int inteiro;
    float pontoFlutuante;
    char letra;
};

int main() {
    struct Tipo tipo;

    tipo.inteiro = 42;
    tipo.pontoFlutuante = 3.14159;
    tipo.letra = 'A';

    printf("Inteiro: %d\n", tipo.inteiro);
    printf("Ponto Flutuante: %.2f\n", tipo.pontoFlutuante);
    printf("Letra: %c\n", tipo.letra);

    return 0;
}
