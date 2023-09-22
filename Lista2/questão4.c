#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int matriz[][4] = {{12, 11, 13, 5},
                       {6, 7, 8, 9},
                       {4, 3, 2, 1}};

    int linhas = sizeof(matriz) / sizeof(matriz[0]);
    int colunas = sizeof(matriz[0]) / sizeof(matriz[0][0]);

    int tamanho = linhas * colunas;
    int arr[tamanho];
    int k = 0;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            arr[k++] = matriz[i][j];
        }
    }

    quickSort(arr, 0, tamanho - 1);

    k = 0;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = arr[k++];
        }
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
