#include <stdio.h>
#include <stdlib.h>

int main() {
    int  quantidade    = 0;
    int  capacidade    = 4;
    int  numero_lido;

    
    int *numeros = (int *)malloc(capacidade * sizeof(int));
    if (!numeros) {
        fprintf(stderr, "Erro ao alocar memória inicial\n");
        return 1;
    }

    
    while (scanf("%d", &numero_lido) == 1) {
        
        if (quantidade == capacidade) {
            capacidade *= 2;  

           
            int *temp = (int *)realloc(numeros, capacidade * sizeof(int));
            if (!temp) {
                fprintf(stderr, "Erro ao realocar memória\n");
                free(numeros);   
                return 1;
            }
            numeros = temp;
        }

        numeros[quantidade] = numero_lido;
        quantidade++;
    }

 
    printf("Mais um bom dia de trabalho!\n");
    
    for (int i = 0; i < quantidade; i++) {
        if (numeros[i] % 2 != 0) {
            printf("%d\n", numeros[i]);
        }
    }
    
    for (int i = 0; i < quantidade; i++) {
        if (numeros[i] % 2 == 0) {
            printf("%d\n", numeros[i]);
        }
    }

    printf("Vou visitar esses lugares de novo... algum dia.\n");

    
    free(numeros);

    return 0;
}
