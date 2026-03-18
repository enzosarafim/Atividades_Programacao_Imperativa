#include <stdio.h>

int main() {
    char corredor[1000][1000];
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            corredor[i][j] = ' ';

    int q;
    scanf("%d", &q);

    int linha = 0, col = 0;
    int invalido = 0;
    char dir_anterior = ' ';

    for (int k = 0; k < q; k++) {
        int passos; char dir;
        scanf("%d %c", &passos, &dir);

        if (dir == 'D') {
            // Após B ou E, marca passos+1 pois col já está no último ponto
            int total = (dir_anterior == 'B' || dir_anterior == 'E') ? passos + 1 : passos;
            for (int i = 0; i < total; i++) {
                corredor[linha][col] = '.';
                col++;
            }

        } else if (dir == 'E') {
            if (col - passos < 0) { invalido = 1; break; }
            for (int i = 0; i <= passos; i++)
                corredor[linha][col - i] = '.';
            col -= passos;

        } else if (dir == 'B') {
            for (int i = 0; i < passos; i++) {
                linha++;
                corredor[linha][col - 1] = '.';
            }
            col--; // col fica no último ponto marcado

        }

        dir_anterior = dir;
    }

    if (invalido) { printf("Informacao invalida\n"); return 0; }

    int ultima_linha = 0;
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            if (corredor[i][j] == '.') ultima_linha = i;

    for (int i = 0; i <= ultima_linha; i++) {
        int ultima_col = 0;
        for (int j = 0; j < 1000; j++)
            if (corredor[i][j] == '.') ultima_col = j;
        for (int j = 0; j <= ultima_col; j++)
            printf("%c", corredor[i][j]);
        printf("\n");
    }

    return 0;
}
