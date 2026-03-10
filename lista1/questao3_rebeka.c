#include <stdio.h>
int main() {
    int total, x, y, z;
    scanf("%d %d %d %d", &total, &x, &y, &z);
//foi utilizada IA para correcao e identificação de erros de sintaxe
    int cenario = -1;
    int totalFinal = 0;
    for (int i = 0; i <= 3; i++) {
        int t = total + i;
        if ((t * x) % 100 == 0 && (t * y) % 100 == 0 && (t * z) % 100 == 0) {
            int sobra = t - (t*x/100) - (t*y/100) - (t*z/100);
            if (i == 0 || sobra > i) {
                cenario = i;
                totalFinal = t;
                break;
            }
        }
    }
    int A = 0, B = 0, C = 0, sobra = 0;
    if (cenario != -1) {
        A = totalFinal * x / 100;
        B = totalFinal * y / 100;
        C = totalFinal * z / 100;
        sobra = totalFinal - A - B - C;
        printf("Cada homem ficou com %d, %d e %d reais, respectivamente\n", A, B, C);
    } else {
        printf("Nao foi dessa vez que Rebeka pode ajudar...\n");
    }
    int dinheiro_rebeka = 3;
    if (cenario != -1) {
        dinheiro_rebeka = 3 - cenario + sobra;
    }
    if (cenario == 2) {
        char c1, c2, c3;
        scanf(" %c %c %c", &c1, &c2, &c3);
        int soma = (c1 - 'a' + 1) + (c2 - 'a' + 1) + (c3 - 'a' + 1);
        printf("%d\n", soma);
    }
    if (cenario == 3) {
        int i1, i2, i3;
        scanf("%d %d %d", &i1, &i2, &i3);
        if (i1 % 3 == 0 || i2 % 3 == 0 || i3 % 3 == 0) {
            int parcelas = 0;
            if (i1 % 3 == 0) parcelas += i1;
            if (i2 % 3 == 0) parcelas += i2;
            if (i3 % 3 == 0) parcelas += i3;
            parcelas = parcelas / 3;
            printf("%d\n", parcelas);
        }
    }
    if (dinheiro_rebeka >= 7) {
        printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
    } else {
        printf("E parece que Rebeka vai ter que voltar andando...\n");
    }
    return 0;
}
