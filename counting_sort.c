#include <stdio.h>
#include <string.h>

void countingSortString(char s[]) {
    int count[26] = {0}; // arreglo para contar letras (a-z)

    // contar cada letra
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
    }

    // reconstruir la cadena en orden
    int index = 0;
    for (int i = 0; i < 26; i++) {
        while (count[i] > 0) {
            s[index++] = i + 'a';
            count[i]--;
        }
    }
}

int main() {
    char s1[] = "edsab";
    char s2[] = "geeksforgeeks";

    countingSortString(s1);
    countingSortString(s2);

    printf("Resultado 1: %s\n", s1); // abdes
    printf("Resultado 2: %s\n", s2); // eeeefggkkorss

    return 0;
}// Escribe aquí la implementación de los ejercicios de Counting Sort.
#include <stdio.h>

void counting_sort(char a[], int n);

void counting_sort(char a[], int n){
	int max=; 

	int B[n];
	int C[max];

	for (int i = 0; i < max; ++i){
		C[i]=0;
	}
	for (int j = 0; j < n-1; ++j){
		C[a[j]]=C[a[j]]+1;
	}
	for (int k = 1; k < max; ++k){
		C[k]=C[k]+C[k-1];
	}
	for (int l = 0; l < n-1; --l){
		B[C[a[l]-1]]=a[l];
		C[a[l]]=C[a[l]]-1;
	}                                                                                                             
}

int main()
{
	int n; if (scanf("%d", &n) != 1 || n <= 0) return 0;
    char *a = (char*)malloc(sizeof(char) * n);
    if (!a) return 0;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    counting_sort(a, n)

    for (int i = 0; i < n; ++i) {
        if (i) putchar(' ');
        printf("%d", a[i]);
    } 
    putchar('\n');

    free(a);
    return 0;
}
