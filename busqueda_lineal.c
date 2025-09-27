// Escribe aquí la implementación de los ejercicios de búsqueda lineal.
// Ejercicio 1
#include <stdio.h>

// Busca secuencialmente el valor en el arreglo
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (arr[i] == x) 
            return i; // encontrado
    return -1; // no encontrado
}

int main() {
    int n, x;
    printf("Cantidad de elementos: ");
    scanf("%d", &n);

    int arr[n];
    printf("Ingresa los %d elementos: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Elemento a buscar: ");
    scanf("%d", &x);

    int pos = linearSearch(arr, n, x);
    if (pos != -1) printf("Elemento encontrado en posicion %d\n", pos);
    else printf("Elemento no encontrado\n");

    return 0;
}

// Ejercicio 2
#include <stdio.h>

// Asume que el arreglo está ORDENADO
int linearSearchImproved(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return i;  // encontrado
        if (arr[i] > x) return -1;  // ya no puede estar
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

    int pos = linearSearchImproved(arr, n, x);
    if (pos != -1) printf("Elemento encontrado en posicion %d\n", pos);
    else printf("Elemento no encontrado\n");

    return 0;
}

// Ejercicio 3
#include <stdio.h>

// Búsqueda recursiva
int linearSearchRecursive(int arr[], int n, int x, int index) {
    if (index >= n) return -1;   // caso base: no encontrado
    if (arr[index] == x) return index; // encontrado
    return linearSearchRecursive(arr, n, x, index + 1);
}

int main() {
    int n, x;
    printf("Cantidad de elementos: ");
    scanf("%d", &n);

    int arr[n];
    printf("Ingresa los %d elementos: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Elemento a buscar: ");
    scanf("%d", &x);

    int pos = linearSearchRecursive(arr, n, x, 0);
    if (pos != -1) printf("Elemento encontrado en posicion %d\n", pos);
    else printf("Elemento no encontrado\n");

    return 0;
}

// Ejercicio 4
#include <stdio.h>

// Búsqueda con centinela (agrega el valor buscado como "marca")
int linearSearchSentinel(int arr[], int n, int x) {
    int last = arr[n-1];
    arr[n-1] = x;  // colocamos el centinela
    int i = 0;
    while (arr[i] != x) i++;
    arr[n-1] = last; // restauramos el último valor
    if (i < n-1 || arr[n-1] == x) return i;
    return -1;
}

int main() {
    int n, x;
    printf("Cantidad de elementos: ");
    scanf("%d", &n);

    int arr[n];
    printf("Ingresa los %d elementos: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Elemento a buscar: ");
    scanf("%d", &x);

    int pos = linearSearchSentinel(arr, n, x);
    if (pos != -1) printf("Elemento encontrado en posicion %d\n", pos);
    else printf("Elemento no encontrado\n");

    return 0;
}
