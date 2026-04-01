#include <stdio.h>

int main() {
    int numLinhas, numColunas;
    scanf("%d %d", &numLinhas, &numColunas);

    char praca[100][101];

    for (int linha = 0; linha < numLinhas; linha++) {
        scanf("%s", praca[linha]);
    }

    // Deslocamentos para cima, baixo, esquerda, direita (colocam '+')
    int deslocamentoLinha4[] = {-1, 1, 0, 0};
    int deslocamentoColuna4[] = {0, 0, -1, 1};

    // Deslocamentos diagonais (colocam 'x')
    int deslocamentoLinhaDiagonal[] = {-1, -1, 1, 1};
    int deslocamentoColunaDiagonal[] = {-1, 1, -1, 1};

    for (int linha = 0; linha < numLinhas; linha++) {
        for (int coluna = 0; coluna < numColunas; coluna++) {
            if (praca[linha][coluna] == 'P') {

                // Marca '+' nas 4 direções adjacentes
                for (int direcao = 0; direcao < 4; direcao++) {
                    int linhaVizinha = linha + deslocamentoLinha4[direcao];
                    int colunaVizinha = coluna + deslocamentoColuna4[direcao];

                    int dentroDoLimite = linhaVizinha >= 0 && linhaVizinha < numLinhas
                                     && colunaVizinha >= 0 && colunaVizinha < numColunas;

                    if (dentroDoLimite && praca[linhaVizinha][colunaVizinha] != 'P') {
                        praca[linhaVizinha][colunaVizinha] = '+';
                    }
                }

                // Marca 'x' nas 4 posições diagonais (só se ainda for '-')
                for (int direcao = 0; direcao < 4; direcao++) {
                    int linhaVizinha = linha + deslocamentoLinhaDiagonal[direcao];
                    int colunaVizinha = coluna + deslocamentoColunaDiagonal[direcao];

                    int dentroDoLimite = linhaVizinha >= 0 && linhaVizinha < numLinhas
                                     && colunaVizinha >= 0 && colunaVizinha < numColunas;

                    if (dentroDoLimite && praca[linhaVizinha][colunaVizinha] == '-') {
                        praca[linhaVizinha][colunaVizinha] = 'x';
                    }
                }
            }
        }
    }

    for (int linha = 0; linha < numLinhas; linha++) {
        printf("%s\n", praca[linha]);
    }

    return 0;
}
