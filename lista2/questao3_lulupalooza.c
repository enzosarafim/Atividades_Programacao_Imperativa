#include <stdio.h>

int main() {
    int X, N;
    scanf("%d", &X);
    scanf("%d", &N);

    int melhor_canal = -1;
    int melhor_minuto = -1;
    long long melhor_termo = -1;
    long long melhor_distancia = -1;

    for (int c = 1; c <= N; c++) {
        long long seq[100];
        scanf("%lld %lld", &seq[0], &seq[1]);

        //Gera a sequ�ncia do canal até um limite
        int tamanho = 2;
        while (tamanho < 90) {
            seq[tamanho] = seq[tamanho-1] + seq[tamanho-2];
            if (seq[tamanho] > 2e14) break;
            tamanho++;
        }

        // Melhor termo dentro deste canal
        long long canal_melhor_termo = -1;
        long long canal_melhor_distancia = -1;
        int canal_melhor_minuto = -1;

        // Acha o termo mais pr�ximo de X neste canal
        for (int i = 0; i < tamanho; i++) {
            long long distancia = seq[i] - X;
            if (distancia < 0) distancia = -distancia;

            // Em empate pega o menor termo
            if (canal_melhor_distancia == -1 || distancia < canal_melhor_distancia) {
                canal_melhor_distancia = distancia;
                canal_melhor_termo = seq[i];
                canal_melhor_minuto = i + 1;
            }
        }

        // Em empate entre canais, pega o de �ndice maior
        if (canal_melhor_distancia < melhor_distancia || melhor_distancia == -1) {
            melhor_distancia = canal_melhor_distancia;
            melhor_termo = canal_melhor_termo;
            melhor_minuto = canal_melhor_minuto;
            melhor_canal = c;
        } else if (canal_melhor_distancia == melhor_distancia) {
            melhor_canal = c;
            melhor_termo = canal_melhor_termo;
            melhor_minuto = canal_melhor_minuto;
        }
    }

    //soma os algarismos do melhor termo para verificar VIP
    long long temp = melhor_termo;
    if (temp < 0) temp = -temp;
    int soma = 0;
    while (temp > 0) {
        soma += temp % 10;
        temp /= 10;
    }

    if (soma > 10)
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d e com o VIP garantido!!!\n", melhor_canal, melhor_minuto);
    else
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d, mas o ingresso VIP n�o vai rolar :(\n", melhor_canal, melhor_minuto);

    return 0;
}
