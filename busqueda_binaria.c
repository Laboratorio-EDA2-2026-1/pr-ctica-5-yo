// Escribe aqui la implementación de los ejercicios de búsqueda binaria.
// Ejercicio 1
#include <stdio.h>

// Búsqueda binaria recursiva
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main() {
    int n, x;
    printf("Cantidad de elementos: ");
    scanf("%d", &n);

    int arr[n];
    printf("Ingresa los %d elementos (ordenados): ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Elemento a buscar: ");
    scanf("%d", &x);

    int pos = binarySearch(arr, 0, n-1, x);
    if (pos != -1) printf("Elemento encontrado en posicion %d\n", pos);
    else printf("Elemento no encontrado\n");

    return 0;
}

// Ejercicio 2
#include <stdio.h>

// Genera la representación binaria de x en [0,1) usando k pasos
void binaryCode(double x, int k) {
    double left = 0.0, right = 1.0, mid;
    for (int i = 0; i < k; i++) {
        mid = (left + right) / 2.0;
        if (x >= mid) {
            printf("1");
            left = mid;
        } else {
            printf("0");
            right = mid;
        }
    }
    printf("\n");
}

int main() {
    double x;
    int k;

    printf("Ingresa un numero real (0 <= x < 1): ");
    scanf("%lf", &x);
    printf("Numero de pasos: ");
    scanf("%d", &k);

    printf("Codigo binario: ");
    binaryCode(x, k);

    return 0;
}
