// Escribe aquí la implementación de los ejercicios de Counting Sort.
// Ejercicio 1
#include <stdio.h>
#include <stdlib.h>

void counting_sort(char a[], int n){
	int max=26; //letras de a-z
	char B[n]; // arreglo auxiliar
	int C[max]; // arrglo de conteo
	// inicializar conteo
	for (int i = 0; i < max; ++i){
		C[i]=0;
	}
	// contar ocurrencias
	for (int j = 0; j < n; ++j){
		C[a[j]-'a']++;
	}
	// acumular
	for (int k = 1; k < max; ++k){
		C[k]=C[k]+C[k-1];
	}
	// acomodar de atras hacia adelante 
	for (int l = n-1; l >=0; --l){
		B[C[a[l]-'a']-1]=a[l];
		C[a[l]-'a']--;
	}     
	// copiar el resultado en a[]
	for (int i = 0; i < n; ++i){
		a[i]=B[i];                                                                                                                                     
	}
}

int main()
{
	int n; 
	printf("Ingresa el número de letras que deceas ingresar: ");
	if (scanf("%d", &n) != 1 || n <= 0) return 0;

    char *a = (char*)malloc(sizeof(char) * (n+1));
    if (!a) return 0;

    printf("Ingresa las letras sin espacios: ");
    for (int i = 0; i < n; ++i){
    	scanf(" %c", &a[i]);
    }

    counting_sort(a, n);

    printf("Letras ordenadas: ");
    for (int i = 0; i < n; ++i) {
        printf("%c", a[i]);
    } 
    putchar('\n');

    free(a);
    return 0;
}

// Ejercicio 2
#include <stdio.h>
#include <stdlib.h>

void sort_colors(int A[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (A[mid] == 0) { 
            // swap con low
            int temp = A[low];
            A[low] = A[mid];
            A[mid] = temp;
            low++;
            mid++;
        } else if (A[mid] == 1) { 
            mid++;
        } else { 
            // A[mid] == 2
            int temp = A[mid];
            A[mid] = A[high];
            A[high] = temp;
            high--;
        }
    }
}

int main() {
    int n;
    printf("Ingresa el número de elemetos: ");
    if (scanf(" %d", &n) != 1 || n <= 0) return 0;

    int *A = (int*)malloc(sizeof(int) * n);
    if (!A) return 0;

    printf("Ingresa los elemetos: \n");
    printf("0. Rojo\n");
    printf("1. Blanco\n");
    printf("2. Azul\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i]); // leer colores: 0,1,2
    }

    sort_colors(A, n);

    printf("Elementos ordemados: ");
    for (int i = 0; i < n; ++i) {
        if (i) putchar(' ');
        printf("%d", A[i]);
    }
    putchar('\n');

    free(A);
    return 0;
}
