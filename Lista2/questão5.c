#include <stdio.h>

void ordenarLinhaPorInsercao(int arr[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int chave = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }
}

int main() {
    int matriz[][4] = {{12, 11, 13, 5},
                       {6, 7, 8, 9},
                       {4, 3, 2, 1}};

    int linhas = sizeof(matriz) / sizeof(matriz[0]);
    int colunas = sizeof(matriz[0]) / sizeof(matriz[0][0]);

    for (int i = 0; i < linhas; i++) {
        ordenarLinhaPorInsercao(matriz[i], colunas);
    }

    printf("Matriz bidimensional ordenada:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
