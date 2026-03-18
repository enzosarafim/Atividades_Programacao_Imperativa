#include <stdio.h>

int main() {
    char c;
    scanf("%c", &c);
    int n = c - 'A' + 1;

    for (int i = 1; i <= n; i++) {
        // Espaços esquerda
        for (int j = 0; j < n - i; j++)
            printf(".");

        // Letras subindo
        for (int j = 0; j < i; j++)
            printf("%c", 'A' + j);

        // Letras descendo
        for (int j = i - 2; j >= 0; j--)
            printf("%c", 'A' + j);

        // Espaços à direita
        for (int j = 0; j < n - i; j++)
            printf(".");

        printf("\n");
    }

    return 0;
}
