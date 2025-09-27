// Escribe aquí la implementación de los ejercicios de búsqueda lineal.
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
