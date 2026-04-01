#include <stdio.h>

int main() {
    // Matriz 4x4 que conta quantas vezes Pedro visitou cada posição
    // = {0} garante que todos os valores começam em zero
    int cidade[4][4] = {0};

    // Pedro sempre começa no canto superior esquerdo
    int linhaAtual = 0;
    int colunaAtual = 0;

    // Marca a posição inicial como visitada
    cidade[linhaAtual][colunaAtual]++;

    // Lê e processa cada um dos 20 movimentos
    char movimento;
    for (int passo = 0; passo < 20; passo++) {

        // O espaço antes de %c descarta enters e espaços entre os caracteres
        scanf(" %c", &movimento);

        // Move Pedro conforme o caractere lido
        // Sempre verifica se não vai sair dos limites da matriz (0 a 3)
        if (movimento == 'c' && linhaAtual > 0)
            linhaAtual--;         // cima = diminui linha
        else if (movimento == 'b' && linhaAtual < 3)
            linhaAtual++;         // baixo = aumenta linha
        else if (movimento == 'e' && colunaAtual > 0)
            colunaAtual--;        // esquerda = diminui coluna
        else if (movimento == 'd' && colunaAtual < 3)
            colunaAtual++;        // direita = aumenta coluna

        // Marca a nova posição como visitada
        cidade[linhaAtual][colunaAtual]++;
    }

    // Procura a posição mais visitada (onde Manuela estará esperando)
    int maiorValor   = cidade[0][0];
    int linhaDoMaior  = 0;
    int colunaDoMaior = 0;

    for (int linha = 0; linha < 4; linha++) {
        for (int coluna = 0; coluna < 4; coluna++) {
            if (cidade[linha][coluna] > maiorValor) {
                maiorValor    = cidade[linha][coluna];
                linhaDoMaior  = linha;
                colunaDoMaior = coluna;
            }
        }
    }

    // X = coluna, Y = linha (conforme o enunciado)
    printf("Coordenada X: %d, Y: %d ", colunaDoMaior, linhaDoMaior);

    return 0;
}
