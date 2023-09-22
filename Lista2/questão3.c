#include <stdio.h>

void ordenarPorInsercaoDecrescente(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = chave;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    ordenarPorInsercaoDecrescente(arr, n);

    printf("\nArray ordenado em ordem decrescente: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
