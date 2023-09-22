#include <stdio.h>
#include <math.h>

struct Ponto {
    double x;
    double y;
};

// Função para calcular a distância entre dois pontos
double calcularDistancia(struct Ponto p1, struct Ponto p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Função para calcular a inclinação da reta que conecta dois pontos
double calcularInclinacao(struct Ponto p1, struct Ponto p2) {
    if (p1.x == p2.x) {
        return INFINITY; // Vertical (inclinacao indefinida)
    }
    return (p2.y - p1.y) / (p2.x - p1.x);
}

int main() {
    struct Ponto ponto1, ponto2;

    printf("Digite as coordenadas do primeiro ponto (x y): ");
    scanf("%lf %lf", &ponto1.x, &ponto1.y);

    printf("Digite as coordenadas do segundo ponto (x y): ");
    scanf("%lf %lf", &ponto2.x, &ponto2.y);

    double distancia = calcularDistancia(ponto1, ponto2);
    double inclinacao = calcularInclinacao(ponto1, ponto2);

    printf("Distancia entre os pontos: %.2lf\n", distancia);
    printf("Inclinacao da reta que conecta os pontos: %.2lf\n", inclinacao);

    return 0;
}
