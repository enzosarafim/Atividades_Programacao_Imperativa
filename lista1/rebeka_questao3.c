#include <stdio.h>

int main() {
    int total, x, y, z;
    scanf("%d", &total);
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);

    // Verificar divisão com total original
    // A*100 == total*x ? (evitar float)
    int okOrig = ((total * x) % 100 == 0) && ((total * y) % 100 == 0) && ((total * z) % 100 == 0);

    int A, B, C, sobra, investido, totalFinal;

    // total original funciona
    // total+1 funciona E sobra > 1 (investiu 1 real)
    // total+2 funciona E sobra > 2
    // total+3 funciona E sobra > 3

    int ok1 = (((total+1)*x)%100==0) && (((total+1)*y)%100==0) && (((total+1)*z)%100==0);
    int sobra1 = (ok1) ? ((total+1) - (total+1)*x/100 - (total+1)*y/100 - (total+1)*z/100) : -1;

    int ok2 = (((total+2)*x)%100==0) && (((total+2)*y)%100==0) && (((total+2)*z)%100==0);
    int sobra2 = (ok2) ? ((total+2) - (total+2)*x/100 - (total+2)*y/100 - (total+2)*z/100) : -1;

    int ok3 = (((total+3)*x)%100==0) && (((total+3)*y)%100==0) && (((total+3)*z)%100==0);
    int sobra3 = (ok3) ? ((total+3) - (total+3)*x/100 - (total+3)*y/100 - (total+3)*z/100) : -1;

    // Determinar cenário
    // Prioridade: 0 investido, depois 1, 2, 3
    // Condição: sobra > investido
    int sobraOrig = (okOrig) ? (total - total*x/100 - total*y/100 - total*z/100) : -1;

    // Escolher o melhor cenário (menor investimento que funciona)
    int cenario; // 0=original ok, 1=+1, 2=+2, 3=+3, -1=impossivel
    cenario = (okOrig) ? 0 : ((ok1 && sobra1 > 1) ? 1 : ((ok2 && sobra2 > 2) ? 2 : ((ok3 && sobra3 > 3) ? 3 : -1)));

    // Porém se okOrig mas sobraOrig < 0... sobra nunca é negativa se porcentagens <= 100%
    // cenário 0 sempre válido se okOrig

    totalFinal = (cenario == 0) ? total : ((cenario == 1) ? total+1 : ((cenario == 2) ? total+2 : ((cenario == 3) ? total+3 : 0)));
    A = (cenario != -1) ? totalFinal*x/100 : 0;
    B = (cenario != -1) ? totalFinal*y/100 : 0;
    C = (cenario != -1) ? totalFinal*z/100 : 0;
    sobra = (cenario != -1) ? (totalFinal - A - B - C) : 0;
    investido = (cenario == -1) ? 0 : cenario;

    // Saída divisão
    if (cenario != -1)
        printf("Cada homem ficou com %d, %d e %d reais, respectivamente\n", A, B, C);
    else
        printf("Nao foi dessa vez que Rebeka pode ajudar...\n");

    // Dinheiro de Rebeka até agora
    // Se cenario 0: sobra
    // Se 1,2,3: sobra - investido 
    int dinheiro_rebeka = (cenario == 0) ? sobraOrig : ((cenario == -1) ? 0 : (sobra - investido));

    dinheiro_rebeka = (cenario == -1) ? 3 : (3 - investido + sobra);

    // Prova de contas
    if (cenario == 2) {
        char c1, c2, c3;
        scanf(" %c %c %c", &c1, &c2, &c3);
        int v1 = c1 - 'a' + 1;
        int v2 = c2 - 'a' + 1;
        int v3 = c3 - 'a' + 1;
        printf("%d\n", v1 + v2 + v3);
    }

    if (cenario == 3) {
        int i1, i2, i3;
        scanf("%d %d %d", &i1, &i2, &i3);
        // se pelo menos uma divisível por 3, retorna soma de parcelas do 3
        int temDiv = (i1%3==0) || (i2%3==0) || (i3%3==0);
        int parcelas = (temDiv) ? ((i1/3) + (i2/3) + (i3/3)) : 0;
        if (temDiv)
            printf("%d\n", parcelas);
    }

    // Resultado final
    if (dinheiro_rebeka >= 7)
        printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
    else
        printf("E parece que Rebeka vai ter que voltar andando...\n");

    return 0;
}
