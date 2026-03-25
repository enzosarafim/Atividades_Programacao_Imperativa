#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int caso = 0; caso < T; caso++) {
        int N;
        scanf("%d", &N);

        int v[100];

        for (int i = 0; i < N; i++) {
            scanf("%d", &v[i]);
        }

        int inicio_atual = 0;
        int tamanho_atual = 1;

        int melhor_inicio = 0;
        int melhor_tamanho = 1;

        for (int i = 1; i < N; i++) {
            if (v[i] < v[i - 1]) {
                tamanho_atual++;
            } else {
                inicio_atual = i;
                tamanho_atual = 1;
            }

            if (tamanho_atual > melhor_tamanho) {
                melhor_tamanho = tamanho_atual;
                melhor_inicio = inicio_atual;
            }
        }

        if (melhor_tamanho < 2) {
            printf("0\n");
        } else {
            printf("%d\n", melhor_tamanho);

            for (int i = melhor_inicio; i < melhor_inicio + melhor_tamanho; i++) {
                printf("%d ", v[i]);
            }

            printf("\n");
        }
    }

    return 0;
}
