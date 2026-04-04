#include <stdio.h>
#include <stdlib.h>

int m, n;
char** parede;

// Função recursiva para simular o trajeto da água
void goteira(int x, int y) {
    // Verifica se saiu dos limites da matriz
    if (x < 0 || x >= n || y < 0 || y >= m) return;
    
    // Se essa posição já tem água ('o'), não precisamos recalcular
    if (parede[y][x] == 'o') return;

    // Marca a posição atual com a gota d'água
    parede[y][x] = 'o';

    // Se chegou na última linha (chão), a água não tem mais para onde cair
    if (y == m - 1) return;

    // Cenário 1: O espaço de baixo é vazio ('.') ou já tem água caindo ('o') -> continua caindo
    if (parede[y+1][x] == '.' || parede[y+1][x] == 'o') {
        goteira(x, y + 1);
    } 
    // Cenário 2: Bateu em uma prateleira ('#') -> espalha para os lados
    else if (parede[y+1][x] == '#') {
        
        // Espalhando para a esquerda
        int esq_x = x - 1;
        while (esq_x >= 0 && parede[y+1][esq_x] == '#') {
            parede[y][esq_x] = 'o'; // Molha em cima da prateleira
            esq_x--;
        }
        // Quando sair do while, 'esq_x' é a posição onde a prateleira acabou
        if (esq_x >= 0) {
            goteira(esq_x, y); // Chama a função na borda para a água cair
        }

        // Espalhando para a direita
        int dir_x = x + 1;
        while (dir_x < n && parede[y+1][dir_x] == '#') {
            parede[y][dir_x] = 'o'; // Molha em cima da prateleira
            dir_x++;
        }
        // Quando sair do while, 'dir_x' é a posição onde a prateleira acabou
        if (dir_x < n) {
            goteira(dir_x, y); // Chama a função na borda para a água cair
        }
    }
}

int main() {
    // Lê as dimensões m (linhas) e n (colunas)
    if (scanf("%d %d", &m, &n) != 2) return 0;

    // Alocação dinâmica da matriz (parede)
    parede = (char**)malloc(m * sizeof(char*));
    for (int i = 0; i < m; i++) {
        // Aloca n + 1 para caber o '\0' final de string
        parede[i] = (char*)malloc((n + 1) * sizeof(char)); 
        scanf("%s", parede[i]); // Lê cada linha da parede
    }

    // Localizar as coordenadas iniciais da goteira ('o')
    int inicio_x = -1, inicio_y = -1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (parede[i][j] == 'o') {
                inicio_x = j;
                inicio_y = i;
                parede[i][j] = '.'; // Limpamos temporariamente para a recursão não ignorar
                break;
            }
        }
        if (inicio_x != -1) break;
    }

    // Se encontrou uma goteira, inicia a simulação
    if (inicio_x != -1) {
        goteira(inicio_x, inicio_y);
    }

    // Imprimir o resultado final e liberar a memória
    for (int i = 0; i < m; i++) {
        printf("%s\n", parede[i]);
        free(parede[i]); 
    }
    free(parede);

    return 0;
}
