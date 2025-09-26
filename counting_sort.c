// Escribe aquí la implementación de los ejercicios de Counting Sort.
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
