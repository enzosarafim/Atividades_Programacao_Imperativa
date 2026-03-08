#include <stdio.h>

int main() {
    int total, x, y, z;
    scanf("%d %d %d %d", &total, &x, &y, &z);

    // Verificar se a divisão original resulta em inteiros
    int okOrig = 0;
    if ((total * x) % 100 == 0 && (total * y) % 100 == 0 && (total * z) % 100 == 0) {
        okOrig = 1;
    }

    int ok1 = 0;
    if (((total+1) * x) % 100 == 0 && ((total+1) * y) % 100 == 0 && ((total+1) * z) % 100 == 0) {
        ok1 = 1;
    }

    int ok2 = 0;
    if (((total+2) * x) % 100 == 0 && ((total+2) * y) % 100 == 0 && ((total+2) * z) % 100 == 0) {
        ok2 = 1;
    }

    int ok3 = 0;
    if (((total+3) * x) % 100 == 0 && ((total+3) * y) % 100 == 0 && ((total+3) * z) % 100 == 0) {
        ok3 = 1;
    }

    // Calcular sobras para cada caso
    int sobraOrig = 0;
    if (okOrig) {
        sobraOrig = total - (total * x / 100) - (total * y / 100) - (total * z / 100);
    }

    int sobra1 = 0;
    if (ok1) {
        sobra1 = (total+1) - ((total+1) * x / 100) - ((total+1) * y / 100) - ((total+1) * z / 100);
    }

    int sobra2 = 0;
    if (ok2) {
        sobra2 = (total+2) - ((total+2) * x / 100) - ((total+2) * y / 100) - ((total+2) * z / 100);
    }

    int sobra3 = 0;
    if (ok3) {
        sobra3 = (total+3) - ((total+3) * x / 100) - ((total+3) * y / 100) - ((total+3) * z / 100);
    }

    // Escolher o cenário (menor investimento que funciona)
    int cenario = -1;
    if (okOrig) {
        cenario = 0;
    } else if (ok1 && sobra1 > 1) {
        cenario = 1;
    } else if (ok2 && sobra2 > 2) {
        cenario = 2;
    } else if (ok3 && sobra3 > 3) {
        cenario = 3;
    }

    // Calcular valores finais com base no cenário
    int totalFinal = 0;
    if (cenario == 0) {
        totalFinal = total;
    } else if (cenario == 1) {
        totalFinal = total + 1;
    } else if (cenario == 2) {
        totalFinal = total + 2;
    } else if (cenario == 3) {
        totalFinal = total + 3;
    }

    int A = 0, B = 0, C = 0, sobra = 0;
    if (cenario != -1) {
        A = totalFinal * x / 100;
        B = totalFinal * y / 100;
        C = totalFinal * z / 100;
        sobra = totalFinal - A - B - C;
    }

    // Imprimir resultado da divisão
    if (cenario != -1) {
        printf("Cada homem ficou com %d, %d e %d reais, respectivamente\n", A, B, C);
    } else {
        printf("Nao foi dessa vez que Rebeka pode ajudar...\n");
    }

    // Calcular dinheiro de Rebeka
    int dinheiro_rebeka = 0;
    if (cenario == -1) {
        dinheiro_rebeka = 3;
    } else {
        dinheiro_rebeka = 3 - cenario + sobra;
    }

    // Prova com 2 reais (letras)
    if (cenario == 2) {
        char c1, c2, c3;
        scanf(" %c %c %c", &c1, &c2, &c3);
        int v1 = c1 - 'a' + 1;
        int v2 = c2 - 'a' + 1;
        int v3 = c3 - 'a' + 1;
        printf("%d\n", v1 + v2 + v3);
    }

    // Prova com 3 reais (idades)
    if (cenario == 3) {
        int i1, i2, i3;
        scanf("%d %d %d", &i1, &i2, &i3);

        int temDiv = 0;
        if (i1 % 3 == 0 || i2 % 3 == 0 || i3 % 3 == 0) {
            temDiv = 1;
        }

        if (temDiv) {
            int parcelas = (i1 / 3) + (i2 / 3) + (i3 / 3);
            printf("%d\n", parcelas);
        }
    }

    // Resultado final
    if (dinheiro_rebeka >= 7) {
        printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
    } else {
        printf("E parece que Rebeka vai ter que voltar andando...\n");
    }

    return 0;
}
