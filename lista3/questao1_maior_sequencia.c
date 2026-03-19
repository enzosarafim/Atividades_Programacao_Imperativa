//código incompleto
#include <stdio.h>
#include <stdlib.h>

int main() {
    int casos_teste, tamanho_sequencia, num, num_passado;

    scanf("%d", & casos_teste);
    scanf("%d", &tamanho_sequencia);

    int sequencia[tamanho_sequencia];

    int sequencia_decrescente;

    for (size_t i = 0; i <= tamanho_sequencia; i++) {
        scanf("%d", &num);

        sequencia[i] = num;

        num_passado = num;

        if ()
    }
    for ( size_t i = 0; i <= tamanho_sequencia; i++) {
        printf("%d ", sequencia[i]);
    }
    return 0;
}
