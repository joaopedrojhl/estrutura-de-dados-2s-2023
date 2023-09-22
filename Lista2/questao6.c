#include <stdio.h>

void buscarValorNaMatriz(int matriz[][4], int linhas, int colunas, int valor, int *linhaEncontrada, int *colunaEncontrada) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] == valor) {
                *linhaEncontrada = i;
                *colunaEncontrada = j;
                return;
            }
        }
    }
    *linhaEncontrada = -1;
    *colunaEncontrada = -1;
}

int main() {
    int matriz[][4] = {{12, 11, 13, 5},
                       {6, 7, 8, 9},
                       {4, 3, 2, 1}};

    int linhas = sizeof(matriz) / sizeof(matriz[0]);
    int colunas = sizeof(matriz[0]) / sizeof(matriz[0][0]);

    int valorProcurado;
    printf("Digite o valor a ser procurado na matriz: ");
    scanf("%d", &valorProcurado);

    int linhaEncontrada, colunaEncontrada;
    buscarValorNaMatriz(matriz, linhas, colunas, valorProcurado, &linhaEncontrada, &colunaEncontrada);

    if (linhaEncontrada != -1 && colunaEncontrada != -1) {
        printf("O valor %d foi encontrado na linha %d e coluna %d da matriz.\n", valorProcurado, linhaEncontrada, colunaEncontrada);
    } else {
        printf("O valor %d nao foi encontrado na matriz.\n", valorProcurado);
    }

    return 0;
}
