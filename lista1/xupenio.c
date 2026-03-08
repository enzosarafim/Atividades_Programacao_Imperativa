#include <stdio.h>
//Foi utizada IA para auxiliar na lógica matemática
int main() {
    int N, A, B;
    int somaTotal, somaA, somaB, somaAB, resultado;
    int qtdA, qtdB, qtdAB;
    int mmc;
    scanf("%d", &N);
    scanf("%d %d", &A, &B);

    somaTotal = N * (N + 1) / 2;

    //quantidade de multiplos
    qtdA = N / A;
    qtdB = N / B;

    //soma dos multiplos
    somaA = A * qtdA * (qtdA + 1) / 2;
    somaB = B * qtdB * (qtdB + 1) / 2;

    //mmc para detectar os multiplos compartilhados por a e b, aproximado
    mmc = A * B;

    //quantidade dos multiplos compartilhados
    qtdAB = N / mmc;

    //soma dos compartilhados
    somaAB = mmc * qtdAB * (qtdAB + 1) / 2;

    //soma final
    resultado = somaTotal - somaA - somaB + somaAB;

    // checa se é par
    if (resultado % 2 == 0)
        printf("Lá ele!!!\n");
    else
        printf("%d\n", resultado);
        printf("Opa xupenio AULAS...\n");

    return 0;
}
