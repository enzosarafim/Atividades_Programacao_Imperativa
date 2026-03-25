#include <stdio.h>

int main() {
    int total_clientes, multiplo, clientes_sistema;
    scanf("%d %d %d", &total_clientes, &multiplo, &clientes_sistema);

    int latas_por_cliente[1001] = {0};
    int horario_por_cliente[1001] = {0};

    // L� o sistema primeiro
    for (int i = 0; i < clientes_sistema; i++) {
        char horario[6];
        int quantidade_latas;

        scanf("%s %d", horario, &quantidade_latas);

        int hora   = (horario[0] - '0') * 10 + (horario[1] - '0');
        int minuto = (horario[3] - '0') * 10 + (horario[4] - '0');

        // Hor�rio de t�rmino: 07:00 + cliente*3 -> cliente = (min - 420) / 3
        int total_minutos = hora * 60 + minuto;
        int numero_cliente = (total_minutos - 420) / 3;

        latas_por_cliente[numero_cliente]  = quantidade_latas;
        horario_por_cliente[numero_cliente] = total_minutos;
    }

    // D� 1 lata aos m�ltiplos de X que N�O est�o no sistema
    if (multiplo != 0) {
        for (int i = 1; i <= total_clientes; i++) {
            if (i % multiplo == 0 && latas_por_cliente[i] == 0) {
                latas_por_cliente[i] = 1;
                horario_por_cliente[i] = 420 + i * 3;
            }
        }
    }

    // Acumula latas e acha o vencedor
    int total_latas  = 0;
    int vencedor     = -1;
    int latas_ganhou = 0;
    int horario_ganhou = 0;

    for (int i = 1; i <= total_clientes; i++) {
        if (latas_por_cliente[i] > 0) {
            total_latas += latas_por_cliente[i];

            if (vencedor == -1 && total_latas >= 50) {
                vencedor     = i;
                latas_ganhou = latas_por_cliente[i];
                horario_ganhou = horario_por_cliente[i];
            }
        }
    }

    if (vencedor == -1) {
        int faltam = 50 - total_latas;
        if (faltam == 1)
            printf("Ainda nao foram vendidas latas suficientes. Falta %d lata.\n", faltam);
        else
            printf("Ainda nao foram vendidas latas suficientes. Faltam %d latas.\n", faltam);
    } else {
        int hora_saida   = horario_ganhou / 60;
        int minuto_saida = horario_ganhou % 60;

        if (latas_ganhou == 1)
            printf("Quem levou a cesta basica foi o %d* cliente atendido por coragem, as %02d:%02d. Que comprou %d lata.\n",
                   vencedor, hora_saida, minuto_saida, latas_ganhou);
        else
            printf("Quem levou a cesta basica foi o %d* cliente atendido por coragem, as %02d:%02d. Que comprou %d latas.\n",
                   vencedor, hora_saida, minuto_saida, latas_ganhou);
    }

    return 0;
}
