#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//  Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                trocar(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Quick Sort
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

// j Merge Sort
void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

int main() {
    srand(time(NULL)); // números aleatórios

    int tamanhos[] = {1000, 5000, 10000}; // arrays

    for (int i = 0; i < sizeof(tamanhos) / sizeof(tamanhos[0]); i++) {
        int n = tamanhos[i];
        int arr_bubble[n], arr_quick[n], arr_merge[n];

        // números aleatórios
        for (int j = 0; j < n; j++) {
            arr_bubble[j] = rand() % 10000;
            arr_quick[j] = arr_bubble[j];
            arr_merge[j] = arr_bubble[j];
        }

        // Medir o tempo de execução do Bubble Sort
        clock_t start_bubble = clock();
        bubbleSort(arr_bubble, n);
        clock_t end_bubble = clock();
        double tempo_bubble = (double)(end_bubble - start_bubble) / CLOCKS_PER_SEC;

        // Medir o tempo de execução do Quick Sort
        clock_t start_quick = clock();
        quickSort(arr_quick, 0, n - 1);
        clock_t end_quick = clock();
        double tempo_quick = (double)(end_quick - start_quick) / CLOCKS_PER_SEC;

        // Medir o tempo de execução do Merge Sort
        clock_t start_merge = clock();
        mergeSort(arr_merge, 0, n - 1);
        clock_t end_merge = clock();
        double tempo_merge = (double)(end_merge - start_merge) / CLOCKS_PER_SEC;

        printf("Tamanho do array: %d\n", n);
        printf("Tempo Bubble Sort: %f segundos\n", tempo_bubble);
        printf("Tempo Quick Sort: %f segundos\n", tempo_quick);
        printf("Tempo Merge Sort: %f segundos\n", tempo_merge);
        printf("\n");
    }

    return 0;
}
