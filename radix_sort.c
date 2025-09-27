// Escribe aquí la implementación del ejercicio de Radix Sort.
#include <stdio.h>

// Función para encontrar el máximo en el arreglo
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Counting Sort para un dígito específico
void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    // Contamos las apariciones de cada dígito
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Ajustamos count[i] para que almacene la posición real
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Construimos el arreglo ordenado
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copiamos de regreso al arreglo original
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort principal
void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    // Ordenamos por cada dígito (unidades, decenas, centenas, ...)
    for (int exp = 1; m / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    int n;
    printf("Cantidad de elementos: ");
    scanf("%d", &n);

    int arr[n];
    printf("Ingresa los %d elementos: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    radixSort(arr, n);

    printf("Arreglo ordenado: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
