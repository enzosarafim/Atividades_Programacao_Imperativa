#include <stdio.h>

int main() {
    // Inicializa a matriz 4x4 com zeros (representando os locais)
    int matriz[4][4] = {0}; 
    
    // Posição inicial no canto superior esquerdo (X = coluna, Y = linha)
    int x = 0, y = 0;
    char mov;

    // Laço para ler os 20 movimentos (conforme a descrição)
    for (int i = 0; i < 20; i++) {
        // O espaço antes do %c é importante para ignorar espaços em branco na entrada
        scanf(" %c", &mov); 
        
        // Atualiza a posição de acordo com a direção
        if (mov == 'c') {        // Cima
            y--;
        } else if (mov == 'b') { // Baixo
            y++;
        } else if (mov == 'e') { // Esquerda
            x--;
        } else if (mov == 'd') { // Direita
            x++;
        }

        // Adiciona +1 no local visitado, garantindo que não ultrapasse os limites da matriz 4x4
        if (x >= 0 && x < 4 && y >= 0 && y < 4) {
            matriz[y][x]++;
        }
    }

    // Variáveis para descobrir qual posição teve mais visitas
    int max_visitas = -1;
    int max_x = 0, max_y = 0;

    // Percorre a matriz inteira
    for (int i = 0; i < 4; i++) {       // i = Linhas (Eixo Y)
        for (int j = 0; j < 4; j++) {   // j = Colunas (Eixo X)
            if (matriz[i][j] > max_visitas) {
                max_visitas = matriz[i][j];
                max_y = i;  // Salva a linha do maior valor
                max_x = j;  // Salva a coluna do maior valor
            }
        }
    }


    printf("Coordenada X:%d, Y:%d\n", max_x, max_y);

    return 0;
}
