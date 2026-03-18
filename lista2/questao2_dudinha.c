#include <stdio.h>

int main() {
    int N, K, P;
    scanf("%d %d %d", &N, &K, &P);

    int primeiro_valido = -1;
    int Q = 0;

    for (int i = N; i < K; i++) {
        int n = i;
        int contar = 0;
        int valido = 1;

        // fatores de 2
        while (n % 2 == 0)
            n /= 2;

        //fatores primos ímpares
        for (int j = 3; j * j <= n; j += 2) {
            if (n % j == 0) {
                contar++;
                n /= j;
                if (n % j == 0) {
                    valido = 0;
                    break;
                }
            }
        }

        if (n > 1)
            contar++;

        if (valido && contar == P) {
            if (primeiro_valido == -1)
                primeiro_valido = i;
            else
                Q++;
        }
    }

    if (primeiro_valido == -1)
        printf("Poxa dudinha, me desculpa, nao achei os numeros mas vou te mandar uma foto de um gatinho fofo.\n");
    else
        printf("%d %d\n", primeiro_valido, Q);

    return 0;
}
