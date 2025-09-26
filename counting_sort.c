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
