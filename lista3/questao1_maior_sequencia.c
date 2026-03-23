#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    
    //T-- = while(T > 0){... t--}
    while (T--) {
        int N;
        scanf("%d", &N);

        int seq[N];
        for (int i = 0; i < N; i++)
            scanf("%d", &seq[i]);

        // Variáveis para rastrear a melhor sequência encontrada
        int melhor_inicio = 0, melhor_tamanho = 1;
        // Variáveis para rastrear a sequência atual
        int atual_inicio = 0, atual_tamanho = 1;

        for (int i = 1; i < N; i++) {
            if (seq[i] < seq[i - 1]) {
                // Continua a sequência decrescente
                atual_tamanho++;
            } else {
                // Sequência quebrou, verifica se é a melhor até agora
                if (atual_tamanho > melhor_tamanho) {
                    melhor_tamanho = atual_tamanho;
                    melhor_inicio = atual_inicio;
                }
                // Reinicia sequência atual
                atual_inicio = i;
                atual_tamanho = 1;
            }
        }

        // Verifica a última sequência (se não cair no else anterior)
        if (atual_tamanho > melhor_tamanho) {
            melhor_tamanho = atual_tamanho;
            melhor_inicio = atual_inicio;
        }

        //resultado
        
        if (melhor_tamanho > 1) {
            printf("%d\n", melhor_tamanho);
            for (int i = melhor_inicio; i < melhor_inicio + melhor_tamanho; i++)
                printf("%d ", seq[i]);
            printf("\n");
        }else {
            printf("0");
        }
    }

    return 0;
}
