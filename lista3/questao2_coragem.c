#include <stdio.h>

int main() {
    int total_clientes, multiplo, clientes_sistema;
    scanf("%d %d %d", &total_clientes, &multiplo, &clientes_sistema);

    int latas_por_cliente[1001] = {0};
    int horario_termino[1001] = {0};

    if (multiplo != 0) {
        for (int i = 1; i <= total_clientes; i++) {
            if (i % multiplo == 0) {
                latas_por_cliente[i] = 1;
            }
        }
    }

    for (int i = 0; i < clientes_sistema; i++) {
        int quantidade_latas;
        char horario[6];

        scanf("%s %d", horario, &quantidade_latas);

        int hora   = (horario[0] - '0') * 10 + (horario[1] - '0');
        int minuto = (horario[3] - '0') * 10 + (horario[4] - '0');

        int minutos_desde_abertura = (hora * 60 + minuto) - (7 * 60);
        int numero_cliente = minutos_desde_abertura / 3;

        latas_por_cliente[numero_cliente] = quantidade_latas;
        horario_termino[numero_cliente]   = hora * 60 + minuto;
    }

    int total_latas_vendidas = 0;
    int cliente_vencedor     = -1;
    int latas_do_vencedor    = 0;
    int horario_do_vencedor  = 0;

    for (int i = 1; i <= total_clientes; i++) {
        if (latas_por_cliente[i] > 0) {
            total_latas_vendidas += latas_por_cliente[i];

            if (cliente_vencedor == -1 && total_latas_vendidas >= 50) {
                cliente_vencedor    = i;
                latas_do_vencedor   = latas_por_cliente[i];

                if (horario_termino[i] != 0)
                    horario_do_vencedor = horario_termino[i];
                else
                    horario_do_vencedor = 7 * 60 + i * 3;
            }
        }
    }

    if (cliente_vencedor == -1) {
        int latas_faltando = 50 - total_latas_vendidas;

        if (latas_faltando == 1)
            printf("Ainda nao foram vendidas latas suficientes. Falta %d lata.\n", latas_faltando);
        else
            printf("Ainda nao foram vendidas latas suficientes. Faltam %d latas.\n", latas_faltando);
    } else {
        int hora_atendimento   = horario_do_vencedor / 60;
        int minuto_atendimento = horario_do_vencedor % 60;

        if (latas_do_vencedor == 1)
            printf("Quem levou a cesta basica foi o %d* cliente atendido por coragem, as %02d:%02d. Que comprou %d lata.\n",
                   cliente_vencedor, hora_atendimento, minuto_atendimento, latas_do_vencedor);
        else
            printf("Quem levou a cesta basica foi o %d* cliente atendido por coragem, as %02d:%02d. Que comprou %d latas.\n",
                   cliente_vencedor, hora_atendimento, minuto_atendimento, latas_do_vencedor);
    }

    return 0;
}
